#include <iostream>
#include <string>
#include "compressFile.cpp" 

using namespace std;

int main() {
    string inputFilePath;
    cout << "Enter the path of the file to compress: ";
    getline(cin, inputFilePath);

    compressFile(inputFilePath);

    return 0;
}
