#include "Player.hpp"
#include "Constants.hpp"
#include <iostream>

const float Player::SPEED = PLAYER_SPEED;

Player::Player(const sf::Vector2f& position, const sf::Keyboard::Key up, const sf::Keyboard::Key left,
	const sf::Keyboard::Key down, const sf::Keyboard::Key right, const sf::Color& color)
	: moveUp(up), moveLeft(left), moveDown(down), moveRight(right), velocity(0.0f, 0.0f), isJumping(false)
{
	health = MAX_HEALTH;
	sprite.setFillColor(color);
	sprite.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
	sprite.setPosition(position);

	//healthBar.setSize(sf::Vector2f(50, 3));  // ��������� ������
	//healthBar.setFillColor(sf::Color::Green);

	//healthBarBackground.setSize(sf::Vector2f(50, 3));
	//healthBarBackground.setFillColor(sf::Color::Red);
	if (!font.loadFromFile("font.ttf")) {
		std::cerr << "Failed to load font." << std::endl;
	}
	healthText.setString(std::to_string(health));

	healthText.setFont(font);
	healthText.setCharacterSize(20); // ������ ������
	healthText.setFillColor(sf::Color::White); // ���� ������
	// ������� ������ ����� ����������� �����, ����� �� ��������� ���
}

void Player::takeDamage(int amount) {
	health -= amount;
	if (health < 0) {
		health = 0;
	}
	healthText.setString(std::to_string(health)); // ��������� ������ ������ � ������� �������� ��������
}

void Player::heal(int amount) {
	health += amount;
	if (health > MAX_HEALTH) {
		health = MAX_HEALTH;
	}
	healthText.setString(std::to_string(health)); // ��������� ������ ������ � ������� �������� ��������

}

int Player::getHealth() const {
	return health;
}



void Player::handleInput() {
	velocity.x = 0.0f;  // ���������, ��� �������� �� ��� X ��������������� � 0 ��� ������ ������

	if (sf::Keyboard::isKeyPressed(moveUp) && !isJumping) {
		jump();
	}
	if (sf::Keyboard::isKeyPressed(moveLeft)) {
		velocity.x -= SPEED;
	}
	if (sf::Keyboard::isKeyPressed(moveRight)) {
		velocity.x += SPEED;
	}
}
void Player::jump() {
	if (!isJumping) {
		std::cout << "Jumping!" << std::endl;  // �������� ��� ������
		velocity.y = -JUMP_STRENGTH;  // �������� ������ � ������������� ��������� (���������)
		isJumping = true;
	}
}


void Player::move(float dt) {
	

	sprite.move(velocity.x * dt, velocity.y * dt);

	// �������� ������������ � "������"
	if (sprite.getPosition().y + sprite.getSize().y >= WINDOW_HEIGHT) {
		sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - sprite.getSize().y);
		isJumping = false;
		velocity.y = 0;  // �������� ������������ �������� ����� ������� �����
	}
}


void Player::update(float deltaTime) {
	// ���������� ����������
	velocity.y += GRAVITY * deltaTime;

	// ������������ ������������ �������� �������
	if (velocity.y > MAX_FALL_SPEED) {
		velocity.y = MAX_FALL_SPEED;
	}

	// ���������� ������� ������
	sprite.move(velocity * deltaTime);

	// �������� �� �����
	if (sprite.getPosition().y >= WINDOW_HEIGHT - sprite.getSize().y) {
		sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - sprite.getSize().y);
		isJumping = false;
	}

	// ���������� ������� ������ ������������ ���������
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
//	healthBarBackground.setPosition(sprite.getPosition().x, sprite.getPosition().y - 10);  // 10 - ��� ���������� ��� ����������
//	healthBar.setSize(sf::Vector2f(((float)health/MAX_HEALTH), 5));
//	healthBar.setPosition(sprite.getPosition().x, sprite.getPosition().y - 10);

//	window.draw(healthBarBackground);
//	window.draw(healthBar);
	window.draw(healthText);

}


void Player::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}

sf::Vector2f Player::getPosition() const {
	return sprite.getPosition();
}

