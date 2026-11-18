#include "world.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowEnums.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 800}), "PLUTO Physics Engine", sf::Style::None);

    sf::Clock clock;

    World world;
    world.add_body({});

    world.bodies[0].position = Vec2D(5, 5);
    world.bodies[0].velocity = Vec2D(500, 500);

    sf::CircleShape body(5);

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();
        world.update(dt);

        body.setPosition({static_cast<float>(world.bodies[0].position.x), static_cast<float>(795-world.bodies[0].position.y)});

        window.clear(sf::Color::Black);
        window.draw(body);
        window.display();

        std::cout << world.bodies[0].position << "\n";
    }

    return 0;
}
