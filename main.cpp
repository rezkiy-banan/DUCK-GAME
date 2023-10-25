#include <SFML/Graphics.hpp>

int main()
{
    // Создаем окно SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Перемещение персонажей");

    // Создаем персонажа (синий квадрат)
    sf::RectangleShape player1(sf::Vector2f(50, 50));
    player1.setFillColor(sf::Color::Blue);
    player1.setPosition(375, 275);

    // Создаем второго персонажа (красный квадрат)
    sf::RectangleShape player2(sf::Vector2f(50, 50));
    player2.setFillColor(sf::Color::Red);
    player2.setPosition(375, 325);

    // Основной цикл программы
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Обработка клавиш WASD для синего квадрата
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player1.move(0, -0.5); // Двигаем синий квадрат вверх
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player1.move(0, 0.5); // Двигаем синий квадрат вниз
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player1.move(-0.5, 0); // Двигаем синий квадрат влево
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player1.move(0.5, 0); // Двигаем синий квадрат вправо
        }

        // Обработка клавиш стрелок для красного квадрата
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            player2.move(0, -0.5); // Двигаем красный квадрат вверх
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player2.move(0, 0.5); // Двигаем красный квадрат вниз
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player2.move(-0.5, 0); // Двигаем красный квадрат влево
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player2.move(0.5, 0); // Двигаем красный квадрат вправо
        }

        // Очищаем окно
        window.clear();

        // Рисуем персонажей
        window.draw(player1);
        window.draw(player2);

        // Обновляем окно
        window.display();
    }

    return 0;
}
