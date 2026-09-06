#ifndef _ELECTROMAGNETISM_
#define _ELECTROMAGNETISM_

#include "Vector3D.h"
#include "Charge.h"
#include <vector>

namespace Electromagnetism {
    const double k = 1; // Coulomb's constant placeholder

    Vector3D Force(const Charge& q1, const Charge& q2);
    Vector3D Force(const Charge& q1, const std::vector<Charge> charges);
    Vector3D FieldAt(const Vector3D r, const Charge& q);
    Vector3D FieldAt(const Vector3D r, const std::vector<Charge> charges); // Measurment of field (V/m or N/C)
};

#include "..\src\Electromagnetism.cpp"

#endif