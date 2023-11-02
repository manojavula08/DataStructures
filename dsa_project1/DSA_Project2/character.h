// preprocessor
#include <string>// importing the string library
using namespace std;
// creating the class called Character.
class Character{
    //instialized the key variables of the project 
    private:
    string name;
    string role;
    int hitPoints;
    int attackBonus;
    int damageBonus;
    int armorClass;

    public:
    // default Constructor
    Character();
    // setters
    void setName(string);
    void setRole(string);
    void setHitPoints(int);
    void setAttackBonus(int);
    void setDamageBonus(int);
    void setArmorClass(int);
    // getters
    int getHitPoints();
    string getName();
    string getRole();
    int getAttackBonus();
    int getDamageBonus();
    int getArmorClass();
    // functions
    void attack(Character &);
    void damage(int);
    int randomNumberGenerator(int);
    // print the output
    void print(ostream&);

};