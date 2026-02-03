Huffman Coding Implementation in C++
A complete implementation of the Huffman coding algorithm in C++ for lossless data compression. This program constructs an optimal binary tree based on input character frequencies/probabilities and generates corresponding variable-length binary codes.
Features

Complete Huffman Tree Construction: Builds the optimal binary tree using a greedy algorithm approach
Frequency-based Encoding: Creates shorter codes for more frequent characters and longer codes for less frequent ones
Accurate Statistics: Calculates both the average code length (n) and information entropy (H) of the source
Robust Handling: Properly handles cases with identical probability values using unique indexing
Clean Implementation: Well-structured code with clear separation of concerns

How It Works
The program takes as input the number of characters and their respective probabilities, then:

Constructs a priority queue (min-heap) of nodes
Repeatedly combines the two nodes with lowest probabilities until one tree remains
Traverses the final tree to generate binary codes (left branch = 0, right branch = 1)
Calculates and displays the average code length and entropy

Example Usage
Input format:
8
0.25
0.2
0.15
0.15
0.12
0.05
0.04
0.04

Output includes each character's probability with its corresponding Huffman code, plus calculated statistics.
Mathematical Background

Information Entropy H(X): The theoretical minimum average number of bits needed to encode symbols
Average Code Length n: The actual average length achieved by the Huffman encoding
Efficiency: The ratio H(X)/n, which should be close to 1 for optimal encoding

Perfect for educational purposes, data compression applications, or understanding fundamental concepts in information theory and algorithms.
