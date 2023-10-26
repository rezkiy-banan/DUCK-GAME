#include "Player.hpp"
#include "Constants.hpp"
#include <iostream>

const float Player::SPEED = PLAYER_SPEED;

Player::Player(const sf::Vector2f& position, const sf::Keyboard::Key up, const sf::Keyboard::Key left,
    const sf::Keyboard::Key down, const sf::Keyboard::Key right, const sf::Color& color)
    : moveUp(up), moveLeft(left), moveDown(down), moveRight(right), velocity(0.0f, 0.0f) {
    sprite.setFillColor(color);
    sprite.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
    sprite.setPosition(position);
}

void Player::handleInput() {
    velocity.x = 0.0f;
    velocity.y = 0.0f;

    if (sf::Keyboard::isKeyPressed(moveUp)) {
        velocity.y -= SPEED;
    }
    if (sf::Keyboard::isKeyPressed(moveDown)) {
        velocity.y += SPEED;
    }
    if (sf::Keyboard::isKeyPressed(moveLeft)) {
        velocity.x -= SPEED;
    }
    if (sf::Keyboard::isKeyPressed(moveRight)) {
        velocity.x += SPEED;
    }
}
void Player::move(float dt) {
    // Обработка ввода для горизонтального движения
    if (sf::Keyboard::isKeyPressed(moveLeft)) {
        velocity.x = -SPEED;
    }
    else if (sf::Keyboard::isKeyPressed(moveRight)) {
        velocity.x = SPEED;
    }
    else {
        velocity.x = 0.0f;
    }

    // Применение гравитации
    accelerationY += GRAVITY;
    velocity.y += accelerationY * dt;

    // Простая проверка столкновения с "землей"
    if (sprite.getPosition().y + sprite.getSize().y > WINDOW_HEIGHT) {
        sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - sprite.getSize().y);
        accelerationY = 0;
        velocity.y = 0;
    }

    // Обновление положения спрайта
    sprite.move(0, velocity.y * dt);
    std::cout << "Acceleration Y: " << accelerationY << ", Velocity Y: " << velocity.y << std::endl;
}

void Player::update(float deltaTime) {
    sprite.move(velocity * deltaTime);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::setPosition(const sf::Vector2f& position) {
    sprite.setPosition(position);
}

sf::Vector2f Player::getPosition() const {
    return sprite.getPosition();
}

