#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <ostream>

class Vec2D {
public:
    double x, y;

    Vec2D(double x, double y) : x(x), y(y) {}
    Vec2D() : x(0), y(0) {}
    Vec2D(const sf::Vector2f& other) : x(other.x), y(other.y) {}

    Vec2D operator+ (const Vec2D& other) const {
        return {x + other.x, y + other.y};
    }

    Vec2D operator- (const Vec2D& other) const {
        return {x - other.x, y - other.y};
    }

    Vec2D& operator+= (const Vec2D& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2D& operator-= (const Vec2D& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2D operator* (const double scalar) {
        return { scalar * x, scalar * y};
    }

    double operator* (const Vec2D& other) {
        return (x * other.x) + (y * other.y);
    }

    Vec2D operator/ (const double scalar) {
        return {(x / scalar), (y / scalar)};
    }

    Vec2D cross (const Vec2D& other) {

    }

    Vec2D operator-() const { return Vec2D(-x, -y); }

    friend std::ostream& operator<< (std::ostream& os, const Vec2D& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }

    operator sf::Vector2<float>() const {
        return sf::Vector2<float>(static_cast<float>(x), static_cast<float>(y));
    }

};
