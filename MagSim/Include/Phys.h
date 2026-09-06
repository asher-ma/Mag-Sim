#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct Vector3D {
    double x{0}, y{0}, z{0}; // Coordinates (m)


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



// Geometry namespace: includes geometric functions that act between objects
// Geometry header
namespace Geometry {
    double dist(Vector3D r1, Vector3D r2); // Gets distance between two vectors
    Vector3D dir(Vector3D r1, Vector3D r2); // Gets direction from v1 to v2
};

// Geometry implementation
double Geometry::dist(Vector3D r1, Vector3D r2) {
    return sqrt(pow(r1.x - r2.x, 2) + pow(r1.y - r2.y, 2) + pow(r1.z - r2.z, 2));
};

Vector3D Geometry::dir(Vector3D r1, Vector3D r2) {
    return r2 - r1;
};
