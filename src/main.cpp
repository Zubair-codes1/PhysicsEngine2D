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

            else if (auto* key = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (key->button == sf::Mouse::Button::Left) {

                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    shape.setPosition(sf::Vector2f((float) mousePosition.x - radius, (float) mousePosition.y - radius));
                }
                
            }
        }

        window.clear();

        window.draw(shape);
        std::cout << shape.getPosition().x << " " << shape.getPosition().y << std::endl;
        window.display();
    }

    return 0;
}