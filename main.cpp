#include <SFML/Graphics.hpp>

int main()
{
    // ������� ���� SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "����������� ����������");

    // ������� ��������� (����� �������)
    sf::RectangleShape player1(sf::Vector2f(50, 50));
    player1.setFillColor(sf::Color::Blue);
    player1.setPosition(375, 275);

    // ������� ������� ��������� (������� �������)
    sf::RectangleShape player2(sf::Vector2f(50, 50));
    player2.setFillColor(sf::Color::Red);
    player2.setPosition(375, 325);

    // �������� ���� ���������
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ��������� ������ WASD ��� ������ ��������
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player1.move(0, -0.5); // ������� ����� ������� �����
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player1.move(0, 0.5); // ������� ����� ������� ����
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player1.move(-0.5, 0); // ������� ����� ������� �����
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player1.move(0.5, 0); // ������� ����� ������� ������
        }

        // ��������� ������ ������� ��� �������� ��������
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            player2.move(0, -0.5); // ������� ������� ������� �����
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player2.move(0, 0.5); // ������� ������� ������� ����
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player2.move(-0.5, 0); // ������� ������� ������� �����
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player2.move(0.5, 0); // ������� ������� ������� ������
        }

        // ������� ����
        window.clear();

        // ������ ����������
        window.draw(player1);
        window.draw(player2);

        // ��������� ����
        window.display();
    }

    return 0;
}
