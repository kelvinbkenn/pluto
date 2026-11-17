#include "world.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3 Window");
    window.setFramerateLimit(60);

    sf::Clock clock;

    World world;
    world.add_body({});
    world.bodies[0].velocity = Vec2D(50, 50);

    sf::CircleShape body(5);

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();
        world.update(dt);

        body.setPosition({static_cast<float>(world.bodies[0].position.x), static_cast<float>(500-world.bodies[0].position.y)});

        window.clear(sf::Color::Black);
        window.draw(body);
        window.display();
    }

    return 0;
}
