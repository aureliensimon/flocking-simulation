#ifndef PVECTOR_H
#define PVECTOR_H

#include <iostream>
#include <math.h>

using namespace std;

class PVector {
    public :
        PVector() {}
        PVector(double xinit, double yinit, double zinit = 0.f) : x(xinit), y(yinit), z(zinit) {}
        ~PVector() {}

        // Getters
        double getX() const { return x; }
        double getY() const { return y; }
        double getZ() const { return z; }
        
        // Setters
        void set(double, double, double = 0.f);

        // Operations
        void add(PVector);
        void sub(PVector);
        void mul(PVector);
        void div(PVector);
        void addScalar(double);
        void subScalar(double);
        void mulScalar(double);
        void divScalar(double);

        // Magnitude
        double getMagnitude();
        void setMagnitude(double);

        void normalize();
    protected :
        double x, y, z;
};

#endif