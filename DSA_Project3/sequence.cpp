/*
Project Name:  Linked Sequence Data Structure
*/
#include "Sequence.h" // importing the sequence.h file

/*
    Function: Sequence -- It is the parameterized constructer of the Sequence class used to create the objects.
    Parameters: sz -- the length of the sequence(int)
    Return: None

*/
Sequence::Sequence(size_type sz)
{
    numElts = sz;
    head = nullptr;
    tail = nullptr;
    // The for loop run as the size given by the user and create objects with intial value as 0 by calling the pushback function.
    for(size_type i=0; i<numElts;i++)
    {
        push_back(0);
    }
}

/*
    Function: Sequence -- It is the parameterized constructer of the Sequence class used to deep copy of the sequence objects.
    Parameters: s -- sequence object.

*/
Sequence::Sequence(const Sequence& s)
{
    head = nullptr; 
    if(s.head != nullptr) // checking the head is a nullptr or not
    {
        SequenceNode* deepCopy = s.head;
        while(deepCopy != nullptr)
        {
            push_back(deepCopy->elt); // calling the push_back function
            deepCopy = deepCopy->next;
        }
    }

}

/*
    Function: ~Sequence -- It is a destructor which clears the memory in the heap to avoid the memory leak.
*/
Sequence::~Sequence()
{
    clear();// calling the function clear.
}

/*
    Function: operator -- This operator is used to assign the value of one object from the sequence to another.
    Parameter: s -- object of the sequence
    Return: *this -- returns current object.
*/
Sequence& Sequence::operator=(const Sequence& s)
{
    clear(); //clearing the memory by calling function clear.
        head = nullptr;
    if(s.head != nullptr){
        SequenceNode* deepCopy = s.head;
        while(deepCopy != nullptr){
            push_back(deepCopy->elt);
            deepCopy = deepCopy->next;
        }
    }
    return *this;
}

/*
    Function: operator[] -- this operator allows to access elements in the Sequence by index position and returns value.
    Parameter: position -- is index of the Sequence
    Return type: returns the position value of the sequence object.
*/
Sequence::value_type& Sequence::operator[](size_type position)
{   // checking the position is inbound of the sequence size.
    if(position > numElts && position < 0){
        throw exception();
    }
    SequenceNode* current = head;
    // for loop is used to pass through the nodes.
    for(size_type i=0; i<position; i++){
        current = current->next;
    }
    return current->elt;
}

/*
    Function: push_back -- create a new node and add at end.
    Parameter: value -- value that need to be add
    Return: None
*/
void Sequence::push_back(const value_type& value)
{
    // checking the head is wheater null or not 
    if(head == nullptr){
        SequenceNode* newNode = new SequenceNode(value);
        head = newNode;
    }
    else{
        SequenceNode* currentNode = head;
        // while loop is used to pass through the nodes until the null trigers.
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        SequenceNode* newNode = new SequenceNode(value);
        currentNode->next = newNode;
        newNode->prev = currentNode;
        tail = newNode; // assigning the tail to the last node.
        
    }
}

/*
    Function: pop_back -- used to remove the last node of the linked list
    Paramters: None
    Returns: None
*/
void Sequence::pop_back()
{
    // if length is null trigger the exception.
    if(numElts <= 0){
        throw exception();
    }
    else{
        // pointing the lastnode object to the tail.
        SequenceNode* lastNode = tail;
        tail = tail->prev;

        if(tail == nullptr){
            head = nullptr;
        }
        else{
            tail->next = nullptr;
        }
        // delete the last node and reduce the length by 1
        delete lastNode;
        numElts = numElts - 1;
    }
}

/*
    Function: insert -- is used to assign value to Sequence at the particular index of list
    Parameters: position and value -- index and element .
    Return: None
*/
void Sequence::insert(size_type position, value_type value)
{
    if (position<0 || position>numElts) // if position less than 0 or greater than or equal to no of elements.
    {
        throw exception();
    }
    else
    {
        SequenceNode* newNode = new SequenceNode();
        SequenceNode* tempNextNode = nullptr;
        newNode->elt = value;
        if (position == 0)// Insert at the beginning position. 
        {  
            newNode->next = head;    
            newNode->prev = nullptr; 
            if (head != nullptr) // If head not equal to nullptr assign newNode to prev of head
            {
                head->prev = newNode; 
            }
            head = newNode; 
            if (tail == nullptr) // If the list was empty, update the tail as well
            {
                tail = newNode;
            }
        } 
        else  // Insert at the specified position
        { 
            SequenceNode* insertNode = head;
            for (size_type i = 1; i<position; i++) // pass through till the position index
            {
                insertNode = insertNode->next;
            }
            newNode->next = insertNode->next;  
            newNode->prev = insertNode;

            if (insertNode->next != nullptr) // Pass through until the node next equals to null
            {
                tempNextNode = insertNode->next;
                tempNextNode->prev = newNode; 
            }
            insertNode->next = newNode;
            
        }
        
    }
    numElts++; // Increase the number of elements by 1.
}

