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
void HudRenderer::drawMousePos(Vector3 r) {
    std::string mouseText = "Mouse at: (" + std::to_string(static_cast<int>(r.x)) + "," +
            std::to_string(static_cast<int>(r.y)) + ")";
    DrawText(mouseText.c_str(), 10,40,10,WHITE);
}