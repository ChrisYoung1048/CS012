#include <iostream>

using namespace std;

#include "Character.h"
#include "Wizard.h"

Wizard::Wizard(const string &n, 
                    double h, double a,
                    int rank) :
Character(WIZARD, n, h, a) , rank(rank) {}

void Wizard::attack(Character &c) {
    if (c.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(c);
        double damageTaken = attackStrength * ((double)rank / opp.rank);
        opp.damage(damageTaken);
        cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
        cout << opp.getName() << " takes " << damageTaken << " damage." << endl;
    } else {
        double damageTaken = attackStrength;
        c.damage(damageTaken);
        cout << "Wizard " << name << " attacks " << c.getName() << " --- POOF!!" << endl;
        cout << c.getName() << " takes " << damageTaken << " damage." << endl;
    }
}