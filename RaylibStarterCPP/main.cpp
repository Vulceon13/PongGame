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

class Paddle
{
protected:

    void LimitMovement()
    {
        if (y <= 0)
        {
            y = 0;
        }
        if (y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x, y;
    float width, height;
    int speed;

    void Draw()
    {
        DrawRectangle(x, y, width, height, WHITE); // Drawing Right Paddle
    }

    void Update()
    {
        // Adding Button
        if (IsKeyDown(KEY_UP))
        {
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN))
        {
            y = y + speed;
        }
        LimitMovement();
    }

};

class CpuPaddle : public Paddle
{
public:
    
    void Update(int ball_y) 
    {
        // Making the paddle move up or down depending on where the position of the ball is to the paddle
        if (y + height / 2 > ball_y)
        {
            y = y - speed;
        }
        if (y + height / 2 <= ball_y)
        {
            y = y + speed;
        }        
        LimitMovement();

    }
};


Ball ball;
Paddle player;
CpuPaddle cpu;

int main(int argc, char* argv[])
{
    int screenWidth = 1280;
    int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Pong!");
    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    player.width = 25;
    player.height = 120;
    player.x = screenWidth - player.width - 10;
    player.y = screenHeight/2 - player.height/2;
    player.speed = 6;

    cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screenHeight / 2 - cpu.height / 2;
    cpu.speed = 6;
    
    while (!WindowShouldClose())   
    {    
        BeginDrawing();

        //Updating
        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        //Drawing
        ClearBackground(BLACK); // Creating Black Background
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE); // Drawing A Halfway Line                
        ball.Draw();
        cpu.Draw();
        player.Draw();
        
        EndDrawing();
       
    }

       
    CloseWindow();
   
    return 0;
}