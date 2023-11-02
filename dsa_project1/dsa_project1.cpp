// the library that provides input and output functionality using streams.
#include<iostream>
// header file that contains a set of general-purpose functions
#include<cstdlib>
// we use namespace std without having to prefix with the std:: namespace qualifier.
using namespace std;
// declaring the MAX_ROLL and MIN_ROLL using define keyword
#define MAX_ROLL 12
#define MIN_ROLL 2
/* --------------------------------------
    main: 
    return: returns a program has completed its task without errors
-----------------------------------------*/

int main()
{
    // initializing the integer variable for number of rolls
    int numberOfRolls;
    // requesting the input from the user
    cin>> numberOfRolls;
    short int diceTotal=0; // initializing the short integer variable for count of two dice
    int totalCount[MAX_ROLL] = {0}; // creating the totalCount array intializing the 0 to all values
    srand(time(NULL)); // seeding the random with current time for different iteration every time.
    for(int i=0;i<numberOfRolls;i++)
    {
        short int dice1 = (rand()%6)+1; // created dice1 variable for store the random number between 1 to 6.
        short int dice2 = (rand()%6)+1; // created dice2 variable for store the random number between 1 to 6.
        diceTotal = dice1 + dice2; // storing the sum of dice1 and dice2 in diceTotal
        totalCount[diceTotal] += 1; // incrementing the array values based on totalCount
    }
    // printing the data from the array totalCount using for loop
    for (int j=MIN_ROLL; j<=MAX_ROLL; j++)
    {
        cout<<j<<" was rolled "<< totalCount[j]<<" times"<< endl;
    }
    
    return 0;
}