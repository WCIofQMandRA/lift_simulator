//config_paser.hpp: 配置文件分析器
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.
#pragma once
#include <any>
#include <string>
#include <memory>
#include <stdexcept>
#include <sstream>
#include "vector.hpp"
#include "splay_tree.hpp"

namespace zzc
{
namespace converters
{
//将字符串转换为特定的运行时确定的类型的转换器
class converter_base
{
public:
    virtual void parse(std::any &,const std::string&)=0;
    virtual ~converter_base()=default;
};
template<typename T>
class converter:public converter_base
{
public:
    virtual void parse(std::any &v,const std::string &s)override
    {
        std::istringstream sin(s);
        T tmp;
        sin>>tmp;
        v=std::make_any<T>(tmp);
    }
};
template<typename T1,typename T2>
class converter<std::pair<T1,T2>>:public converter_base
{
public:
    virtual void parse(std::any &v,const std::string &s)override
    {
        std::istringstream sin(s);
        std::pair<T1,T2> tmp;
        sin>>tmp.first>>tmp.second;
        v=std::make_any<std::pair<T1,T2>>(tmp);
    }
};
template<typename T>
class converter<zzc::vector<T>>:public converter_base
{
public:
    virtual void parse(std::any &v,const std::string &s)override
    {
        std::istringstream sin(s);
        zzc::vector<T> vec;
        T tmp;
        while(sin>>tmp)vec.push_back(tmp);
        v=std::make_any<zzc::vector<T>>(vec);
    }
};
}

class ini_parser
{
public:
    
public:
    //添加INI文件的键名，即等号左侧的字符串
    template<typename T>
    void add_key(const std::string &key)
    {
        for(auto i:key)
            if(i=='=')throw std::runtime_error("zzc::ini_parser::add_key: The key cannot contain `='.");
        if(m_options.count(key))
            throw std::runtime_error("zzc::ini_parser::add_key: The has already existed. key="+key);
        m_options.insert(std::make_pair(key,std::make_pair(std::any(),std::make_unique<converters::converter<T>>())));
    }

    //指定转换器
    template<typename T>
    void add_key(const std::string &key,std::unique_ptr<converters::converter_base> &&converter)
    {
        for(auto i:key)
            if(i=='=')throw std::runtime_error("zzc::ini_parser::add_key: The key cannot contain `='.");
        if(m_options.count(key))
            throw std::runtime_error("zzc::ini_parser::add_key: The has already existed. key="+key);
        m_options.insert(std::make_pair(key,std::make_pair(std::any(),std::move(converter))));
    }

    //从INI文件读取配置
    void load(std::istream &is);

    //读取INI文件的键，T必须与add_key时的T完全相同
    template<typename T>
    void get_key(T &value,const std::string &key)
    {
        value=std::any_cast<T>(m_options.at(key).first);
    }
private:
    zzc::splay_tree<std::string,std::pair<std::any,std::unique_ptr<converters::converter_base>>> m_options;
};
}
