// Pistol.hpp
#pragma once
#include "Weapon.hpp"
#include "Bullet.hpp"

class Pistol : public Weapon {
public:
    Pistol();
    void fire(sf::Vector2f position, sf::Vector2f direction) override;
    void update(float deltaTime, sf::Keyboard::Key fireKey, sf::Vector2f playerPosition);  // Remove const here
    void draw(sf::RenderWindow& window);

private:
    float fireRate;
    float timeSinceLastShot;
    std::vector<Bullet> bullets;
};