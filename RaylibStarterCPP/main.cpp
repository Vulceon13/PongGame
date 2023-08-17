#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

int main(int argc, char* argv[])
{
    int screenWidth = 1280;
    int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Pong!");
    SetTargetFPS(60);
    

    while (!WindowShouldClose())   
    {    
        BeginDrawing();

        ClearBackground(BLACK);

        //Drawing
        DrawCircle(screenWidth/2, screenHeight/2, 20, WHITE);
        DrawRectangle(10, screenHeight / 2 - 60, 25, 120, WHITE);
        DrawRectangle(screenWidth - 35, screenHeight / 2 - 60, 25, 120, WHITE);
        EndDrawing();
       
    }

       
    CloseWindow();
   
    return 0;
}