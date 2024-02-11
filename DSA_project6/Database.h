/*
    Name: Manoj Kumar Reddy Avula
    Project Name: Hash Table Indexing
    description: Indexing the data into the Hash table using linear probing
*/
#pragma once

#include "Record.h"
#include "HashTable.h"

using namespace std;

class Database {

    public:

        HashTable indexTable;                               
        vector<Record> recordStore;                         

        Database();                                         // Constructor for the database

        ~Database();                                        // Destructor for the database

        bool insert(const Record&, int&);                   // inserts a record into database

        bool remove(int);     // removes the student record with the provided UID from the database

        bool find(int, Record&, int&);    // check for uid

        float alpha();  // calculates the load factor

        friend ostream& operator<<(ostream&, Database&);    // prints out the database


};