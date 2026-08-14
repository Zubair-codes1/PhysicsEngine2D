#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML setup");
    window.setFramerateLimit(60);

    // mouse
    sf::Mouse::Button mouseLeftButton(sf::Mouse::Button::Left);
    float radius = 100.f;
    sf::CircleShape shape(radius, 50.f);
    sf::Time pauseTime = sf::seconds(1);
    shape.setFillColor(sf::Color::Green);

    while(window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();

        if (sf::Mouse::isButtonPressed(mouseLeftButton)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition();
            shape.setPosition(sf::Vector2f(mousePosition.x, mousePosition.y));
            window.draw(shape);
        }

        window.draw(shape);
        window.display();
    }

    return 0;
}