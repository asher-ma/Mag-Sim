#ifndef _APPLICATION_
#define _APPLICATION_

#include "Simulation.h"
#include "Renderer.h"
#include "HudRenderer.h"
#include "raylib.h"

// The main application. Handles simulation and rendering cycles
class Application {
    private:
        Simulation simulation;
        Camera camera;
        Camera initCamera();
        Renderer renderer;
        HudRenderer HudRenderer;

    public:

};

#include "..\src\Application.cpp"

#endif // Application