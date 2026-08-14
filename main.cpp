#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    RenderWindow window(VideoMode({800, 600}), "SFML setup");
    float radius = 100.f;
    CircleShape shape(radius, 50.f);
    Time pauseTime = seconds(1);
    shape.setFillColor(Color::Green);

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
        Vector2f pos = shape.getPosition();
        pos += Vector2{10.f, 10.f};
        shape.setPosition(pos);
        sleep(pauseTime);
        window.display();
    }

    return 0;
}