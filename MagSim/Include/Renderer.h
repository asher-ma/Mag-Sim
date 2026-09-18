#ifndef _RENDERER_
#define _RENDERER_

#include "raylib.h"

class Renderer {
    private:
        Camera camera;
        Camera initCam();
        void initWorld();
        

        void drawGrid(int width, int height);
        void drawCharges(); // TODO
        void drawFields(); // TODO

    public:
        // Constructor
        Renderer(int width, int height);

        void drawWorld(); // TODO

        Vector3 getMouseWorldPos();
};

#include "..\src\Renderer.cpp"

#endif // Renderer