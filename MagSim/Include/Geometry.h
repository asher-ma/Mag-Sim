#ifndef _GEOMETRY_
#define _GEOMETRY_

#include "Vector3D.h"

// Geometry namespace: includes geometric functions that act between objects
// Geometry header
namespace Geometry {
    double dist(Vector3D r1, Vector3D r2); // Gets distance between two vectors
    Vector3D dir(Vector3D r1, Vector3D r2); // Gets direction from v1 to v2
};

#include "../src/Geometry.cpp"

#endif