#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const sf::Vector2f& position, const sf::Keyboard::Key up, const sf::Keyboard::Key left,
        const sf::Keyboard::Key down, const sf::Keyboard::Key right, const sf::Color& color);

    void handleInput();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;
    void move(float dt);
private:
    sf::RectangleShape sprite;
    sf::Vector2f velocity;

    sf::Keyboard::Key moveUp;
    sf::Keyboard::Key moveLeft;
    sf::Keyboard::Key moveDown;
    sf::Keyboard::Key moveRight;
    const float GRAVITY = 50.0f; // или любое другое значение, которое вам подходит
    float accelerationY = 0.0f;
    const float MAX_FALL_SPEED = 20.0f;
    static const float SPEED;
};

