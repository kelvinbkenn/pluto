#include "world.hpp"

int main() {
    World world({0, -25});

    world.add_body({{0, 50}, {50, 50}});

    return 0;
}
