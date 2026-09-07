#ifndef _VECTOR_3D_
#define _VECTOR_3D_

#include <iostream>
#include <cmath>

struct Vector3D {
    double x, y, z; // Coordinates (m)

    // Constructors
    Vector3D() : x(0), y(0), z(0) {} // Default creates origin vector
    Vector3D(int x_, int y_) : x(x_), y(y_), z(0) {} // 2D constructor
    Vector3D(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {} // 3D constructor    


    // Vector properties
    // Get magnitude of vector
    double mag() {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    };

    // Get direction of vector
    Vector3D unit() {
        double m = mag();
        if (m == 0) {
            return Vector3D(0,0,0);
        };
        return *this/m;
    };


    // Math operators
    // This vector + other vector 
    Vector3D operator+(const Vector3D& o) const { return Vector3D(x + o.x, y + o.y, z + o.z); };

    // This vector - other vector
    Vector3D operator-(const Vector3D& o) const { return Vector3D(x - o.x, y - o.y, z - o.z); };

    // This vector * scalar value
    Vector3D operator*(const double& s) const {
        return Vector3D(x*s, y*s, z*s);
    };

    // This vector / scalar value
    Vector3D operator/(const double& s) const {
        if (s == 0) {
            throw std::runtime_error("Vector divide by 0 error");
        };
        return Vector3D(x/s, y/s, z/s);
    };

    //  Print operator (prints coordinates)
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
        os << "(" << v.x << "," << v.y << "," << v.z << ")";
        return os;
    };
};

#endif