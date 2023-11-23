
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

void Pistol::update(float deltaTime) {
    timeSinceLastShot += deltaTime;

    // Use std::remove_if followed by erase
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
        [&](const Bullet& bullet) {
            return bullet.getPosition().x < 0 ||
                bullet.getPosition().x > WINDOW_WIDTH ||
                bullet.getPosition().y < 0 ||
                bullet.getPosition().y > WINDOW_HEIGHT;
        }),
        bullets.end());

    // Update remaining bullets
    for (auto& bullet : bullets) {
        bullet.update(deltaTime);
    }
}

void Pistol::draw(sf::RenderWindow& window) {
    for (const auto& bullet : bullets) {
        bullet.draw(window);
    }
}

