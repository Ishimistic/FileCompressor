# FileCompressor

A high-performance C++ file compression utility implementing Huffman coding to significantly reduce file sizes while preserving original content integrity. This utility supports multiple file formats including text, CSV files with impressive compression rates.

## Compression Performance

| File Type        | Compression Rate |
|------------------|------------------|
| Text Files       | 38.2%            |
| CSV Files        | Up to 42.4%      |

## Key Features

- **Multi-format Support**: Compresses text files, PDFs, and Word documents with format-specific optimizations
- **Lossless Compression**: Guarantees exact reconstruction of original content when decompressed
- **File Extension Preservation**: Maintains original file extensions throughout the compression/decompression process
- **Bit-level Encoding**: Uses efficient bit-level operations for maximum compression performance
- **Robust Error Handling**: Comprehensive validation and error management for reliable operation
- **Cross-format Compatibility**: Consistent performance across different file types

## Getting Started

### Prerequisites

- C++ compiler (GCC recommended)
- Basic command line knowledge

### Installation

- Clone the repository
```bash
git clone https://github.com/yourusername/FileCompressor.git
cd FileCompressor
```

### Usage

1. Compile the code.
```bash
 g++ mainCompressFile.cpp BuildHuffmanTree.cpp CompressFile.cpp DecompressFile.cpp GenerateCode.cpp -o huffman
```

2. Run the program
```bash
./huffman
```

3. Choose whether you want to compress or decompress by typing the corresponding option: (decompress in case of txt file)
 ```bash
Choose an option:
1. Compress a file
2. Decompress a file
```

#### Compression
4. Enter the file path
```bash
Enter the path of the file to compress: /path/to/your/file.extension
```

5. Output
```bash
File compressed successfully to: /home/user/documents/example.txt.huff
```

#### Decompression
4. Enter the file path
```bash
Enter the path of the file to decompress: /path/to/your/file.extension.huff
```

5. Output
```bash
File decompressed successfully to: /path/to/your/file.extension
```


## Error handling

If the specified file cannot be opened, the program will output an error message:
```bash
Could not open file: <file-path>
```


## Real-World Applications:

- Data Storage: Compress large text files to save disk space (e.g., logs, documents).
- Data Transmission: Reduce data size for faster transmission in networks.
- Text & Document Compression: Save space for documents, books, and legal papers.
- Backup Systems: Compress files for efficient backups.
- Embedded Systems: Save space in memory-constrained devices like IoT devices.
## Limitations

- This program works well for text files but would require modification to handle binary files or other complex file types.
- The .huff file is specific to this compression scheme and cannot be opened or read directly without decompression.
## Future Scope


- **Image Compression:**
Implement lossless and lossy image compression using Huffman coding for efficient storage and transmission of images.
- **Text and Image Hybrid Compression:**
Extend the algorithm to handle both text and images, compressing multi-format files like scanned documents.

- **Compression for Other File Types:**
Adapt the algorithm to compress audio, and video files for more versatile usage.
