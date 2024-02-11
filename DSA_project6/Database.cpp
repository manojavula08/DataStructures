/*
    Name: Manoj Kumar Reddy Avula
    Project Name: Hash Table Indexing
    description: Indexing the data into the Hash table using linear probing
*/
#include "Database.h"

/*
    Function: Database -- constructer
    Parameters: none
    return: none
*/
Database::Database() {}

/*
    Function: ~database -- Destructor for the database
    Parameters: none
    return: none
*/
Database::~Database() {}

/*
    Function: insert -- insert into the database
    Parameters: record, newRecord, collisions
    return: bool
*/
bool Database::insert(const Record& newRecord, int& collisions) {
    return indexTable.insert(newRecord.getUID(), recordStore.size(), collisions) ? (recordStore.push_back(newRecord), true) : false;
}


/*
    Function: find -- ckeck the UID exists in the database or not
    Parameters: uid, foundrecord, collisions
    return: none
*/
bool Database::find(int uid, Record& foundRecord, int& collisions) {
    int HashTableIndex; 

    if (indexTable.find(uid, HashTableIndex, collisions)) {
        foundRecord = recordStore[HashTableIndex];
        return true;
    }

    return false;
}

/*
    Function: remove -- remove the user data from database
    Parameters: key
    return: none
*/
bool Database::remove(int key) {
    int HashTableIndex, collisions, slot;

    if (!indexTable.find(key, HashTableIndex, collisions)) {
        return false;
    }

    indexTable.remove(key);
    if (HashTableIndex != recordStore.size() - 1) {
        recordStore[HashTableIndex] = recordStore.back();
        indexTable.findSlot(recordStore[HashTableIndex].getUID(), slot);
        indexTable.getSlotIndex(slot).setIndex(HashTableIndex);
    }
    recordStore.pop_back();

    return true;
}

/*
    Function: aplha -- load factor
    Parameters: none
    return: load factor from database
*/
float Database::alpha() {
    return indexTable.alpha();
}

/*
    Function: operator -- print the hash table
    Parameters: os, hashtable
    return: output stream
*/
ostream& operator<<(ostream& os, Database& data) {
    int recordStoreIndex;   // the index of a student record in the vector of student records

    os << "Database contents:" << endl;

    int i = MAXHASH - 1;
    while (i >= 0) {
        if (data.indexTable.getSlotIndex(i).isNormal()) {
            recordStoreIndex = data.indexTable.getSlotIndex(i).getIndex();
            os << "HashTable Slot: " << i << ", recordStore slot " << recordStoreIndex << " -- " << data.recordStore[recordStoreIndex] << endl;
        }
        --i;
    }

    return os;
}
