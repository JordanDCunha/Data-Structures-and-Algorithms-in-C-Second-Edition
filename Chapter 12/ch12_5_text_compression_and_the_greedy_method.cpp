/**
 * CHAPTER 12.5: TEXT COMPRESSION AND THE GREEDY METHOD
 * --- THE CONCEPT ---
 * Text compression reduces the size of a string by encoding it into binary.
 * Huffman Coding is an optimal prefix-free variable-length encoding.
 * - Frequent characters -> Short codes
 * - Rare characters -> Long codes
 * This follows the "Greedy Method": making locally optimal choices 
 * (merging the two smallest frequencies) to reach a global optimum.
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

// =============================================================================
// 12.5.1: HUFFMAN TREE STRUCTURE
// =============================================================================

struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    
    // Internal node constructor
    HuffmanNode(int f, HuffmanNode* l, HuffmanNode* r) 
        : ch('\0'), freq(f), left(l), right(r) {}
};

// Comparison object for the Priority Queue (Min-Heap)
struct CompareNodes {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq;
    }
};

// =============================================================================
// 12.5.2: THE HUFFMAN ALGORITHM
// =============================================================================

/**
 * huffman: Builds the optimal prefix code tree.
 * Time Complexity: O(n + d log d), where n is string length and d is unique chars.
 */
HuffmanNode* buildHuffmanTree(const string& X) {
    // 1. Compute frequencies
    map<char, int> freqMap;
    for (char c : X) freqMap[c]++;

    // 2. Initialize priority queue with single-node trees
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> Q;
    for (auto const& [ch, freq] : freqMap) {
        Q.push(new HuffmanNode(ch, freq));
    }

    

    // 3. Greedy merging: combine two trees with smallest frequencies
    while (Q.size() > 1) {
        HuffmanNode* T1 = Q.top(); Q.pop();
        HuffmanNode* T2 = Q.top(); Q.pop();

        // Create new internal node with sum of frequencies
        HuffmanNode* parent = new HuffmanNode(T1->freq + T2->freq, T1, T2);
        Q.push(parent);
    }

    // The remaining node is the root of the Huffman Tree
    return Q.top();
}

// =============================================================================
// 12.5.3: ENCODING AND DECODING
// =============================================================================

/**
 * generateCodes: Traverses the tree to create the bit-string mapping.
 * Left branch = 0, Right branch = 1.
 */
void generateCodes(HuffmanNode* root, string code, map<char, string>& codeMap) {
    if (!root) return;
    if (root->ch != '\0') {
        codeMap[root->ch] = code;
    }
    generateCodes(root->left, code + "0", codeMap);
    generateCodes(root->right, code + "1", codeMap);
}



// =============================================================================
// SUMMARY OF THE GREEDY METHOD
// =============================================================================
/**
 * GREEDY-CHOICE PROPERTY:
 * A global optimal can be reached by a series of locally optimal choices.
 * In Huffman coding, the local optimal choice is merging the two trees with 
 * the lowest frequencies.
 * * PREFIX CODE PROPERTY:
 * No code is a prefix of another. This ensures that Y can be decoded into X
 * unambiguously without needing separators.
 */

/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement a complete "Compress" and "Decompress" function using these trees?
 * 2. Explain the "Fractional Knapsack" problem (another classic Greedy example)?
 * 3. Discuss the "Optimal Substructure" property required for Greedy algorithms?
 */
