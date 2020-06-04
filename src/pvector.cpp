#include "../include/pvector.h"

void PVector::set (double x, double y, double z = 0.f) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void PVector::add (PVector vector) {
    this->x += vector.x;
    this->y += vector.y;
    this->z += vector.z;
}

void PVector::sub (PVector vector) {
    this->x -= vector.x;
    this->y -= vector.y;
    this->z -= vector.z;
}

void PVector::mul (PVector vector) {
    this->x *= vector.x;
    this->y *= vector.y;
    this->z *= vector.z;
}

void PVector::div (PVector vector) {
    this->x /= vector.x;
    this->y /= vector.y;
    this->z /= vector.z;
}

void PVector::addScalar (double scalar) {
    this->x += scalar;
    this->y += scalar;
    this->z += scalar;
}

void PVector::subScalar (double scalar) {
    this->x -= scalar;
    this->y -= scalar;
    this->z -= scalar;
}

void PVector::mulScalar (double scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
}

void PVector::divScalar (double scalar) {
    this->x /= scalar;
    this->y /= scalar;
    this->z /= scalar;
}

double PVector::getMagnitude () {
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

void PVector::setMagnitude (double newMagnitude) {
    normalize();
    mulScalar(newMagnitude);
}

void PVector::normalize () {
    this->set(this->x / this->getMagnitude(), this->y / this->getMagnitude(), this->z / this->getMagnitude());
}



