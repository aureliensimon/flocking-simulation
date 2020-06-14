#ifndef PVECTOR_H
#define PVECTOR_H

#include <iostream>
#include <math.h>

using namespace std;

class PVector {
    public :
        PVector() : x(0.f), y(0.f), z(0.f) {}
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
        void limit(double);
        static PVector diff(PVector, PVector);
        double dist(PVector);
        int compare(PVector);

        // Magnitude
        double getMagnitude();
        void setMagnitude(double);

        void normalize();
    protected :
        double x, y, z;
};

#endif