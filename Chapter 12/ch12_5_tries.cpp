/**
 * CHAPTER 12.5: TRIES (STANDARD, COMPRESSED, AND SUFFIX)
 * --- THE CONCEPT ---
 * A Trie (from "retrieval") is a tree-based data structure used to store a 
 * collection of strings. Unlike other trees, nodes do not store the keys 
 * themselves; instead, a node's position in the tree defines the key it is 
 * associated with.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// =============================================================================
// 12.5.1: STANDARD TRIE
// =============================================================================
/**
 * A Standard Trie stores a set of strings where:
 * - Each node (except root) is labeled with a character.
 * - Children are ordered by the alphabet.
 * - Paths from root to external nodes represent the strings.
 * Complexity: Search/Insert O(dm) where d=alphabet size, m=string length.
 */



struct TrieNode {
    map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class StandardTrie {
public:
    StandardTrie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) return false;
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }

private:
    TrieNode* root;
};

// =============================================================================
// 12.5.2: COMPRESSED TRIE (PATRICIA TRIE)
// =============================================================================
/**
 * A Compressed Trie reduces space by merging "redundant" chains of nodes 
 * (nodes with only one child) into a single edge labeled with a substring.
 * Complexity: Space O(s) where s is the number of strings.
 */



/**
 * COMPACT REPRESENTATION:
 * Instead of storing strings in edges, we store triplets (i, j, k)
 * representing the substring S[i][j..k] from a primary array of strings.
 */

// =============================================================================
// 12.5.3: SUFFIX TRIES
// =============================================================================
/**
 * A Suffix Trie is a compressed trie of all suffixes of a single string X.
 * - Used for: Pattern matching in a fixed text.
 * - Space: O(n) for a string of length n (using compact representation).
 * - Match Query: O(m) where m is the length of the pattern.
 */



// =============================================================================
// 12.5.4: SEARCH ENGINES & INVERTED FILES
// =============================================================================
/**
 * Search engines use an Inverted Index:
 * 1. Vocabulary (Terms): Stored in a Compressed Trie for O(m) lookup.
 * 2. Occurrence Lists (Postings): Lists of Web pages containing each term.
 * * Logic:
 * Query "Hamilton" -> Search Trie -> Get Index of Occurrence List -> Load List.
 */



/**
 * WOULD YOU LIKE ME TO:
 * 1. Implement a Prefix Matcher that returns all words starting with a string?
 * 2. Show the logic for intersecting two Occurrence Lists (AND query)?
 * 3. Explain the "Suffix Array," a more space-efficient alternative to Suffix Tries?
 */