/*
    Function: front -- return the first value.
    Paramters: None
    Return: first node element.
*/
const Sequence::value_type& Sequence::front() const
{   bool isEmpty = empty();
    if(isEmpty) // throw exception if sequence is empty
    {
        throw exception();
    }
    else
    {
        SequenceNode* firstNode = head;
        return firstNode->elt;
    }
}

/*
    Function: back -- return the last value.
    Paramters: None
    Return: last node element.
*/
const Sequence::value_type& Sequence::back() const
{
    bool isEmpty = empty();
    if(isEmpty)// throw exception if sequence is empty
    {
        throw exception();
    }
    else
    {
        SequenceNode* lastNode = tail;
        return lastNode->elt;
    }
}

/*
    Function: empty -- It return the sequence elements are empty or not.
    Paramters: None
    returns: boolean 
*/
bool Sequence::empty() const
{
    if(numElts == 0) // check number of elements are 0 or not.
    {
        return true;
    }
    else{
        return false;
    }
}

/*
    Function: size - returns  number of nodes length
    Paramters: None
    returns: length of the sequence. 
*/
Sequence::size_type Sequence::size() const
{
    size_type length=0;
    Sequence::SequenceNode* element = head;
    while (element != nullptr) // pass through till end of the nodes and increments by 1.
        {
            length++;
            element = element->next;
        }
    
    return length ;
}

/*
    Function: clear - function delete all nodes
*/
void Sequence::clear()
{
    if (head!= nullptr)
    {
        SequenceNode* deleteNode = head;
        while (deleteNode != nullptr) // pass through nodes till the nullptr
        {
            SequenceNode* deleteNodeNext = deleteNode->next;
            delete deleteNode;
            deleteNode = deleteNodeNext;
            numElts--; // Decrease the number of elements by 1.
        }
    }
    head = nullptr;
}

/*
    Function: erase - clear number of elements from the postion as given by count.
    Parameters:  positoin -- index of the node, count -- number of nodes from the postion
    returns: None 
*/
void Sequence::erase(size_type position, size_type count)
{
    if(position >= numElts || count > numElts-position || position <0 || count == 0){
        throw exception();
        }
    else{
        SequenceNode* deleteCurrentNode = head;
        for(size_type i=0; i<position; i++)// finding a node at specified position for delete
        {
            deleteCurrentNode = deleteCurrentNode->next;
        }

        SequenceNode* deleteNextNode = deleteCurrentNode->prev;
        for(size_type i=0; i<count; i++)// travels from position and deletes till count 
        { 
            SequenceNode* countEnd = deleteCurrentNode->next;
            delete deleteCurrentNode;
            deleteCurrentNode = countEnd;
            numElts = numElts -1;
	    }
        if (deleteNextNode != nullptr && deleteCurrentNode != nullptr) // if node before position is not null then assigns node value after count
        {
            deleteNextNode->next = deleteCurrentNode;
            deleteCurrentNode->prev = deleteNextNode;
	    }

        if (deleteCurrentNode == nullptr) // if node after count is null then tail is node before position
        {

            tail = deleteNextNode;

            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
        }
        if (deleteNextNode == nullptr) // if node before is null then head is node after count
        {
            head = deleteCurrentNode;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }

        }
    }
}

/*
    Function: print -- display the node elements
    Parameters: ostream os -- output stream used for sending output to various destinations
    returns: None
*/
void Sequence::print(ostream& os) const
{
    Sequence::SequenceNode* currentNode = head;
    os<<"<";
    while (currentNode != nullptr) // pass through till nodes points to null
        {
            os << currentNode->elt; // print the output element
            if(currentNode->next != nullptr) // check wheater next element is null or not
            {
                os<<", ";
            } 
            currentNode=currentNode->next;
        }
    os<<">";
}

// Don't modify, do the output in the print() method
/*
    Function: operator -- used to output the content of sequence.
    Parameters: ostream os -- output stream used for sending output to various destinations, sequence -- address of sequence.
    returns: os
*/
ostream& operator<<(ostream& os, const Sequence& s)
{
    s.print(os);
    return os;
}
