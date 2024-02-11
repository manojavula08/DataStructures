/*
    Name: Manoj Kumar Reddy
    Project Name: Building a word autocomplete application using an alphabet trie
    Description: constructing an alphabetic dictionary trie for inserting and search the words by prefix and a word mentioned by end user and retrive the data.
*/

#include<iostream>
#include <exception>
#include <vector>
#include<string>
#include "TrieNode.h"
using namespace std;

class Trie
{
public:
    
    int size;// size is no of nodes
    int countMatched; // used to get no of words which has string given
    int numberOfWords;// used to get no of words inserted
    //constructor of trie class
    Trie();
    //desctructor of trie class used for no memeory leaks
    ~Trie();
    // inserts words into trie
    bool insert(string);
    // is used to get no of words inserted
    int count();
    // is used to get no of nodes created
    int getSize();
    //is used to search for word in trie returns true if word found and flase if not found
    bool find(string);
    //Is used to get no of words which start with given string
    int completeCount(string);
    //function is used to get number of words which start with given string
    vector<string> complete(string);
    //this function is used to copy one trie to other trie initially clearning all nodes
    Trie& operator=(const Trie&);
    //is the copy constructor ---------
    Trie(const Trie& other);
    
    TrieNode* root; // root node
    void clearTrieTree(TrieNode* ); // used to clear the trie tree
    void searchWords(TrieNode*, vector<string>&, string, int&); // it's a search function for words
    void deepCopyTrie(TrieNode*, TrieNode*& ); // help the copy of the tree
    
};