#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>

#include "Geometry.h"
#include "Electromagnetism.h"
#include "raylib.h"

void displayVectorProperties(Vector3D r) {
    std::cout << "r: " << r << "\nmag: " << r.mag() << "\nunit: " << r.unit() << std::endl;
};
void displayVectorRelations(Vector3D r1, Vector3D r2) {
    std::cout << "r: " << r2-r1 << "\ndist: " << Geometry::dist(r1, r2)
        << "\ndir: " << Geometry::dir(r1, r2) << std::endl;
};
double rad(double deg){
    return deg * (M_PI/180);
}

// Vector operations tests
void VectorGeometryTests() {
    std::cout << "\n-----------------------------------------------------------------------------\nVECTOR OPERATIONS\n";
    Vector3D r0(0, 0, 0);
    Vector3D r1(3, 4, 0);
    Vector3D r2(6, 8, 0);
    
    std::cout << "Vector r0:\n";
    displayVectorProperties(r0);
    std::cout << "\nVector r1:\n";
    displayVectorProperties(r1);
    std::cout << "\nVector r2:\n";
    displayVectorProperties(r2);
    
    // Vector geometry tests
    std::cout << "\nVector r01:\n";
    displayVectorRelations(r0, r1);
    std::cout << "\nVector r12:\n";
    displayVectorRelations(r1, r2);
    std::cout << "\nVector r02:\n";
    displayVectorRelations(r0, r2);
}

// Electromagnetic operations tests
void ElectromagneticTests() {
    std::cout << "\n-----------------------------------------------------------------------------\nElectromagnetic force operations\n";
    const int s = 1;
    {
        std::cout << "Test A:\n" << "Expected: (0,2,0)\n";
        Charge q0(Vector3D(0,0,0), 1);
        std::vector<Charge> charges = {
            Charge(Vector3D(-s*sin(rad(60)), -s*cos(rad(60)), 0), 1),
            Charge(Vector3D(0,-s,0), 1),
            Charge(Vector3D(s*sin(rad(60)), -s*cos(rad(60)), 0), 1)
        };
        Vector3D F =  Electromagnetism::Force(q0, charges);
        std::cout << "F(q0): " << F << std::endl
                << "Mag: " << F.mag() << std::endl
                << "Dir: " << F.unit() << std::endl;
    }

    {
        std::cout << "\nTest B:\n" << "Expected: (0,3,0)\n";
        Charge q0(Vector3D(0,0,0), 1);
        Charge q1(Vector3D(0,-s,0), 3);
        Vector3D F =  Electromagnetism::Force(q0, q1);
        std::cout << "F(q0): " << F << std::endl
                << "Mag: " << F.mag() << std::endl
                << "Dir: " << F.unit() << std::endl;
    }

    {
        std::cout << "\nTest C:\n" << "Expected: (-3sqrt(3)/2,3/2,0) OR (" << (-double(3) * sqrt(3))/2 << "," << double(3)/2 << ",0)\n";
        Charge q0(Vector3D(0,0,0), 1);
        std::vector<Charge> charges = {
            Charge(Vector3D(-s*sin(rad(60)), -s*cos(rad(60)), 0), -3),
            Charge(Vector3D(0,-s,0), 3)
        };
        Vector3D F =  Electromagnetism::Force(q0, charges);
        std::cout << "F(q0): " << F << std::endl
                << "Mag: " << F.mag() << std::endl
                << "Dir: " << F.unit() << std::endl;
    }
}

// Center camera on origin
Camera centerCam() {
    Vector3 position = {0,500,0};
    Vector3 target = {0,0,0};
    Vector3 up = {0,0,-1};
    float fovy = 1000;
    int projection = CAMERA_ORTHOGRAPHIC;
    return Camera{position, target, up, fovy, projection};
}

void rayInit() {
    // Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    
    int width = 1000;
    int height = 1000;
    int graphSpacing = 50;

    // Initialize window and OpenGL context
    InitWindow(width, height, "MagSim");

    Camera camera = centerCam();

    // game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
        // Update camera
        UpdateCamera(&camera, CAMERA_CUSTOM);


		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

        BeginMode3D(camera);
        DrawGrid(width/graphSpacing - 1, graphSpacing);
        EndMode3D();

        // // Draw grid for graph
        // drawGrid(width, height);

        // Display fps
        std::string fpsText = std::to_string(GetFPS());
        DrawText(fpsText.c_str(), 10,10,10,WHITE);

        // Display elapsed time
        std::string timeText = std::to_string(static_cast<int>(GetTime()));
        DrawText(timeText.c_str(), 10,25,10,WHITE);

        std::string mouseText = "Mouse at: (" + std::to_string(GetMouseX()) + "," + std::to_string(GetMouseX()) + ")";
        DrawText(mouseText.c_str(), 10,40,10,WHITE);
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

    // destroy the window and cleanup the OpenGL context
    CloseWindow();
}

int main() {
    // VectorGeometryTests();    
    // ElectromagneticTests();

    
    rayInit();

    return 0;
}