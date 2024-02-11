/*
    Name: Manoj Kumar Reddy
    Project Name: Building a word autocomplete application using an alphabet trie
    Description: constructing an alphabetic dictionary trie for inserting and search the words by prefix and a word mentioned by end user and retrive the data. 
*/

#include "Trie.h"
#include <iostream>
#include <fstream> // fstream for file stream objects
#include <vector>
#include <string>
using namespace std;
int main() 
{
    Trie trie;
    ifstream fileIn("wordfile.txt"); //reading the file
    vector<string> wordFileList;
    if (fileIn.good()){ // make sure we opened the file properly
        string word;
        while (fileIn >> word){ // reading the file  
            trie.insert(word); // inserting into trie
        }
    }
    else {
        cout << "Couldn't open file!" << endl; // prints the error message
    }
    fileIn.close(); // closing the file
    for (string item : wordFileList){ //iterating the for loop
        cout << item << " "; // print the wordFileList
    }
    cout << endl;
    trie.find("quadrilateral");
    while(true){ // while loop will break if no word entered into it.
        cout<<"Please enter a word prefix (or press enter to exit): ";
        
        string input;
        getline(cin,input); // takes input
        if(input == ""){
            break;
        }
        else{
            cout<<"There are "<< trie.completeCount(input); // get the number of words which start with provides word.
            cout<<" completions for the prefix "<<input<<".  Show completions? ";
            string choice;
            getline(cin,choice);
            if(choice =="Yes"||choice == "yes"){
                cout<<"Completions\n"<<"-----------"<<endl;

                vector<string> getWords = trie.complete(input); // get the number of resulted words with given input.
        
                for(string word: getWords) // iterates the getWords and print the data
                {
                    cout<<word<<endl;
                }
            }
        }

    } 
    return 0;
    
}
