/*
    Name: Manoj Kumar Reddy Avula
    Project Name: Indexing with AVL Trees
    Description: implementing the AVL Tree that insert based on BST tree and rebalance the based on AVL tree properties rotate left, rotate right and also double rotation left and right based on the balance factor of the node. Also return the height, size and range of nodes provides by the end user.  
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
