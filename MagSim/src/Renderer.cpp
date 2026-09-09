#include "Renderer.h"


// Draw grid
void Renderer::drawGrid(int width, int height) {
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
}