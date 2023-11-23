#include "Weapon.hpp"

Weapon::Weapon(int damage, float range)
    : damage(damage), range(range) {
}

int Weapon::getDamage() const {
    return damage;
}

float Weapon::getRange() const {
    return range;
}