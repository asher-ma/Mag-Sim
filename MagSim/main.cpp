#include <iostream>
#include <string>

#include "Phys.h"

using namespace std;

void displayVectorProperties(Vector3D r) {
    cout << "r: " << r << "\nmag: " << r.mag() << "\nunit: " << r.unit() << endl;
};
void displayVectorRelations(Vector3D r1, Vector3D r2) {
    cout << "r: " << r2-r1 << "\ndist: " << Geometry::dist(r1, r2)
        << "\ndir: " << Geometry::dir(r1, r2) << endl;
};

int main() {
    // Vector operations tests
    Vector3D r0(0, 0, 0);
    Vector3D r1(3, 4, 0);
    Vector3D r2(6, 8, 0);
    
    cout << "Vector r0:\n";
    displayVectorProperties(r0);
    cout << "\nVector r1:\n";
    displayVectorProperties(r1);
    cout << "\nVector r2:\n";
    displayVectorProperties(r2);
    
    // Vector geometry tests
    cout << "\nVector r01:\n";
    displayVectorRelations(r0, r1);
    cout << "\nVector r12:\n";
    displayVectorRelations(r1, r2);
    cout << "\nVector r02:\n";
    displayVectorRelations(r0, r2);

    return 0;
};