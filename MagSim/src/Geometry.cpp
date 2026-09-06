#include "Geometry.h"

// Geometry implementation
double Geometry::dist(Vector3D r1, Vector3D r2) {
    return sqrt(pow(r1.x - r2.x, 2) + pow(r1.y - r2.y, 2) + pow(r1.z - r2.z, 2));
};

Vector3D Geometry::dir(Vector3D r1, Vector3D r2) {
    return r2 - r1;
};
