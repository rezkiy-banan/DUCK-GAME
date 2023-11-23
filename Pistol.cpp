
#include "Pistol.hpp"
#include "Constants.hpp"

Pistol::Pistol()
    : Weapon(10, 100), fireRate(0.5f), timeSinceLastShot(0.0f) {
}

void Pistol::fire(sf::Vector2f position, sf::Vector2f direction) {
    if (timeSinceLastShot >= fireRate) {
        bullets.emplace_back(position, direction, 500.0f, getDamage());
        timeSinceLastShot = 0.0f;
    }
}

void Pistol::update(float deltaTime, sf::Keyboard::Key fireKey, sf::Vector2f playerPosition) {
    timeSinceLastShot += deltaTime;

    if (sf::Keyboard::isKeyPressed(fireKey)) {
        fire(playerPosition, sf::Vector2f(1.0f, 0.0f));
    }

    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
        [&](const Bullet& bullet) {
            return bullet.getPosition().x < 0 ||
                bullet.getPosition().x > WINDOW_WIDTH ||
                bullet.getPosition().y < 0 ||
                bullet.getPosition().y > WINDOW_HEIGHT;
        }),
        bullets.end());

    for (auto& bullet : bullets) {
        bullet.update(deltaTime);
    }
}

void Pistol::draw(sf::RenderWindow& window) {
    for (const auto& bullet : bullets) {
        bullet.draw(window);
    }
}

