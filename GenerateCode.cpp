#include <unordered_map>
#include <string>
#include "MinHeapNode.h"

using namespace std;

void generateCodes(MinHeapNode* root, string code, unordered_map<char, string> &huffmanCodes) {
    if (!root)
        return;
    
    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}
