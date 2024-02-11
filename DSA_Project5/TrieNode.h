/*
    Name: Manoj Kumar Reddy
    Project Name: Building a word autocomplete application using an alphabet trie
    Description: constructing an alphabetic dictionary trie for inserting and search the words by prefix and a word mentioned by end user and retrive the data.
*/

#include <iostream>
using namespace std;
#define ALPHA_SIZE 26
#define ZERO 0
class TrieNode{
    public:
        TrieNode* trieNodes[ALPHA_SIZE];
        bool wordEnd;
        TrieNode();
};
        