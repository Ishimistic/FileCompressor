#include <iostream>
#include <string>
#include "BuildHuffmanTree.h"
#include "GenerateCode.h"
#include "CompressFile.h"
#include "DecompressFile.h"

using namespace std;

int main() {
    cout << "Choose an option: \n";
    cout << "1. Compress a file\n";
    cout << "2. Decompress a file\n";

    int choice;
    cin >> choice;
    cin.ignore(); 

    string filePath;
    bool result = false;

    switch (choice) {
        case 1:
            cout << "Enter the path of the file to compress: ";
            getline(cin, filePath);
            result = compressFile(filePath);
            break;
        case 2:
            cout << "Enter the path of the file to decompress: ";
            getline(cin, filePath);
            result = decompressFile(filePath);
            break;
        default:
            cout << "Invalid option!" << endl;
            return 1;
    }

    return result ? 0 : 1;
}
