using namespace std;

#include "Character.h"

Character::Character(HeroType t, const string &n, 
                    double h, double a) :
type(t), name(n), health(h), attackStrength(a) {}

HeroType Character::getType() const {
    return type;
}

const string & Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return static_cast<int>(health);
}

void Character::setHealth(double h) {
    health = h;
}

void Character::damage(double d) {
    health -= d;
}

bool Character::isAlive() const {
    if (health > 0)
        return true;
    return false;
}


