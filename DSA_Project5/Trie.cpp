/*
    Name: Manoj Kumar Reddy
    Project Name: Building a word autocomplete application using an alphabet trie
    Description: constructing an alphabetic dictionary trie for inserting and search the words by prefix and a word mentioned by end user and retrive the data. 
*/

#include "Trie.h"
using namespace std;

/*
    Function: Trie -- default constructer
    Parameters: None
    return: None
*/
Trie::Trie(): root(nullptr), size(ZERO), countMatched(ZERO), numberOfWords(ZERO) {}

/*
    Function: ~Trie -- destructer for Trie class
    Parameters: None
    Return: None
*/
Trie::~Trie(){
    Trie::clearTrieTree(root); // calling the function
}

/*
    Function: insert -- data will inserterd in trie in alphabetic way 
    Parameters: data -- data is words in the wordFile
    return: bool -- is true or not
*/
bool Trie::insert(string data){
    if(!root){ // root equal to null
        root = new TrieNode();
        size = ZERO;
    }
    
    TrieNode* headNode = root;
    for(char character : data){ // iterating the data charcters
        int index = character - 'a';
        if (index >= ZERO && index < ALPHA_SIZE) { //checking the index is betweeen the range
            if(!headNode->trieNodes[index]){
                headNode->trieNodes[index] = new TrieNode();
                size++; // incrementing the size
            }
            headNode = headNode->trieNodes[index];   
        }
    }
    if (!headNode->wordEnd) {
        headNode->wordEnd = true;
        numberOfWords++; // Increment the number of words
        return true; // Word inserted successfully
    }

    return false; // Word not inserted successfully
}

/*
    Function: completeCount -- return the number of words of given string
    parameter: data -- word is given by end user
    return: number of count
*/
int Trie::completeCount(string data){
    vector<string> matchWords; // words store in vector
    countMatched = ZERO; // number of matched 
    TrieNode* headNode = root;
    for(char character : data){ // iterate the data charcter
        int index = character - 'a';
        if(!headNode->trieNodes[index]){
            return countMatched;
        }
        headNode = headNode->trieNodes[index];
    }
    searchWords(headNode, matchWords, data, countMatched); // calling the function
    return countMatched; // return countMatched
}

/*
    Function: searchWords -- it creates the vector of words
    parameter: headNode -- node of trie, matchWords -- vector words of matched, prefixWords -- string, count -- number of words
    return: None
*/
void Trie::searchWords(TrieNode* headNode, vector<string>& matchWords, string prefixWord, int& count){
    if(headNode->wordEnd != false){ // is wordEnd or not
        count++;
        matchWords.push_back(prefixWord); // insert into the vector
    } 
    for (int i = ZERO; i < ALPHA_SIZE; i++) {
        TrieNode* subNode = headNode->trieNodes[i];
        if (subNode) { //subNode not equal to null
            char character = 'a' + i;
            string newPrefixWord = prefixWord + character;
            searchWords(subNode, matchWords, newPrefixWord, count);// calling the function
        }
    }
    
}

/*
    Function: getSize -- size of trie
    parameter: None
    return: size -- int
*/
int Trie::getSize(){
    return size;
}

/*
    Function: complete -- get number of words start with given string
    parameter: word -- string
    return: vector words
*/
vector<string> Trie::complete(string word)
{
    vector<string> vector_words;
    TrieNode* current = root;
    int count = ZERO;
    for (char the_char : word) { // iterate the character of data
        int index = the_char - 'a';
        if (current->trieNodes[index] == nullptr) {
            return vector_words;
        }
        current = current->trieNodes[index];
    }
    searchWords(current,vector_words,word, count); // calling the function
    
    return vector_words; // returns words

}

/*
    Function: deepCopyTrie -- copy the trie to another trie
    parameter: orginaltrie, duplicateTrie
    return: None
*/
void Trie::deepCopyTrie(TrieNode* orginalTrie, TrieNode*& duplicateTrie){
    
    if (orginalTrie == nullptr) { // checking the wheater orginal tree is null or not
        return;
    }

    duplicateTrie = new TrieNode();  //class for trie nodes
    duplicateTrie->wordEnd = orginalTrie->wordEnd;

    for (int i = 0; i < 26; ++i) {  // 26 nodes for each letter
        if (orginalTrie->trieNodes[i] != nullptr) {
            deepCopyTrie(orginalTrie->trieNodes[i], duplicateTrie->trieNodes[i]);
        }
    }

}

/*
    Function: operator -- copy one trie to another by cleaning trie
    parameter: trie -- trie
    return: trie
*/
Trie& Trie::operator=(const Trie& trie){
    if(root != nullptr){
        clearTrieTree(root); // calling the function to clear root
    }
    deepCopyTrie(trie.root, root); // copy of trie
    return *this;
}

/*
    Function: Trie -- is the copy constructor 
    parameter: trie --  variable for trie
    return: None 
*/
Trie::Trie(const Trie& trie ){
    root = new TrieNode();
    deepCopyTrie(trie.root, root);
}

/*
    Function: count -- number of words
    parameter: None
    return: numberOfWords
*/
int Trie::count(){
    return numberOfWords;
}

/*
    Function:    -- search the word and retrun true if found
    parameters: word -- string to be searched
    return: boolean
*/
bool Trie::find(string word)
{
    TrieNode* headNode = root;
    int index;
    for (char charcter : word)
    {
        index = charcter - 'a';
        if (headNode->trieNodes[index]==nullptr)  // check the node index is null or not
        {
            return false;
        }
        headNode = headNode->trieNodes[index];
    }
    if (headNode != nullptr && headNode->wordEnd)  // checks the node is pointing to wordEnd and current node is not equal to null pointer
    {
        return true;  
    }
    else
    {
    return false;
    }
    return false;
}

/*
    Function: cleanTrieTree -- destructer of trie
    parameter: deleteCurrent -- trie Node
    return: None
*/
void Trie::clearTrieTree(TrieNode* deleteCurrent){
    if(!deleteCurrent){ // if deleteCurrent is equal to null
        return;
    }
    for(int i=ZERO; i<ALPHA_SIZE; i++){ // iterating the loop
        if(deleteCurrent->trieNodes[i]){
            clearTrieTree(deleteCurrent->trieNodes[i]); // calling the function
            delete deleteCurrent->trieNodes[i]; // deleting the current node
            deleteCurrent->trieNodes[i] = nullptr;
        }
    }
    deleteCurrent->wordEnd = false;// assigning the worndEnd false
}