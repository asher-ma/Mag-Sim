#ifndef _PHYSICS_OBJECT_
#define _PHYSICS_OBJECT_

#include "Vector3D.h"

class PhysicsObject {
    public :
        Vector3D pos; // Position vector
        double charge; // Measurment of charge in coulombs (C)

        // Constructors
        PhysicsObject() : pos(Vector3D()), charge(0) {}
        PhysicsObject(Vector3D r, double Q) : pos(r), charge(Q) {}
};

#endif // Physics object