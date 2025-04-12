#include "CompressFile.h"
#include "MinHeapNode.h"
#include "BuildHuffmanTree.h"
#include "generateCode.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

bool compressFile(const string &inputFilePath) {
    ifstream inputFile(inputFilePath,  ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Could not open file: " << inputFilePath << endl;
        return false;
    }

    // Read entire file into buffer
    vector<char> buffer((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    if (buffer.empty()) {
         cerr << "File is empty: " << inputFilePath << endl;
         return false;
     }

    // Count byte frequencies
    unordered_map<unsigned char, int> freqMap;
    char ch;
    for (unsigned char byte : buffer) {
        freqMap[byte]++;
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
    unordered_map<unsigned char, string> huffmanCodes;
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

     // Save original file extension
     string extension = inputFilePath.substr(inputFilePath.find_last_of('.'));
     int extLength = extension.size();
     outputFile.write(reinterpret_cast<const char*>(&extLength), sizeof(extLength));
     outputFile.write(extension.c_str(), extLength);
 

    // Write frequency map
    int mapSize = freqMap.size();
    outputFile.write(reinterpret_cast<const char*>(&mapSize), sizeof(mapSize));

    for (const auto& pair : freqMap) {
        unsigned char byte = static_cast<unsigned char>(pair.first);
        outputFile.write(reinterpret_cast<const char*>(&byte), sizeof(byte));
        outputFile.write(reinterpret_cast<const char*>(&pair.second), sizeof(pair.second));
    }
    

    // Reset input file to beginning
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    // Encode the file
    string encodedString;
    for (unsigned char byte : buffer) {
        encodedString += huffmanCodes[byte];
    }

    // Pad the encoded string to ensure full bytes
    int padding = 8 - (encodedString.length() % 8);
    encodedString.append(padding, '0');

    // Write padding information
    outputFile.write(reinterpret_cast<const char*>(&padding), sizeof(padding));
    
    // Write binary data
    for (size_t i = 0; i < encodedString.length(); i += 8) {
        bitset<8> bits(encodedString.substr(i, 8));
        char byte = static_cast<char>(bits.to_ulong());
        outputFile.write(&byte, sizeof(byte));
    }

    cout << "File compressed successfully to: " << outputFilePath << endl;

    inputFile.close();
    outputFile.close();
    destroyHuffmanTree(root); 

    return true;
}
