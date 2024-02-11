/*
    Name: Manoj Kumar Reddy Avula
    Project Name: Hash Table Indexing
    description: Indexing the data into the Hash table using linear probing
*/
#include "HashTable.h"
#include "hashfunction.h"
#include<random>
#include<chrono>
#include<algorithm>

/*
    Function: HashTable -- constructer
    Parameters: none
    return: none
*/
HashTable::HashTable(): usedSlot(0){

    auto seed = static_cast<unsigned int>( std::chrono::system_clock::now().time_since_epoch().count() );
    int i=1;
    do
    {
        searchSlot.push_back(i);
        i++;
    } while (i < MAXHASH);
    
    shuffle(searchSlot.begin(), searchSlot.end(), default_random_engine(seed));
}

/*
    Function: HashTable -- constructer
    Parameters: none
    return: none
*/
HashTable::~HashTable(){}

/*
    Function: insert -- insert the data in the hashtable
    Parameters: key, index, collisions
    return: bool
*/
bool HashTable::insert(int key, int index, int& collisions) {
    if (find(key, index, collisions)) {
        return false;  
    }

    collisions = 0;
    int i = 0;

    do {
        int hashing = (jsHash(key) + i) % MAXHASH;

        if (slots[hashing].isNormal()) {
            collisions++;
        } else {
            slots[hashing].load(key, index);
            usedSlot++;
            return true;
        }

        i++;
    }
    while (i < MAXHASH);

    return false;
}

/*
    Function: getSlotIndex -- returns a refernce to slot in the hash table
    Parameters: slotIndex -- index of the slot in hash table
    return: none
*/
Slot& HashTable::getSlotIndex(int slotIndex){
    return slots[slotIndex];
}

/*
    Function: remove -- remove the entery from the database
    Parameters: key
    return: bool
*/
bool HashTable::remove(int key) {
    for (int i = 0; i < MAXHASH; ++i) {
        int hash = (jsHash(key) + i) % MAXHASH;

        if (slots[hash].isNormal() && key == slots[hash].getKey()) {
            // If the slot is occupied and the key matches, remove the key/index pair
            slots[hash].kill();
            usedSlot--;
            return true;
        } else if (slots[hash].isEmptySinceStart()) {
            // If the slot has always been empty, the key/index pair is not in the hash table
            return false;
        }
    }

    return false;  // Key not found in the hash table
}

/*
    Function: find -- find the data of the UID from teh hashTable
    Parameters: Key, index 
    return: bool
*/
bool HashTable::find(int key, int& index, int& collisions) {
    collisions = 0;

    for (int i = 0; i < MAXHASH; ++i) {
        int hash = (jsHash(key) + i) % MAXHASH;
        int currentKey = slots[hash].getKey();

        if (key == currentKey && slots[hash].isNormal()) {
            // If the slot is occupied and the key matches, update the index and return true
            index = slots[hash].getIndex();
            return true;
        } else if (slots[hash].isEmptySinceStart()) {
            // If the slot has always been empty, the key/index pair is not in the hash table
            return false;
        }

        // Otherwise, probe the hash table
        collisions++;
    }

    return false;
}

/*
    Function: alpha -- retruns the load factor
    Parameters: none
    return: load factor
*/
float HashTable::alpha() {
    return (usedSlot / MAXHASH);
}

/*
    Function: operator -- print the hash table
    Parameters: os, hashtable
    return: output stream
*/
ostream& operator<<(ostream& os, const HashTable& hashTable) {
    os << "HashTable contents:" << endl;
    
    int i = MAXHASH - 1;
    while (i >= 0) {
        if (hashTable.slots[i].isNormal()) {
            os << "HashTable Slot " << i << ": " << hashTable.slots[i] << endl;
        }
        --i;
    }

    return os;
}

/*
    Function: findSlot -- search for the slot in the hashTable
    Parameters: key, slot
    return: bool
*/
bool HashTable::findSlot(int key, int& slot) {
    int collisions;
    return find(key, slot, collisions);
}
