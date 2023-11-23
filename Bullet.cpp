#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction, float speed, int damage)
    : damage(damage) {
    shape.setRadius(5);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(position);
    velocity = direction * speed;
}

void Bullet::update(float deltaTime) {
    shape.move(velocity * deltaTime);
}

void Bullet::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::Vector2f Bullet::getPosition() const {
    return shape.getPosition();
}
