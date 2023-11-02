/*
    Name: Manoj Kumar Reddy Avula
    Project Name: Indexing with AVL Trees
    Description: implementing the AVL Tree that insert based on BST tree and rebalance the based on AVL tree properties rotate left, rotate right and also double rotation left and right based on the balance factor of the node. Also return the height, size and range of nodes provides by the end user.  
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