#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const sf::Vector2f& position, const sf::Keyboard::Key up, const sf::Keyboard::Key left,
        const sf::Keyboard::Key down, const sf::Keyboard::Key right, const sf::Color& color);

    void handleInput();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void jump();
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;
    void move(float dt);
    void takeDamage(int amount);
    void heal(int amount);
    int getHealth() const;

private:
    sf::Text healthText;
    sf::Font font;
    int health;
    sf::RectangleShape healthBar;
    sf::RectangleShape healthBarBackground;
    const int MAX_HEALTH = 100;
    sf::RectangleShape sprite;
    sf::Vector2f velocity;
    bool isJumping = false;
    const float JUMP_STRENGTH = 1000.0f;
    sf::Keyboard::Key moveUp;
    sf::Keyboard::Key moveLeft;
    sf::Keyboard::Key moveDown;
    sf::Keyboard::Key moveRight;
    const float GRAVITY = 10000.0f;
    float accelerationY = 0.0f;
    const float MAX_FALL_SPEED = 400.0f;
    static const float SPEED;
};
