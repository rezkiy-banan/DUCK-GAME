#include "Game.hpp"
#include "Constants.hpp"
#include <iostream>

Game::Game()
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Duck Game Clone"),
    player1("player1.png", { 100, WINDOW_HEIGHT / 2 }, sf::Keyboard::W, sf::Keyboard::A, sf::Keyboard::S, sf::Keyboard::D, sf::Color::Blue),
    player2("player2.png", { WINDOW_WIDTH - 100, WINDOW_HEIGHT / 2 }, sf::Keyboard::Up, sf::Keyboard::Left, sf::Keyboard::Down, sf::Keyboard::Right, sf::Color::Red) {
}

void Game::run() {
    sf::Clock clock;
    try {
        while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        processEvents();
        update(deltaTime);
        render();
    }
    }
    catch (const std::exception& e) {

        std::cerr << "Îøèáêà: " << e.what() << std::endl;

    }

}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                // Call fire on non-const object
                player1.getPistol().fire(player1.getPosition(), sf::Vector2f(1.0f, 0.0f));
            }

            if (event.key.code == sf::Keyboard::Return) {
                // Call fire on non-const object
                player2.getPistol().fire(player2.getPosition(), sf::Vector2f(1.0f, 0.0f));
            }
        }
    }
}


void Game::update(float deltaTime) {

    std::cout << player1.getPosition().x << std::endl;
    player1.update(deltaTime);
    std::cout << player1.getPosition().x << std::endl;
    player2.update(deltaTime);

    player1.getPistol().update(deltaTime);
    player2.getPistol().update(deltaTime);

}

void Game::render() {
    window.clear();
    player1.draw(window);
    player2.draw(window);
    window.display();
}
