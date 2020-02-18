#include "vector2d.h"
#include <math.h>

Vector2D::Vector2D() {
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double a, double b) {
    x = a;
    y = b;
}

Vector2D Vector2D::add(Vector2D vect) {
    Vector2D newVect = Vector2D();

    newVect.x = x + vect.x;
    newVect.y = y + vect.y;

    return newVect;
}

Vector2D Vector2D::add(Vector2D v1, Vector2D v2) {
    Vector2D newVect = Vector2D();

    newVect.x = v1.x + v2.x;
    newVect.y = v1.y + v2.y;

    return newVect;
}

Vector2D Vector2D::subtract(Vector2D vect) {
    Vector2D newVect = Vector2D();

    newVect.x = x - vect.x;
    newVect.y = y - vect.y;

    return newVect;
}

Vector2D Vector2D::subtract(Vector2D v1, Vector2D v2) {
    Vector2D newVect = Vector2D();

    newVect.x = v1.x - v2.x;
    newVect.y = v2.y - v2.y;

    return newVect;
}

Vector2D Vector2D::mult(double scale) {
    Vector2D newVect = Vector2D();

    newVect.x = x * scale;
    newVect.y = y * scale;

    return newVect;
}

Vector2D Vector2D::mult(Vector2D vect, double scale) {
    Vector2D newVect = Vector2D();

    newVect.x = vect.x * scale;
    newVect.y = vect.y * scale;

    return newVect;
}

Vector2D Vector2D::div(double denom) {
    Vector2D newVect = Vector2D();

    newVect.x = x / denom;
    newVect.y = y / denom;

    return newVect;
}

Vector2D Vector2D::div(Vector2D vect, double denom) {
    Vector2D newVect = Vector2D();

    newVect.x = vect.x / denom;
    newVect.y = vect.y / denom;

    return newVect;
}

double Vector2D::dot(Vector2D vect) {
    double product = 0;

    product = x*vect.x + y*vect.y;

    return product;
}

double Vector2D::dot(Vector2D v1, Vector2D v2) {
    double product = 0;

    product = v1.x*v2.x + v1.y*v2.y;

    return product;
}

double Vector2D::norm() {
    double norm = 0;

    norm = sqrt(x*x + y*y);

    return norm;
}

double Vector2D::norm(Vector2D vect) {
    double norm = 0;

    norm = sqrt(vect.x*vect.x + vect.y*vect.y);

    return norm;
}

bool Vector2D::equals(Vector2D vect) {
    if (x == vect.x && y == vect.y) {
        return true;
    }
    else return false;
}

bool Vector2D::equals(Vector2D v1, Vector2D v2) {
    if (v1.x == v2.x && v1.y == v2.y) {
        return true;
    }
    else return false;
}