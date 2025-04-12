#ifndef COMPARE_H
#define COMPARE_H

#include "MinHeapNode.h"


class Compare {
public:
    bool operator()(MinHeapNode* left, MinHeapNode* right) {
        return left->freq > right->freq;
    }
};

#endif 
