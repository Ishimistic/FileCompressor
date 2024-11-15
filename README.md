**File Compression**
This project implements Huffman coding for file compression, allowing you to compress text files by encoding their content into a more space-efficient format. 
Huffman coding is a lossless compression algorithm, meaning that when you decompress the file, you get back the exact original content.

**Features:**
Compresses text files by replacing frequently occurring characters with shorter binary codes.
Generates a Huffman tree based on the frequency of characters in the input file.
Outputs a compressed .huff file containing the encoded content of the original file.

**Requirements:**
C++ compiler (e.g., GCC or Clang)
Standard C++ library

**How It Works:**
i) Frequency Map Construction: The program first reads the input file and calculates the frequency of each character.
ii) Huffman Tree Construction: It then constructs a Huffman tree based on the frequencies of the characters. This tree is used to generate a binary code for each character, with more frequent characters assigned shorter codes.
iii)File Compression: The program compresses the file by replacing characters with their corresponding Huffman codes, creating a binary string.
iv) Saving the Compressed Data: The encoded string is saved to a .huff file.

**Usage:**
1. Clone the repository (or download the source files).
![Uploading image.png…]()

git clone <repository-url>
2. Compile the code.
For example, if using g++, you can compile the code like this:

bash
Copy code
g++ -o compress compress.cpp
3. Run the program.
After compiling, run the executable:

bash
Copy code
./compress
4. Input the file path.
The program will prompt you to enter the path of the text file you wish to compress. For example:

css
Copy code
Enter the path of the file to compress: example.txt
Make sure that the file exists and is accessible. The program will not work if the file path is incorrect or if the file is not found.

5. Output the compressed file.
The program will generate a .huff file containing the compressed data. For example:

arduino
Copy code
File compressed successfully to: example.txt.huff

Real-World Applications:
Data Storage: Compress large text files to save disk space (e.g., logs, documents).
Data Transmission: Reduce data size for faster transmission in networks.
Text & Document Compression: Save space for documents, books, and legal papers.
Backup Systems: Compress files for efficient backups.
Embedded Systems: Save space in memory-constrained devices like IoT devices
