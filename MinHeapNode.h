#ifndef MINHEAPNODE_H
#define MINHEAPNODE_H

#include <iostream>

// Huffman Tree node
class MinHeapNode {
public:
    char data;         
    int freq;  
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq){
        this -> data = data;
        this -> freq = freq;
        this -> left = NULL;
        this -> right = NULL;
    };
};



#endif 
