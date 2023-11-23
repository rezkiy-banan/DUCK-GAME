#pragma once
#include <SFML/Graphics.hpp>
#include "Pistol.hpp"
enum class Direction {
    Left,
    Right
};

class Player {
public:
    Player(const std::string& texturePath, const sf::Vector2f& position,
        const sf::Keyboard::Key up, const sf::Keyboard::Key left,
        const sf::Keyboard::Key down, const sf::Keyboard::Key right,
        const sf::Color& color, const sf::Keyboard::Key fireKey);
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
    Pistol& getPistol();
    const Pistol& getPistol() const;
    void fire(sf::Vector2f direction);
    Direction direction;

private:

    sf::Text healthText;
    sf::Font font;
    int health;
    Pistol pistol;
    sf::RectangleShape healthBar;
    sf::RectangleShape healthBarBackground;
    const int MAX_HEALTH = 100;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    bool isJumping = false;
    const float JUMP_STRENGTH = 3000.0f;
    sf::Keyboard::Key moveUp;
    sf::Keyboard::Key moveLeft;
    sf::Keyboard::Key moveDown;
    sf::Keyboard::Key moveRight;
    sf::Keyboard::Key fireKey;
    const float GRAVITY = 10000.0f;
    float accelerationY = 0.0f;
    const float MAX_FALL_SPEED = 400.0f;
    static const float SPEED;
};