/*
    Name: Manoj Kumar Reddy Avula
    Project Name: Indexing with AVL Trees
    Description: implementing the AVL Tree that insert based on BST tree and rebalance the based on AVL tree properties rotate left, rotate right and also double rotation left and right based on the balance factor of the node. Also return the height, size and range of nodes provides by the end user.  
*/

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "AVLNode.h"
using namespace std;

class AVLTree{
    public:
        int size; //size of the tree
        AVLTree(); // default constructer
        ~AVLTree(); // destructer
        bool insert(int key, string value); // insert function returns the boolean of success of node
        int getHeight(); // gets height of the tree
        int getSize(); // gets the size of the tree
        friend ostream& operator<<(ostream& os, const AVLTree& me); // print the key and values
        bool find(int key, string& value); // find the key is present in the tree or not
        vector<string> findRange(int lowkey, int highkey); // display the range of the nodes
    
        AVLNode* root; // root node
        bool isNodeInserted; // boolean check
        AVLNode* insertTreeNode(AVLNode* currentNode, int key, string value); // insert the node as per BST
        void clear(AVLNode* current); // clear the memory
        void printTreeNode(ostream&, AVLNode*, unsigned int) const; // print the tree
        AVLNode* balanceTree(AVLNode* balanceNode); // balance the tree as  per the AVL tree
        int calculateHeight(AVLNode* heightNode); // calculate the height of tree
        int balanceFactor(AVLNode* node); // returns the balance of each node
        AVLNode* rotateRight(AVLNode* node); // rotate the node to right 
        AVLNode* rotateLeft(AVLNode* node); // rotate the node to left
        AVLTree& operator=(const AVLTree &tree); // pass the object of the class
        void deepCopyTree(AVLNode*, AVLNode*&); // copy the one tree nodes to another tree
        void getRangeItems(AVLNode* current, int lowkey, int highkey, vector<string>& items); // returns the range of values.

};