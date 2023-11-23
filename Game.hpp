#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"

class Player;
class Game {
public:
    Game();
    void run();

private:
    sf::Keyboard::Key player1FireKey;
    sf::Keyboard::Key player2FireKey;

    // Добавленные методы
    void updatePistols(float deltaTime);
    void processEvents();
    void update(float deltaTime);
    void render();
    
    void renderPistols();

    sf::RenderWindow window;
    Player player1;
    Player player2;
};
