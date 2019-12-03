#include <iostream>

using namespace std;

#include "Character.h"
#include "Warrior.h"

Warrior::Warrior(const string &n, 
                    double h, double a,
                    string allegiance) :
Character(WARRIOR, n, h, a) , allegiance(allegiance) {}

void Warrior::attack(Character &c) {
    if (c.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(c);
        if (allegiance == opp.allegiance) {
            cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        } else {
            double damageTaken = (health / MAX_HEALTH) * attackStrength;
            c.damage(damageTaken);
            cout << "Warrior " << name << " attacks " << c.getName() << " --- SLASH!!" << endl;
            cout << c.getName() << " takes " << damageTaken << " damage." << endl;
        }
    } else {
        double damageTaken = (health / MAX_HEALTH) * attackStrength;
        c.damage(damageTaken);
        cout << "Warrior " << name << " attacks " << c.getName() << " --- SLASH!!" << endl;
        cout << c.getName() << " takes " << damageTaken << " damage." << endl;
    }
}