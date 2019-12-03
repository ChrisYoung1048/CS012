#include <string>

using namespace std;

#ifndef WIZARD_H
#define WIZARD_H

class Wizard: public Character {
    private:
        int rank;

    public:
        Wizard(const string &, double, double, int);
        void attack(Character &opp) override; 
};

#endif