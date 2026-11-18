#pragma once

#include "vec2d.hpp"

#include <vector>
//#include <chrono>

//std::chrono::nanoseconds;
//std::chrono::microseconds;
//std::chrono::milliseconds;

struct Body {
public:
    float mass = 1;
    Vec2D position;
    Vec2D velocity;

    Body(float mass): mass(mass) {}
    Body(Vec2D pos): position(pos) {}
    Body(float mass, Vec2D pos): mass(mass), position(pos) {}
    Body(Vec2D pos, Vec2D vel): position(pos), velocity(vel) {}
    Body(float mass, Vec2D pos, Vec2D vel): mass(mass), position(pos), velocity(vel) {}
};

class World {
public:
    Vec2D global_acceleration;
    std::vector<Body> bodies;

    World(Vec2D acc): global_acceleration(acc) {}

    void update(float dt);
    void add_body(Body body);
};
