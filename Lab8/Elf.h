#include <string>

using namespace std;

#ifndef ELF_H
#define ELF_H

class Elf: public Character {
    private:
        string allegiance;

    public:
        Elf(const string &, double, double, string);
        void attack(Character &opp) override; 
};

#endif