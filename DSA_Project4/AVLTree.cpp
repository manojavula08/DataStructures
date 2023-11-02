/*
    Name: Manoj Kumar Reddy Avula
    Project Name: Indexing with AVL Trees
    Description: implementing the AVL Tree that insert based on BST tree and rebalance the based on AVL tree properties rotate left, rotate right and also double rotation left and right based on the balance factor of the node. Also return the height, size and range of nodes provides by the end user.  
*/

#include "AVLTree.h" // importing the AVLTree
using namespace std;

/*
    Function: AVLTree -- default constructer
    Parameters: None
    return: None
*/
AVLTree::AVLTree(): root(nullptr), size(0){}

/*
    Function: ~AVLTree -- destructer is used to delete the memory to avoid memory leak
    Parameters: None
    return: None
*/
AVLTree::~AVLTree(){
    AVLTree::clear(root); // calling the clear function
}

/*
    Function: getSize -- returns the size of the tree
    Parameters: None
    return: size(int)
*/
int AVLTree::getSize(){
    return size;
}

/*
    Function: getHeight -- returns the height of the tree
    Parameters: None
    return: treeHeight(int)
*/
int AVLTree::getHeight(){
    return calculateHeight(root); // calling the function
}

/*
    Function: find -- returns the node is present or not
    Parameters: key -- node key to be checked, value -- node value refernce to be assigned
    return: return boolean
*/
bool AVLTree::find(int key, string& value){

    // iterate the nodes until the key found or equal to nullptr
    for(AVLNode* nodeCheck = root; nodeCheck!= nullptr; ){
        if(key < nodeCheck->key){
            nodeCheck = nodeCheck->left;
        }
        else if(key > nodeCheck->key){
            nodeCheck = nodeCheck->right;
        }
        else if(key == nodeCheck->key){ // if key found return true
            value = nodeCheck->value;
            return true;
        }
    }
    return false; // return false if not found
}

/*
    Function: getRangeItems -- returns the number of nodes between the low anf high keys
    Parameters: current -- presentNode, lowKey, highKey -- rangeKeys, items -- keys that store.
    returns: None

*/
void AVLTree::getRangeItems(AVLNode* current, int lowkey, int highkey, vector<string>& items) 
{
    if (current != nullptr) 
    {
        if (current->key >= lowkey && current->key <= highkey) 
        {
            // If node key is in the defined range, repeaedlly call the function
            // left and right subtrees will add the value to items vector.
            getRangeItems(current->left, lowkey, highkey, items);
            items.push_back(current->value);
            getRangeItems(current->right, lowkey, highkey, items);
        }
    }
}


/*
    Function: findRange -- this function uses the range_helper and gets the values within range
    Parameters: lowKey, highKey -- keys range to find 
    return type - return type is vector string
*/
vector<string> AVLTree::findRange(int lowkey, int highkey)
{
    vector<string> items; // creating the variable result of type vector string
    getRangeItems(root, lowkey, highkey, items);// calling function getRangeItems
    return items;
}

/*         
    Function: calculateHeight -- calculate the height of the node and return
    Parameters: heightNode -- node to be assigned the height
    return: node height
*/
int AVLTree::calculateHeight(AVLNode* heightNode){
    if (heightNode == nullptr) {
        return -1;  // returns when the size is 0
    }
    int leftHeight = calculateHeight(heightNode->left);
    int rightHeight = calculateHeight(heightNode->right);

    // update the current node with maximum of left and right subtrees by increment of 1.
    heightNode->height = max(leftHeight, rightHeight) + 1;

    return heightNode->height;
}

/*
    Function: balanceFactor -- check for left subtrees and right subtrees heights of the node and return the balance number of node
    Parameters: node to be checked
    return: balance of node
*/
int AVLTree::balanceFactor(AVLNode* node){
    if(!node){ // node is null
        return 0;
    }
    // calculating the height of left and right height of node
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    // return the balance of left and right height of node
    return (leftHeight - rightHeight);
}

/*
    Function: balanceTree -- function is used to check the balance of the node and perform the right of left rotation accordingly
    Parameters: balanceNode -- node to be checked
    return: balanceNode
*/
AVLNode* AVLTree::balanceTree(AVLNode* balanceNode){
    if(!balanceNode){
        return balanceNode;
    }
    int balanceNumber = balanceFactor(balanceNode);
    if(balanceNumber <= -2){
        if(balanceFactor(balanceNode->right) >= 1){
            balanceNode->right = rotateRight(balanceNode->right); // double right rotation
        }
        return rotateLeft(balanceNode);
    }
    else if(balanceNumber >= 2){
        if(balanceFactor(balanceNode->left)<= -1){
            balanceNode->left = rotateLeft(balanceNode->left); // double left rotation
        }
        return rotateRight(balanceNode);
    }
    return balanceNode;

}

