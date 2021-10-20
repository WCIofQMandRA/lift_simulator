//plain_hash_table.cpp: 简陋的散列表
//Copyright (C) 2021-2022 张子辰
//This file is part of the 电梯模拟器.

#include "plain_hash_table.hpp"
#include <cstring>

plain_hash_table::plain_hash_table()
{
    for(size_t i=0;i<256;++i)
    {
        head[i]=new node_t{"",nullptr};
    }
}

plain_hash_table::~plain_hash_table()
{
    for(size_t i=0;i<256;++i)
        del(head[i]);
}

void plain_hash_table::del(node_t *p)
{
    if(p->next)del(p->next);
    delete p;
}

void plain_hash_table::erase(const std::string &value)
{
    if(value.empty())return;
    for(auto p=head[get_hash(value)];p->next;p=p->next)
    {
        if(p->next->value==value)
        {
            auto tmp=p->next;
            p->next=p->next->next;
            delete tmp;
            break;
        }
    }
}

void plain_hash_table::insert(const std::string &value)
{
    if(value.empty())return;
    auto p=head[get_hash(value)];
    p->next=new node_t{value,p->next};
}

bool plain_hash_table::count(const std::string &value)
{
    if(value.empty())return false;
    for(auto p=head[get_hash(value)]->next;p;p=p->next)
    {
        if(p->value==value)return true;
    }
    return false;
}

size_t plain_hash_table::get_hash(const std::string &value)
{
    size_t h=0;
    for(auto i:value)
        h=h*19260817+i;
    return h%256;
}
