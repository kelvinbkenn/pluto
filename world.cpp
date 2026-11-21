#include "world.hpp"

void World::update(float dt) {
    for (Body& body : bodies) {
        Vec2D acc(0, -250);

        body.velocity += acc * dt;
        body.position += body.velocity * dt;

        if (body.position.y < 5 && body.velocity.y < 0) {
            body.velocity.y *= -0.5;
            body.velocity.x *= 0.99999;
        }

        if (body.position.x > 795 && body.velocity.x > 0){
            body.velocity.x *= -0.5;
            body.velocity.y *= 0.99999;
        }

        if (body.position.x < 5 && body.velocity.x < 0) {
            body.velocity.x *= -0.5;
            body.velocity.y *= 0.99999;
        }

        if (body.position.y > 795 && body.velocity.y > 0) {
            body.velocity.y *= -0.5;
            body.velocity.x *= 0.99999;
        }
    }
}


void World::add_body(Body body) { bodies.push_back(body); }
