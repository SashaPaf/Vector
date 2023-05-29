#include "vector.h"
#include <cmath>

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

double Vector::dotProduct(const Vector& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector Vector::add(const Vector& other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::subtract(const Vector& other) const {
    return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::multiply(double scalar) const {
    return Vector(x * scalar, y * scalar, z * scalar);
}

bool Vector::isCollinear(const Vector& other) const {
    double epsilon = 1e-8;  // A small value for floating-point comparison

    // Check if the vectors are parallel
    if (std::abs(x * other.y - y * other.x) < epsilon &&
        std::abs(x * other.z - z * other.x) < epsilon &&
        std::abs(y * other.z - z * other.y) < epsilon) {
        return true;
    }

    return false;
}

bool Vector::isOrthogonal(const Vector& other) const {
    double epsilon = 1e-8;  // A small value for floating-point comparison

    // Check if the dot product is zero
    if (std::abs(dotProduct(other)) < epsilon) {
        return true;
    }

    return false;
}



