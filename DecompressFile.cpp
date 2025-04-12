#include "DecompressFile.h"
#include "MinHeapNode.h"
#include "BuildHuffmanTree.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <cerrno>
#include <cstring>
#include <bitset>

using namespace std;

bool decompressFile(const string& inputFilePath) {
    // cout << "Attempting to open file: " << inputFilePath << endl;
    ifstream inputFile(inputFilePath, ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Error code: " << strerror(errno) << endl; 
        cerr << "Could not open file: " << inputFilePath << endl;
        return false;
    }

    // Read frequency map size
    int mapSize;
    if (!inputFile.read(reinterpret_cast<char*>(&mapSize), sizeof(mapSize))) {
        cerr << "Error reading frequency map size" << endl;
        return false;
    }

    unordered_map<char, int> freqMap;
    for (int i = 0; i < mapSize; ++i) {
        char ch;
        int freq;
        
        if (!inputFile.read(&ch, sizeof(ch)) || 
           !inputFile.read(reinterpret_cast<char*>(&freq), sizeof(freq))) {
           cerr << "Error reading frequency map entry" << endl;
           return false;
        }

        freqMap[ch] = freq;
    }

    // Rebuild Huffman tree
    MinHeapNode* root = buildHuffmanTree(freqMap);
    if (!root) {
        cerr << "Failed to rebuild Huffman tree" << endl;
        return false;
    }


    // Read padding information
    int padding;
    if (!inputFile.read(reinterpret_cast<char*>(&padding), sizeof(padding))) {
        cerr << "Error reading padding information" << endl;
        destroyHuffmanTree(root);
        return false;
    }

    // Read and convert binary data
    string encodedString;
    char byte;
    while (inputFile.read(&byte, sizeof(byte))) {
        // bitset<8> bits(byte);
        bitset<8> bits(static_cast<unsigned char>(byte));
        encodedString += bits.to_string();
    }

   // Check for valid encoded data
    if (encodedString.empty()) {
        cerr << "No encoded data found" << endl;
        destroyHuffmanTree(root);
        return false;
    }

    // Remove padding
    if (padding > 0 && padding < 8) {
        encodedString = encodedString.substr(0, encodedString.length() - padding);
    }

    // Decode the string
    string decodedString;
    MinHeapNode* currentNode = root;

    for (char bit : encodedString) {
        if (bit != '0' && bit != '1') {
            cerr << "Invalid bit in encoded string" << endl;
            destroyHuffmanTree(root);
            return false;
        }

        currentNode = (bit == '0') ? currentNode->left : currentNode->right;

        if (currentNode && !currentNode->left && !currentNode->right) {
            decodedString += currentNode->data;
            currentNode = root;
        }
    }

    // Write decompressed data
    string outputFilePath;
    size_t huffExtPos = inputFilePath.rfind(".huff");
    if (huffExtPos != string::npos) {
        // Remove .huff extension
        outputFilePath = inputFilePath.substr(0, huffExtPos);
        // Add .dec extension
        outputFilePath += ".dec";
    } else {
        outputFilePath = inputFilePath + ".dec";
    }
    
    
    ofstream outputFile(outputFilePath, ios::binary);
    if (!outputFile.is_open()) {
        cerr << "Could not create output file: " << outputFilePath << endl;
        destroyHuffmanTree(root);
        return false;
    }
    
    outputFile.write(decodedString.c_str(), decodedString.length());

    cout << "File decompressed successfully to: " << outputFilePath << endl;

    inputFile.close();
    outputFile.close();
    destroyHuffmanTree(root);
    
    return true;
}