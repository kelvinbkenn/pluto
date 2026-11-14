#pragma once

#include "vec2d.hpp"
#include <vector>

struct Body {
    double mass = 1;
    Vec2D position;
    Vec2D velocity;
};

class World {
public:
    Vec2D force;
    std::vector<Body> bodies;

    void update(double dt);
};
