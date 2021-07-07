# Huffman-coding
This project was made during data structures course - Huffman Coding Algorithm

![image](https://user-images.githubusercontent.com/72739568/124788275-e0b16800-df51-11eb-8dc9-b5cdde1da6db.png)
## User Manual
1. Insert the name of a text file (include ".txt").
2. The program will calculate and print a Huffman Code and its weight.
3. In case of any error - the program will notify and exit.

### Huffman coding is done with the help of the following steps:

- Calculate the frequency of each character in the file.
- Sort the characters in increasing order of the frequency. These are stored in a priority queue.
- Make each unique character as a leaf node.
- Create an empty node z. Assign the minimum frequency to the left child of z and assign the second minimum frequency to the right child of z. Set the value of the z as the sum of the two minimum frequencies.
- Remove these two minimum frequencies from the queue and add the sum into the list of frequencies.
- Insert node z into the tree.
- Repeat steps 4 to 6 for all the characters.
- For each non-leaf node, assign 0 to the left edge and 1 to the right edge.

## Time Complexity
 
##### The time complexity analysis of Huffman Coding is as follows:

extractMin( ) is called 2 x (n-1) times if there are n nodes.
As extractMin( ) calls minHeapify( ), it takes O(logn) time.
 

Thus, Overall time complexity of Huffman Coding becomes O(nlogn).

Here, n is the number of unique characters in the given text.
