#pragma once

#include "vec2d.hpp"

#include <cstdint>
#include <vector>

enum TIME_UNIT {
    NANO,
    MICRO,
    MILLI,
    SECONDS,
};

template<TIME_UNIT unit>
struct TIME {
    const uint64_t duration;

    constexpr double seconds() const {
        switch (unit) {
            case NANO: return duration / 1e9;
            case MICRO: return duration / 1e6;
            case MILLI: return duration / 1e3;
            case SECONDS: return duration;
        }
    }
};

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

    void add_body(Body body);

    void update(TIME<TIME_UNIT::NANO> time);
    void update(TIME<TIME_UNIT::MICRO> time);
    void update(TIME<TIME_UNIT::MILLI> time);
    void update(TIME<TIME_UNIT::SECONDS> time);
};
