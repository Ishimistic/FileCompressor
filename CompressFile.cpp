#include "CompressFile.h"
#include "MinHeapNode.h"
#include "BuildHuffmanTree.h"
#include "generateCode.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <bitset>

using namespace std;

bool compressFile(const string &inputFilePath) {
    ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        cerr << "Could not open file: " << inputFilePath << endl;
        return false;
    }

    // Count character frequencies
    unordered_map<char, int> freqMap;
    char ch;
    while (inputFile.get(ch)) {
        freqMap[ch]++;
    }

    if (freqMap.empty()) {
        cerr << "File is empty: " << inputFilePath << endl;
        return false;
    }

    // Build Huffman tree
    MinHeapNode* root = buildHuffmanTree(freqMap);
    if (!root) {
        cerr << "Failed to build Huffman tree" << endl;
        return false;
    }

    // Generate Huffman codes
    unordered_map<char, string> huffmanCodes;
    generateCode(root, "", huffmanCodes);

    // Prepare output file
    string outputFilePath = inputFilePath + ".huff";

    //Opening output file in binary mode
    ofstream outputFile(outputFilePath, ios::binary);
    if (!outputFile.is_open()) {
        cerr << "Could not create output file: " << outputFilePath << endl;
        destroyHuffmanTree(root);
        return false;
    }

    // Write frequency map size to the compressed file
    int mapSize = freqMap.size();
    outputFile.write(reinterpret_cast<const char*>(&mapSize), sizeof(mapSize));
    
    // Write frequency map entries
    for (const auto& pair : freqMap) {
        outputFile.write(&pair.first, sizeof(pair.first));
        outputFile.write(reinterpret_cast<const char*>(&pair.second), sizeof(pair.second));
    }



    // Reset input file to beginning
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    // Encode the file
    string encodedString;
    while (inputFile.get(ch)) {
        encodedString += huffmanCodes[ch];
    }

    // Pad the encoded string to ensure full bytes
    int padding = 8 - (encodedString.length() % 8);

    // Write padding information
    outputFile.write(reinterpret_cast<const char*>(&padding), sizeof(padding));
    
    encodedString += string(padding, '0');

    // Write binary data
    for (size_t i = 0; i < encodedString.length(); i += 8) {
        bitset<8> bits(encodedString.substr(i, 8));
        char byte = static_cast<char>(bits.to_ulong());
        outputFile.write(&byte, 1);
    }

    cout << "File compressed successfully to: " << outputFilePath << endl;

    inputFile.close();
    outputFile.close();
    destroyHuffmanTree(root); 

    return true;
}
