#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

class Ball 
{
public:
float x, y;
int speed_x, speed_y;
int radius;

void Draw() 
{
    DrawCircle(x, y, radius, WHITE); // Drawing Ball
}

void Update()
{
    x += speed_x;
    y += speed_y;

    // Checking for collision with the edges
    // Using the x pos, y pos and radius of ball to see if ball is colliding with an edge
    if(y + radius >= GetScreenHeight() || y - radius <= 0) 
    {
        speed_y *= -1;
    }
    if (x + radius >= GetScreenWidth() || x - radius <= 0)
    {
        speed_x *= -1;
    }
}

};

Ball ball;

int main(int argc, char* argv[])
{
    int screenWidth = 1280;
    int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Pong!");
    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = screenWidth/2;
    ball.y = screenHeight / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;
    
    while (!WindowShouldClose())   
    {    
        BeginDrawing();

        //Updating
        ball.Update();

        //Drawing
        ClearBackground(BLACK); // Creating Black Background
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE); // Drawing A Halfway Line                
        ball.Draw();
        DrawRectangle(10, screenHeight / 2 - 60, 25, 120, WHITE); // Drawing Left Paddle
        DrawRectangle(screenWidth - 35, screenHeight / 2 - 60, 25, 120, WHITE); // Drawing Right Paddle
        
        EndDrawing();
       
    }

       
    CloseWindow();
   
    return 0;
}