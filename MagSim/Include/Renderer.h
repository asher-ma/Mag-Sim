#ifndef _RENDERER_
#define _RENDERER_

#include "raylib.h"

class Renderer {
    public:
        void drawGrid(int width, int height);
        void drawCharges();
};

#include "..\src\Renderer.cpp"

#endif // Renderer