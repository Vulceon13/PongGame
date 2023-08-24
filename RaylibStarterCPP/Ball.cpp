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
        if (y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }
        if (x + radius >= GetScreenWidth()) // CPU Gains Point
        {
            cpu_score++;
            ResetBall();
        }

        if (x - radius <= 0) // Player Gain Point
        {
            player_score++;
            ResetBall();
        }
    }