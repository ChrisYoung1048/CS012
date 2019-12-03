#include <iostream>

using namespace std;

#include "Character.h"
#include "Elf.h"

Elf::Elf(const string &n, 
                    double h, double a,
                    string allegiance) :
Character(ELF, n, h, a) , allegiance(allegiance) {}

void Elf::attack(Character &c) {
    if (c.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(c);
        if (allegiance == opp.allegiance) {
            cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << allegiance << " family." << endl;
        } else {
            double damageTaken = (health / MAX_HEALTH) * attackStrength;
            c.damage(damageTaken);
            cout << "Elf " << name << " shoots an arrow at " << c.getName() << " --- TWANG!!" << endl;
            cout << c.getName() << " takes " << damageTaken << " damage." << endl;
        }
    } else {
        double damageTaken = (health / MAX_HEALTH) * attackStrength;
        c.damage(damageTaken);
        cout << "Elf " << name << " shoots an arrow at " << c.getName() << " --- TWANG!!" << endl;
        cout << c.getName() << " takes " << damageTaken << " damage." << endl;
    }
}