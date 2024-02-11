/*
    Name: Manoj Kumar Reddy
    Project Name: Building a word autocomplete application using an alphabet trie
    Description: constructing an alphabetic dictionary trie for inserting and search the words by prefix and a word mentioned by end user and retrive the data. 
*/

#include "TrieNode.h" // importing the TrieNode 
#include<string>

TrieNode::TrieNode(){
    wordEnd = false;
    for(int i=0; i<ALPHA_SIZE; i++){ // iterating the loop until 26 nodes
        trieNodes[i] = nullptr;
    }
}
