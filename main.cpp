#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Constants.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Your Game Title");
    sf::Clock clock;

    Player player1(100.0f, 100.0f, sf::Color::Blue);
    Player player2(700.0f, 100.0f, sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        player1.move(dt);
        player2.move(dt);

        window.clear();
        player1.draw(window);
        player2.draw(window);
        window.display();
    }

    return 0;
}
