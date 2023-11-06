/*
    ProjectName: FIGHT!
*/

#include <iostream>// the library that provides input and output functionality using streams.
#include<cstdlib>// header file that contains a set of general-purpose functions
#include "character.h"// importing the character.h class in .cpp file
using namespace std;// we use namespace std without having to prefix with the std:: namespace qualifier.

void getCharacter(Character&);
// initalizing the global variable;
int length = 0;// lenght is used to promt the two players as incrementing the after the player1.
/* --------------------------------------
    main: 
    return: returns a program has completed its task without errors
-----------------------------------------*/

int main(){

    srand(time(NULL));// seeding the random with current time for different iteration every time.
    cout<<"Simulated Combat:"<<endl;
    // creating the variable c1 for class Character
    Character c1;
    // creating the variable c2 for class Character
    Character c2;
    // Prompt the user for c1's attributes
    getCharacter(c1);
    // 
    c1.print(cout);
    // Prompt the user for c2's attributes
    getCharacter(c2);
    c2.print(cout);
    // looping the attack till the one user get lost.
    while(c1.getHitPoints()>0 && c2.getHitPoints()>0){
        c1.attack(c2);
        c2.attack(c1);
    }
    // checking the wheather user1 has hitPoints greater than 0 or not
    if(c1.getHitPoints()>0)
    {
        cout<<"\n"<<"\n"<<c1.getName()<<" wins!";
    }else if(c2.getHitPoints()>0)// checking the wheather user2 has hitPoints greater than 0 or not
    {
        cout<<"\n"<<"\n"<<c2.getName()<< " wins!";
    }else // if both conditions are failed that it's draw.
    {
        cout<<"\n"<<"\n"<<"It's a Draw";
    }
    

    return 0;
}
// getCharacter function are used to prompt the input from user.
void getCharacter(Character & theCharacter){
    string name;
    string role;
    int hitPoints;
    int attackBonus;
    int damageBonus;
    int armorClass;
    length = length + 1;
    if(length == 1){
        cout << "First character name?";
    }
    else if(length == 2){
        cout<< "Second character name?";
    }
    cin >> name; // prompting the name from user
    theCharacter.setName(name);
    cout<<theCharacter.getName()<<"'s role?";
    cin>>role;// prompting the role from user
    theCharacter.setRole(role);
    cout<<theCharacter.getName()<<" the "<<theCharacter.getRole()<<"'s hit points?";
    cin>>hitPoints;// prompting the hitPoints from user
    theCharacter.setHitPoints(hitPoints);
    cout<<theCharacter.getName()<<" the "<<theCharacter.getRole()<<"'s attack bonus?";
    cin>>attackBonus;// prompting the attackBonus from user
    theCharacter.setAttackBonus(attackBonus);
    cout<<theCharacter.getName()<<" the "<<theCharacter.getRole()<<"'s damage bonus?";
    cin>>damageBonus;// prompting the damageBonus from user
    theCharacter.setDamageBonus(damageBonus);
    cout<<theCharacter.getName()<<" the "<<theCharacter.getRole()<<"'s armor class?";
    cin>>armorClass;// prompting the armorClass from user
    theCharacter.setArmorClass(armorClass);

}
