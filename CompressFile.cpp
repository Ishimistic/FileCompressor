#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include "MinHeapNode.h"
#include "BuildHuffmanTree.cpp" 
#include "GenerateCode.cpp"

using namespace std;

void compressFile(const string &inputFilePath) {
    ifstream inputFile(inputFilePath);

    if (!inputFile.is_open()) {
        cerr << "Could not open file: " << inputFilePath << endl;
        return;
    }

    unordered_map<char, int> freqMap;
    char ch;

    while (inputFile.get(ch)) {
        freqMap[ch]++;
    }

    MinHeapNode *root = buildHuffmanTree(freqMap);
    
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    //Reseting file pointer
    inputFile.clear();
    inputFile.seekg(0, ios::beg);


    // Compressing file contents into a .huff file
    string outputFilePath = inputFilePath + ".huff";
    ofstream outputFile(outputFilePath, ios::binary);


    string encodedString;
    while (inputFile.get(ch)) {
        encodedString += huffmanCodes[ch];
    }

    outputFile << encodedString;

    cout << "File compressed successfully to: " << outputFilePath << endl;

    inputFile.close();
    outputFile.close();
}
