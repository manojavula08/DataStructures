#include "character.h"// importing the character.h class in .cpp file
#include <iostream> // the library that provides input and output functionality using streams.
#include <cstdlib> // header file that contains a set of general-purpose functions
#include <string> // importing the string library
using namespace std;// we use namespace std without having to prefix with the std:: namespace qualifier.

// instializing the values for the variables using default constructer 
Character::Character(){
    name = "";
    role = "";
    attackBonus = 0;
    hitPoints = 0;
    damageBonus = 0;
    armorClass=0;
}
// We have to use Character:: before each method definition to specify that this method belongs to class Character 
// printing the Character summary by calling the ostream method.
void Character::print(ostream& os){
    os<<"Character summary"<<endl<<"-----------------"<<endl;
    os << name <<" the "<< role<< endl;
    os << hitPoints << endl;
    os << attackBonus << endl;
    os << damageBonus << endl;
    os << armorClass << endl;
}

// instializing the getter for health, role, name, attackBonus, damageBonus, armourClas.
string Character::getName(){
    return name;
}
string Character::getRole(){
    return role;
}
int Character:: getHitPoints(){
    return hitPoints;
}
int Character:: getAttackBonus(){
    return attackBonus;
}
int Character:: getDamageBonus(){
    return damageBonus;
}
int Character:: getArmorClass(){
    return armorClass;
}
// instializing the setter for health, role, name, attackBonus, damageBonus, armourClas.
void Character::setName(string name){
    this->name = name;
}
void Character::setRole(string role){
    this->role = role;
}
void Character::setHitPoints(int hitPoints){
    this->hitPoints = hitPoints;
}

void Character::setArmorClass(int armorClass){
    this->armorClass = armorClass;
}
void Character::setAttackBonus(int attackBonus){
    this->attackBonus = attackBonus;
}
void Character::setDamageBonus(int damageBonus){
    this->damageBonus = damageBonus;
}
// random number generator function
int Character:: randomNumberGenerator(int number){
    int randomGenerator = (rand()%number)+1;
    return randomGenerator;
}
// initallizing the damage function for deducting the amount of hitPoints from the opponent.
void Character::damage(int amount){
    int lostDamage = getHitPoints() - amount;
    setHitPoints(lostDamage);// by using setter updating the new hitPoints of the opponent.
    if (getHitPoints()<0){
        setHitPoints(0);
    }
    cout<< getName()<<" has "<<getHitPoints()<<" hit points remaining"<<endl;// printing the data of hitPoints after the deduction
}
// creating the attack function for the battle between two user's characters.
void Character::attack(Character &otherCharacter){
    int random1 = randomNumberGenerator(20);// calling for the random number between 1 to 20.
    int playerAttack = random1 + getAttackBonus();
    cout<<"\n"<<"\n"<<getName()<< " attacks!"<<endl;
    if (playerAttack >= otherCharacter.getArmorClass())//checking the attackPoints are greather than opponent armourClass or not.
    {
        int attackHits = randomNumberGenerator(10);// calling for the random number between 1 to 10.
        int totalDamage = getDamageBonus() + attackHits; // adding the attackHits and damageBonus of attacker to deduct the opponents hitPoints.
        // printing the attack roll's attackBonus and playerAttack and it HIT.
        cout<<"Attack Roll: "<<random1<<" + "<< getAttackBonus()<<" = "<<playerAttack<<" --> HIT!"<<endl;
        cout<<"Damage: "<<attackHits <<" + "<< getDamageBonus() <<" = "<<totalDamage<<endl;
        otherCharacter.damage(totalDamage);//passing the totalDamage to the damage function.
    }
    else{
        // printing the attack roll's attackBonus and playerAttack and it MISS.
        cout<<"Attack Roll: "<<random1<<" + "<< getAttackBonus()<<" = "<<playerAttack<<" --> MISS!"<<endl;
    }
}