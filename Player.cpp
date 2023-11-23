// Ваш файл Player.cpp
#include "Player.hpp"
#include "Constants.hpp"
#include <iostream>

const float Player::SPEED = PLAYER_SPEED;

Player::Player(const std::string& texturePath, const sf::Vector2f& position,
	const sf::Keyboard::Key up, const sf::Keyboard::Key left,
	const sf::Keyboard::Key down, const sf::Keyboard::Key right,
	const sf::Color& color)
	: moveUp(up), moveLeft(left), moveDown(down), moveRight(right),
	velocity(0.0f, 0.0f), isJumping(false), pistol() {
	health = MAX_HEALTH;

	if (!texture.loadFromFile(texturePath)) {
		std::cerr << "Failed to load player texture." << std::endl;
	}

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT));
	sprite.setPosition(position);

	if (!font.loadFromFile("font.ttf")) {
		std::cerr << "Failed to load font." << std::endl;
	}

	healthText.setString(std::to_string(health));
	healthText.setFont(font);
	healthText.setCharacterSize(20);
	healthText.setFillColor(sf::Color::White);
}

void Player::takeDamage(int amount) {
	health -= amount;

	if (health < 0) {
		health = 0;
	}

	healthText.setString(std::to_string(health));
}
void Player::fire() {
	getPistol().fire(getPosition(), sf::Vector2f(1.0f, 0.0f));
}

void Player::heal(int amount) {
	health += amount;

	if (health > MAX_HEALTH) {
		health = MAX_HEALTH;
	}

	healthText.setString(std::to_string(health));
}

int Player::getHealth() const {
	return health;
}

void Player::handleInput() {
	// Reset velocity
	velocity.x = 0.0f;

	// Check for key presses and update velocity
	if (sf::Keyboard::isKeyPressed(moveUp) && !isJumping) {
		jump();
	}

	if (sf::Keyboard::isKeyPressed(moveLeft)) {
		velocity.x -= SPEED;
	}

	if (sf::Keyboard::isKeyPressed(moveRight)) {
		velocity.x += SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		fire();
	}
}


void Player::jump() {
	if (!isJumping) {
		std::cout << "Jumping!" << std::endl;
		velocity.y = -JUMP_STRENGTH;
		isJumping = true;
	}
}

void Player::move(float dt) {
	sprite.move(velocity.x * dt, velocity.y * dt);

	// Получение ограничивающего прямоугольника спрайта
	sf::FloatRect bounds = sprite.getLocalBounds();

	// Проверка столкновения с "землей"
	if (sprite.getPosition().y + bounds.height >= WINDOW_HEIGHT) {
		sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - bounds.height);
		isJumping = false;
		velocity.y = 0;
	}
}

void Player::update(float deltaTime) {
	velocity.y += GRAVITY * deltaTime;

	// Ограничение скорости падения
	velocity.y = std::min(velocity.y, MAX_FALL_SPEED);

	sprite.move(velocity * deltaTime);

	// Ограничение позиции по Y
	float minY = WINDOW_HEIGHT - sprite.getLocalBounds().height;
	sprite.setPosition(sprite.getPosition().x, std::min(sprite.getPosition().y, minY));

	isJumping = sprite.getPosition().y < minY;

	health = std::max(0, std::min(health, MAX_HEALTH));

	healthText.setPosition(sprite.getPosition().x, sprite.getPosition().y - 20);
}





void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);

	if (health > MAX_HEALTH) {
		health = MAX_HEALTH;
	}

	if (health < -100) {
		health = MAX_HEALTH;
	}

	window.draw(healthText);
}

void Player::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}

sf::Vector2f Player::getPosition() const {
	return sprite.getPosition();
}
Pistol& Player::getPistol() {
	return pistol;
}

const Pistol& Player::getPistol() const {
	return pistol;
}
