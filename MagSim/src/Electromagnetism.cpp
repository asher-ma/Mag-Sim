#include "Electromagnetism.h"
#include "Geometry.h"

Vector3D Electromagnetism::Force(const Charge& q1, const Charge& q2){
    Vector3D ur12 = Geometry::dir(q2.r, q1.r); // Unit vector for direction from q2 to q1
    double r = Geometry::dist(q1.r, q2.r); // Distance between charges
    
    // Coulombs law: k((q1*q2)/r2)r12
    double FMag = k * (q1.Q * q2.Q) / pow(r, 2);

    Vector3D F = ur12 * FMag;
    
    return F;
}; 

Vector3D Electromagnetism::Force(const Charge& q1, const std::vector<Charge> charges){
    Vector3D F;
    for (const Charge& q : charges) {
        F = F + Force(q1, q);
    };

    return F;
}; 
