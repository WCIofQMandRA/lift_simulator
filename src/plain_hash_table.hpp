//plain_hash_table.hpp: 简陋的散列表, 用于临时替代std::unordered_set<std::string>
//Author: 张子辰
//This file is part of the 电梯模拟器.
//电梯模拟器 is released into public domain,
//see README.md for detail.

#pragma once
#include <string>
class plain_hash_table
{
public:
    plain_hash_table();
    plain_hash_table(const plain_hash_table&)=delete;
    ~plain_hash_table();
    //三个方法均不处理空串（返回false）
    void erase(const std::string &value);
    bool count(const std::string &value);
    //insert不检查value是否已在this中
    void insert(const std::string &value);
private:
    struct node_t
    {
        std::string value;
        node_t *next;
    };
    size_t get_hash(const std::string &value);
    node_t *head[256];
    void del(node_t *p);
};
