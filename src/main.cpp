#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML setup");
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

        shape.setRadius(radius);

        window.draw(shape);

        //radius--;
        sf::Vector2f pos = shape.getPosition();
        pos += sf::Vector2{10.f, 10.f};
        shape.setPosition(pos);
        sf::sleep(pauseTime);
        window.display();
    }

    return 0;
}