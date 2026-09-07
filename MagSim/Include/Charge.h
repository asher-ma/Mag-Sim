#ifndef _CHARGE_
#define _CHARGE_

#include "Vector3D.h"

class Charge {
    public :
        Vector3D r; // Position vector
        double Q; // Measurment of charge in coulombs (C)

        // Constructors
        Charge() : r(Vector3D()), Q(0) {}
        Charge(Vector3D r_, double Q_) : r(r_), Q(Q_) {}
};

#endif