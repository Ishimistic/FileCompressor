#ifndef BUILDHUFFMANTREE_H
#define BUILDHUFFMANTREE_H

#include "MinHeapNode.h"
#include <unordered_map>

using namespace std;

MinHeapNode* buildHuffmanTree(unordered_map<unsigned char, int>& freqMap);


// To clean up the tree memory
void destroyHuffmanTree(MinHeapNode* root);

#endif 
