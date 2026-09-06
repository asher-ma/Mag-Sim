#include "Electromagnetism.h"
#include "Geometry.h"


Vector3D Electromagnetism::FieldAt(const Vector3D r, const Charge& q) {
    Vector3D uqr = Geometry::dir(q.r, r); // Unit vector for direction from q to r
    double d = Geometry::dist(r, q.r); // Distance from q to r

    double EMag = k * (q.Q) / pow(d, 2);

    Vector3D E = uqr * EMag;
    return E;
};

Vector3D Electromagnetism::FieldAt(const Vector3D r, const std::vector<Charge> charges) {
    Vector3D E;
    for (const Charge& q : charges) {
        E = E + FieldAt(r, q);
    };

    return E;
};

Vector3D Electromagnetism::Force(const Charge& q1, const Charge& q2){
    Vector3D E = FieldAt(q1.r, q2);
    Vector3D F = E * q1.Q;
    
    return F;
}; 

Vector3D Electromagnetism::Force(const Charge& q1, const std::vector<Charge> charges){
    Vector3D E = FieldAt(q1.r, charges);
    Vector3D F = E * q1.Q;

    return F;
};