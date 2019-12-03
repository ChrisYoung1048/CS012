#include <string>

using namespace std;

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior: public Character {
    private:
        string allegiance;

    public:
        Warrior(const string &, double, double, string);
        void attack(Character &opp) override; 
};

#endif