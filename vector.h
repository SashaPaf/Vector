#ifndef VECTOR_H
#define VECTOR_H

class Vector {
public:
    double x;
    double y;
    double z;

    Vector(double x, double y, double z);

    double magnitude() const;
    double dotProduct(const Vector& other) const;
    Vector add(const Vector& other) const;
    Vector subtract(const Vector& other) const;
    Vector multiply(double scalar) const;

    bool isCollinear(const Vector& other) const; // Додано функцію перевірки колінеарності векторів
    bool isOrthogonal(const Vector& other) const; // Додано функцію перевірки ортогональності векторів
};

#endif // VECTOR_H
