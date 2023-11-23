#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(sf::Vector2f position, sf::Vector2f direction, float speed, int damage);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;  // Make this function const
    sf::Vector2f getPosition() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    int damage;
};
