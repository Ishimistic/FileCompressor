#include <iostream>
#include <queue>
#include <unordered_map>
#include "MinHeapNode.h"

using namespace std;

class Compare {
public:
    bool operator()(MinHeapNode* left, MinHeapNode* right) {
        return left->freq > right->freq;
    }
};

MinHeapNode* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, Compare> minHeap;

    for (const auto& pair : freqMap) {
        minHeap.push(new MinHeapNode(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        MinHeapNode *left = minHeap.top(); 
        minHeap.pop();
        MinHeapNode *right = minHeap.top(); 
        minHeap.pop();

        MinHeapNode *newNode = new MinHeapNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top();
}
