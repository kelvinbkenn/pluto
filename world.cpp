#include "world.hpp"

void World::update(float dt) {
    for (Body& body : bodies) {

        body.velocity += global_acceleration * dt;
        body.position += body.velocity * dt;
    }
}

void World::add_body(Body body) { bodies.push_back(body); }
