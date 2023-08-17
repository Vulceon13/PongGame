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

        ClearBackground(BLACK); // Creating Black Background

        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE); // Drawing A Halfway Line
        
        //Drawing
        DrawCircle(screenWidth/2, screenHeight/2, 20, WHITE); // Drawing Ball
        
        DrawRectangle(10, screenHeight / 2 - 60, 25, 120, WHITE); // Drawing Left Paddle
        DrawRectangle(screenWidth - 35, screenHeight / 2 - 60, 25, 120, WHITE); // Drawing Right Paddle
        
        EndDrawing();
       
    }

       
    CloseWindow();
   
    return 0;
}