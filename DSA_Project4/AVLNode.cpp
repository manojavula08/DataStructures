/*
    Project Name: Indexing with AVL Trees
*/

#include "AVLNode.h" // importing the AVLNode 
#include<string>

/*
    function: AVLNode -- paramized constructer of AVLNode class
    parameters: newKey, newValue
    return: None
*/
AVLNode::AVLNode(int newKey, string newValue): left(nullptr), right(nullptr){
    value = newValue;
    height = 0;
    key = newKey;
}
