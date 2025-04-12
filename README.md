
# FileCompressor

This project implements Huffman coding for file compression, allowing you to compress text files by encoding their content into a more space-efficient format. Huffman coding is a lossless compression algorithm, meaning that when you decompress the file, you get back the exact original content.


## Features

- Compresses text files into a .huff file.
- Uses a lossless algorithm for efficient storage.


## Deployment

To deploy this project run

1. Compile the code.
```bash
 g++ -o compress compress.cpp
```

2. Run the program
```bash
./compress
```

3. Enter the file path
```bash
Enter the path of the file to compress: /home/user/documents/example.txt
```

4. Output: The program will compress the file and generate a new .huff file. For example:
```bash
File compressed successfully to: /home/user/documents/example.txt.huff
```


**Error handling**

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
Adapt the algorithm to compress PDFs, audio, and video files for more versatile usage.