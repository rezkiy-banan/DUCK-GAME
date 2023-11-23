#include "Game.hpp"
#include "Constants.hpp"

Game::Game()
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Duck Game Clone"),
    player1("player1.png", { 100, WINDOW_HEIGHT / 2 }, sf::Keyboard::W, sf::Keyboard::A, sf::Keyboard::S, sf::Keyboard::D, sf::Color::Blue),
    player2("player2.png", { WINDOW_WIDTH - 100, WINDOW_HEIGHT / 2 }, sf::Keyboard::Up, sf::Keyboard::Left, sf::Keyboard::Down, sf::Keyboard::Right, sf::Color::Red) {
}
void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    player1.handleInput();
    player2.handleInput();
}

void Game::update(float deltaTime) {
    player1.update(deltaTime);
    player2.update(deltaTime);
    updatePistols(deltaTime);
}

// В методе render() добавьте вызов renderPistols()

void Game::render() {
    window.clear();
    player1.draw(window);
    player2.draw(window);
    renderPistols();
    window.display();
}

// Имплементация новых методов

void Game::updatePistols(float deltaTime) {
    player1.getPistol().update(deltaTime);
    player2.getPistol().update(deltaTime);
}

void Game::renderPistols() {
    player1.getPistol().draw(window);
    player2.getPistol().draw(window);
}