/*
    function: rotateRight -- rotate node to the right to balance the tree
    parameters: problemNode -- node to be balanced
    returns: hookNode
*/
AVLNode* AVLTree::rotateRight(AVLNode* problemNode) {
    AVLNode* hookNode = problemNode->left;
    AVLNode* tempHookNodeRightSubtree = hookNode->right;

    // changing the rotation of nodes
    hookNode->right = problemNode;
    problemNode->left = tempHookNodeRightSubtree;

    // Update the heights of the changed nodes
    calculateHeight(problemNode);
    calculateHeight(hookNode);

    return hookNode;
}

/*
    function: rotateLeft -- rotate node to the left to balance the tree
    parameters: problemNode -- node to be balanced
    returns: hookNode 
*/
AVLNode* AVLTree::rotateLeft(AVLNode* problemNode) {
    AVLNode* hookNode = problemNode->right;
    AVLNode* tempHookNodeLeftSubtree = hookNode->left;

    // changing the rotation of the nodes
    hookNode->left = problemNode;
    problemNode->right = tempHookNodeLeftSubtree;

    // Update the heights of the changed nodes
    calculateHeight(problemNode);
    calculateHeight(hookNode);

    return hookNode;
}

/*
    Function: insertTreeNode -- insert the nodes as per the BST algorithm
    Parameters: newNode(root), key(int), value(string)
    return: nodeInsertedValue(int)
*/
AVLNode* AVLTree::insertTreeNode(AVLNode* newNode, int key, string value){
    if(newNode == nullptr){
        AVLNode* nodeInsertedValue = new AVLNode(key, value);
        size++;
        isNodeInserted = true;
        return nodeInsertedValue; 
    }
    else if(key == newNode->key) // if key is equals to current node key returns false due to duplicate element
    {
        isNodeInserted = false;
        return newNode;
    }
    else if(key < newNode->key) // if key is less than a node then it gets inserted to left side of the current node
    { 
        newNode->left = insertTreeNode(newNode->left, key, value);
    } 
    else if(key > newNode->key)// if key is greater than a node then get inserted to right side of the node
    { 
        newNode->right = insertTreeNode(newNode->right, key, value);
    }
    return balanceTree(newNode);
    
}

/*
    function: insert -- insert is used insert the node in tree using the insertTreeNode function and returns the key is duplicate or not.
    parameters: key(int), value(string)
    returns: boolean
    
*/
bool AVLTree::insert(int key, string value){
    AVLNode* newTreeNode = insertTreeNode(root, key, value);// calling the insertTreeNode function for insertion
    if (newTreeNode != root) {
        root = newTreeNode;
        return isNodeInserted; // Insertion was successful
    } else {
        return isNodeInserted; // Duplicate key
    }
}



/*
    Function: clear- Is used to delete nodes of the AVLTree
    Parameter- deleteCurrent
    return: None
*/
void AVLTree::clear(AVLNode* deleteCurrent)
{
    if (deleteCurrent != nullptr) { //post order delete
            clear(deleteCurrent->right);
            clear(deleteCurrent->left);
            delete deleteCurrent;
            size--; // decrement of the size
        }
}

/*
    Function: deepCopyTree -- deep copy of one tree to another
    Parameters: orginalTree -- the that need to be copied, duplicateTree -- tree need to be filled
    return: None
*/
void AVLTree::deepCopyTree( AVLNode* orginalTree, AVLNode*& duplicateTree) {
    if (orginalTree!= nullptr){
        duplicateTree = new AVLNode(orginalTree->key, orginalTree->value);
        deepCopyTree(orginalTree->left,duplicateTree->left); // calls recursively the function and copy left nodes
        deepCopyTree(orginalTree->right,duplicateTree->right);// copies right nodes into new nodes
        duplicateTree->height = orginalTree->height;
        
    }

}

/*
    Function: operator -- this operator is used to assign the value of one object from the tree to another.
    Parameters: tree -- AVLTree object.
    returns: *this

*/
AVLTree& AVLTree::operator=(const AVLTree &tree) {
    // Clear the existing nodes.
    if(root != nullptr){
        clear(root);
    }
    deepCopyTree(tree.root, root);
    return *this;
}

/*
    Function: printTreeNode -- display the node elements
    Parameters: ostream os -- output stream used for sending output to various destinations, printNode -- root node of tree
    returns: None
*/
void AVLTree::printTreeNode(ostream& os, AVLNode* printNode,unsigned int space) const{
    if(printNode != nullptr){
        printTreeNode(os, printNode->right, space + 1);
        os<<string(space * 4,' ');
        os<<printNode->key<<" : "<<printNode->value<<endl;
        printTreeNode(os, printNode->left, space + 1);

    }
} 

/*
    Function: operator -- used to output the content of sequence.
    Parameters: ostream os -- output stream used for sending output to various destinations, AVLTree -- address of AVLTree.
    returns: os
*/
ostream& operator<<(ostream& os, const AVLTree& me){
    if(me.root == nullptr || me.size == 0){
        throw exception();
    }
    me.printTreeNode(os, me.root, 0);
    return os;
}