#include "world.hpp"
#include <chrono>
#include <iostream>
#include <thread>

using Clock = std::chrono::steady_clock;

int main() {
    World world;

    world.bodies.push_back({});

    constexpr auto frame = std::chrono::nanoseconds(1'000'000'000 / 60);

    auto start = Clock::now();
    auto next = start;

    while (world.bodies[0].position.y > -50) {
        auto end = Clock::now();
        std::chrono::duration<double> dt = end - start;
        world.update(dt.count());

        start = end;

        next += frame;
        std::this_thread::sleep_until(next);
    }
}
