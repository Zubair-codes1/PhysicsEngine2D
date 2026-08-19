#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML setup");
    window.setFramerateLimit(60);

    // mouse
    sf::Mouse::Button mouseLeftButton(sf::Mouse::Button::Left);
    float radius = 100.f;
    float position_change = 5;
    sf::CircleShape shape(radius, 50.f);
    
    shape.setOrigin({shape.getRadius(), shape.getRadius()});
    shape.setPosition({shape.getRadius(), shape.getRadius()});


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

            else if (auto* key = event->getIf<sf::Event::KeyPressed>()) {
                if (key->code == sf::Keyboard::Key::Q) {
                    shape.setRadius(shape.getRadius() * 1.5);
                }

                else if (key->code == sf::Keyboard::Key::W) {
                    shape.setRadius(shape.getRadius() / 1.5);
                }

                else if (key->code == sf::Keyboard::Key::A) {
                    shape.setFillColor(sf::Color::Cyan);
                }
            }
        }

        window.clear();

        window.draw(shape);

        if (shape.getPosition().y + radius == window.getSize().y) {
            position_change *= -1;
        }

        sf::Vector2f position = shape.getPosition();
        shape.setPosition(sf::Vector2f{position.x, position.y + position_change});

        window.display();
    }

    return 0;
}