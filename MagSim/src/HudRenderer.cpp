#include "HudRenderer.h"
#include <string>


// Display fps
void HudRenderer::drawFPS() {
    std::string fpsText = std::to_string(GetFPS());
    DrawText(fpsText.c_str(), 10,10,10,WHITE);
}

// Display elapsed time
void HudRenderer::drawElapsedTime() {
    std::string timeText = std::to_string(static_cast<int>(GetTime()));
    DrawText(timeText.c_str(), 10,25,10,WHITE);
}

// Get ray from mouse pos on screen to world
// Ray {Vector3 position, Vector3 direction}
void HudRenderer::drawMousePos() {
    Ray ray = GetScreenToWorldRay(GetMousePosition(), camera);
    std::string mouseText = "Mouse at: (" + std::to_string(static_cast<int>(ray.position.x)) + "," +
            std::to_string(static_cast<int>(ray.position.y)) + ")";
    DrawText(mouseText.c_str(), 10,40,10,WHITE);
}