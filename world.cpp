#include "world.hpp"

void World::update(TIME<TIME_UNIT::NANO> time) {
    for (Body& body : bodies) {
        body.velocity += global_acceleration * time.seconds();
        body.position += body.velocity * time.seconds();
    }
}

void World::update(TIME<TIME_UNIT::MICRO> time) {
    for (Body& body : bodies) {
        body.velocity += global_acceleration * time.seconds();
        body.position += body.velocity * time.seconds();
    }
}

void World::update(TIME<TIME_UNIT::MILLI> time) {
    for (Body& body : bodies) {
        body.velocity += global_acceleration * time.seconds();
        body.position += body.velocity * time.seconds();
    }
}

void World::update(TIME<TIME_UNIT::SECONDS> time) {
    for (Body& body : bodies) {
        body.velocity += global_acceleration * time.seconds();
        body.position += body.velocity * time.seconds();
    }
}

void World::add_body(Body body) { bodies.push_back(body); }
