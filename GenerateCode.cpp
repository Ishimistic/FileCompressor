#include "GenerateCode.h"

using namespace std;

void generateCode(MinHeapNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
    }

    generateCode(root->left, code + "0", huffmanCodes);
    generateCode(root->right, code + "1", huffmanCodes);
}
