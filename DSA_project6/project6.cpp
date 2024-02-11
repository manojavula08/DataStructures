/*
    Name: Manoj Kumar Reddy Avula
    Project Name: Hash Table Indexing
    description: Indexing the data into the Hash table using linear probing
*/
#include "Database.h"

using namespace std;

int main() {
    // Instializing the required variables for the project
    Database database; 
    Record record;      
    int collisions;   
    char input;
    string lastName;    
    string firstName;   
    int uid;
    string year;

    // using the while for particular action
    while (true) {
        cout << "Would you like to (I)nsert or (D)elete a record, or (S)earch for a record, or (P)rint the database, or (Q)uit?" << endl;
        cout << "Enter input: ";
        cin >> input;

        switch (input) {
                //inserts uid
            case 'I':
                {
                    // insert the data into the database and taking the inputs
                    cout << "Inserting a new record." << endl;
                    cout << "Last name: ";
                    cin >> lastName;
                    cout << "First name: ";
                    cin >> firstName;
                    cout << "UID: ";
                    cin >> uid;
                    cout << "Year: ";
                    cin >> year;
                    if (uid > 99999999) { // if condition for uid shouldn't 9 digit
                        cout << "Error: UID must be 8 digits or fewer." << endl;
                    } else{
                        Record record(firstName, lastName, uid, year);


                        if (database.insert(record, collisions)) {
                            cout << "Record inserted (" << collisions << " collisions during insert)." << endl;
                        }
                        else {
                            cout << "Record could not be inserted." << endl;
                        }
                    }
                }
                break;

                // prints the database load factor
            case 'P':
                cout << database << endl;
                cout << "Load Factor of the Database: " << database.alpha() << endl;
                break;
            // remove the student from the database
            case 'D':
                cout << "Deleting a record." << endl;
                cout << "Enter UID: ";
                cin >> uid;

                if (database.remove(uid)) {
                    cout << "Record deleted." << endl;
                }
                else {
                    cout << "Record could not be deleted." << endl;
                }
                break;

            // exits the program
            case 'Q':
                cout << "Exiting." << endl;
                return 0;
                break;
            // search for the student in database
            case 'S':
                cout << "Enter UID to search for: ";
                cin >> uid;

                if (database.find(uid, record, collisions)) {
                    cout << "Searching... record found (" << collisions << " collisions during search)." << endl;
                    cout << "---------------------------" << endl;
                    cout << "Name: " << record.getName() << endl;
                    cout << "UID: " << record.getUID() << endl;
                    cout << "Year: " << record.getYear() << endl;
                    cout << "---------------------------" << endl;
                }
                else {
                    cout << "Searching... record not found." << endl;
                }
                break;
            default:
                break;

            cout << endl;
        }
    }
}