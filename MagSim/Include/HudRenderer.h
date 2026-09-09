#ifndef _HUD_RENDERER_
#define _HUD_RENDERER_

#include "raylib.h"

class HudRenderer {
    public:
        void drawFPS();
        void drawElapsedTime();
        void drawMousePos(int width, int height);
};

#include "..\src\HudRenderer.cpp"

#endif // HudRenderer