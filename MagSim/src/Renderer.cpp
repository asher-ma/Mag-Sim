#include "Renderer.h"

// Constructor
// Creates renderer given window width and height
Renderer::Renderer(int width, int height) : camera(initCam()) {
    // Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    // Initialize window and OpenGL context
    InitWindow(width, height, "MagSim");
}


// Draw grid
void Renderer::drawGrid(int width, int height) {
    BeginMode3D(camera);
    int halfWidth = width/2;
    int halfHeight = height/2;
    int space = 100; // Space between graph lines
    int buffer = space; // Buffer between edge of graph and edge of camera

    // Draw vertical lines
    for (int x = -halfWidth; x < halfWidth; x += space) {
        DrawLine(x, -halfHeight + buffer, x, halfHeight - buffer, LIGHTGRAY);
    }

    // Draw horizontal lines
    for (int y = -halfHeight; y < halfHeight; y += space) {
        DrawLine(-halfWidth + buffer, y, halfWidth - buffer, y, LIGHTGRAY);
    }
    EndMode3D();
}

// Initialize camera
// Center camera on origin
Camera Renderer::initCam() {
    Vector3 position = {0,0,500};
    Vector3 target = {0,0,0};
    Vector3 up = {0,1,0};
    float fovy = 1000;
    int projection = CAMERA_ORTHOGRAPHIC;
    return Camera{position, target, up, fovy, projection};
}

// Getters
Vector3 Renderer::getMouseWorldPos() {
    return GetScreenToWorldRay(GetMousePosition(), camera).position;
}