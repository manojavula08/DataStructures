/*
    Project Name: Indexing with AVL Trees
*/

#include <iostream>
#include <string>
using namespace std;

class AVLNode{
    public:
        // left node of a parent node
        AVLNode* left;
        // right node of a parent node
        AVLNode* right;
        // key of a node
        int key;
        // value of a node
        string value;
        // height of a tree
        int height;

        // paramzised constructer to create a new node
        AVLNode(int newKey, string newValue);
};
