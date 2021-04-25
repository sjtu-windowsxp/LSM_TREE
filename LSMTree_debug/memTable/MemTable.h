//
// Created by 魏新鹏 on 2021/4/22.
//

#ifndef LSM_LAB_MEMTABLE_H
#define LSM_LAB_MEMTABLE_H

#include "SkipList.h"

class MemTable {
private:
    SkipList skList;
    bool *bloomFilter;
    int capacity;
public:
    MemTable();
    ~MemTable();
    bool isFull(uint64_t, uint32_t);
    void addEntry(uint64_t, const std::string&);
    std::string* search(uint64_t);//return NULL is not exist
    void remove(uint64_t);
    Entry ** getWhole();

    bool * getBloom();
    uint64_t getMax();
    uint64_t getMin();
    uint32_t getSize();
    void reset();

};

#endif //LSM_LAB_MEMTABLE_H