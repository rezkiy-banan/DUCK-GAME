#pragma once
#include <SFML/Graphics.hpp>

class Weapon {
public:
    Weapon(int damage, float range);

    int getDamage() const;
    float getRange() const;

    virtual void fire(sf::Vector2f position, sf::Vector2f direction) = 0;

protected:
    int damage;
    float range;
};
