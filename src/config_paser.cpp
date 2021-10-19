//config_paser.cpp: 配置文件分析器
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#include "config_paser.hpp"

namespace zzc
{
void ini_parser::load(std::istream &is)
{
    //TODO
    std::string key,value,section_name;
    int ch;
    size_t line=0;
    while(is)
    {
        ++line;
        ch=is.get();
        while(is&&0<=ch&&ch<=' ')ch=is.get();//忽略行首空格
        if(!is)break;
        //注释
        if(ch==';')
        {
            while(is&&ch!='\n')ch=is.get();
            continue;
        }
        //读取节名
        else if(ch=='[')
        {
            section_name.clear();
            ch=is.get();
            while(is&&ch!=']')
            {
                section_name+=char(ch);
                ch=is.get();
            }
            if(!is)
                throw std::runtime_error("zzc::ini_parser::load(): Stream ends while searching for `]'.");
            ch=is.get();
            while(ch!='\n')ch=is.get();//忽略节名后的任何字符
            continue;
        }
        key.clear();
        //key可以包含除“=”外的任何字符，其key不可以以ASCII控制符或空格开头
        while(is&&ch!='='&&ch!='\n')
        {
            key+=char(ch);
            ch=is.get();
        }
        if(!key.size())
            throw std::runtime_error("zzc::ini_parser::load(): Key should not be empty. On line "+std::to_string(line)+'.');
        //忽略key结尾的空格
        {
            size_t k_end;
            for(k_end=key.size()-1;0<=key[k_end]&&key[k_end]<=' ';--k_end);
            key=key.substr(0,k_end+1);
        }
        //无法找到key
        if(!is||ch=='\n')
            throw std::runtime_error("zzc::ini_parser::load(): Cannot find `=' on line "+std::to_string(line)+".");
        ch=is.get();
        value.clear();
        if(ch=='"'||ch=='\'')
        {
            int break_char=ch;
            ch=is.get();
            while(is&&ch!=break_char)
            {
                if(ch=='\\')
                {
                    ch=is.get();
                    switch(ch)
                    {
                    case '"':value+='"';break;
                    case '\'':value+='\'';break;
                    case 'n':value+='\n';break;
                    case '\\':value+='\\';break;
                    case 't':value+='\t';break;
                    default:if(ch=='\n')++line;(value+='\\')+=char(ch);
                    }
                }
                else 
                {
                    if(ch=='\n')++line;
                    value+=char(ch);
                }
                ch=is.get();
            }
            if(!is)
                throw std::runtime_error("zzc::ini_parser::load(): Stream ends while search for quoter.");
            while(is&&ch!='\n')ch=is.get();
        }
        else
        {
            while(is&&ch!='\n'&&ch!=';')
            {
                value+=char(ch);
                ch=is.get();
            }
            //忽略value开头和结尾的空格
            if(value.size())
            {
                size_t v_start,v_end;
                for(v_start=0;v_start<value.size()&&0<=value[v_start]&&value[v_start]<=' ';++v_start);
                for(v_end=value.size()-1;v_end>=v_start&&0<=value[v_end]&&value[v_end]<=' ';--v_end);
                value=value.substr(v_start,v_end-v_start+1);
            }
            if(ch==';')
            {
                while(is&&ch!='\n')ch=is.get();
            }
        }
        auto &option=m_options.at(key);
        option.second->parse(option.first,value);
    }
}
}
