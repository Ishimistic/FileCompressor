#include "BuildHuffmanTree.h"
#include <queue>
#include "Compare.h"

using namespace std;

MinHeapNode* buildHuffmanTree(unordered_map<char, int> &freqMap) {
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

    return minHeap.empty() ? nullptr : minHeap.top();
}

void destroyHuffmanTree(MinHeapNode* root) {
    if (root == nullptr) return;
    
    destroyHuffmanTree(root->left);
    destroyHuffmanTree(root->right);
    
    delete root;
}
