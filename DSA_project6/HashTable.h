/*
    Name: Manoj Kumar Reddy Avula
    Project Name: Hash Table Indexing
    description: Indexing the data into the Hash table using linear probing
*/
#include<iostream>
#include<vector>
#include "Slot.h"

#define MAXHASH 20 // defining the size of array

using namespace std;

class HashTable{
    private:
    Slot slots[MAXHASH]; // size of array
    vector<int> searchSlot; // number of slots searched before insertion
    int usedSlot; // number of slots used in hashTable

    public:
    HashTable(); // constructer
    bool insert(int, int, int&); // insert into the database
    bool remove(int); // remove the key from the database
    bool find(int, int&, int&); // return true if found
    float alpha(); // load factor
    friend ostream& operator<<(ostream&, const HashTable&); // prints hashTable
    ~HashTable(); // destructer
    Slot& getSlotIndex(int); // retruns the slot index
    bool findSlot(int, int&); // the slot for the data
};