#include "world.hpp"

void World::update(double dt) {
    for (Body& body : bodies) {
        Vec2D acc(0, -9.81);

        body.velocity += acc * dt;
        body.position += body.velocity * dt;
    }
}

void World::update(float dt) {
    for (Body& body : bodies) {
        Vec2D acc(0, -25);

        body.velocity += acc * dt;
        body.position += body.velocity * dt;
    }
}

void World::add_body(Body body) { bodies.push_back(body); }
