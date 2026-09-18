#ifndef _HUD_RENDERER_
#define _HUD_RENDERER_

#include "raylib.h"

class HudRenderer {
    public:
        void drawFPS();
        void drawElapsedTime();
        void drawMousePos(Vector3 r);
};

#include "..\src\HudRenderer.cpp"

#endif // HudRenderer