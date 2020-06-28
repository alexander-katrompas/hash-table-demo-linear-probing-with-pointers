/*
 * This is a simple Hash Table using linear probing.
 */

/* 
 * File:   main.cpp
 * Author: Alex Katrompas
 */

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include "data.h"

#define HASHTABLESIZE 15

using std::cout;
using std::endl;

class Hashtable {

public:
    Hashtable();
    ~Hashtable();
    
    bool insertEntry(int, string);
    string getData(int);
    bool deleteEntry(int id);
    int getCount();
    void printTable();

    private:

    int hash(int);
    
    Data *hashtable[HASHTABLESIZE];
    int count;
};

#endif /* HASHTABLE_HASHTABLE_H */

