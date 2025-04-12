#ifndef GENERATECODE_H
#define GENERATECODE_H

#include <unordered_map>
#include <string>
#include "MinHeapNode.h"

using namespace std;

void generateCode(MinHeapNode* root, string code, unordered_map<char, string>& huffmanCodes);

#endif
