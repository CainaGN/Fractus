#include <stdio.h>
#include <raylib.h>
#include <math.h> 
#include <stdlib.h> // for the rand() function


#define WIDTH 1024
#define HEIGHT 720

#define STARTING_THICKNESS 30
#define OFF_ANGLE 20*DEG2RAD

#define MAX_DEPTH 15

#define BACKGROUND (Color){13, 17, 23, 255} // background color of Github


float rand_float(float x, float percentage)
{

    float min = percentage * x;
    float max = x;
    float random = (float)rand() / RAND_MAX;

    return min + random * (max - min);
}

float variate_position(float a)
{
    float max_variation = a * 0.20;
    float x = (float)rand()/(float)(RAND_MAX/1);
    return a + (x * max_variation);
}

void draw_fractal(float x, float y, float lenght, float angle, float thickness, int depth, int growing, int seed) 
{
    if (depth > growing) return;
    depth++;

    srand(84 + seed);

    float x_end = (x + sinf(angle) * rand_float(lenght, 0.7));
    float y_end = (y - cosf(angle) * rand_float(lenght, 0.6));
    Vector2 end = {x_end, y_end};
    Vector2 start = {x, y};

    // Here i'll be defining the lenght and angle for the next branches so i wont be losing the Seed
    // If i calculate this when i call the method, it will go on until the end on the right side and by the time it arrives on the left side, the seed will be lost
    float new_lenght_right = rand_float((lenght * 0.7), 0.9);
    float new_lenght_left = rand_float((lenght * 0.7), 0.9);
    float new_right_angle = variate_position(angle + OFF_ANGLE);
    float new_left_angle = variate_position(angle - OFF_ANGLE);



    if(depth > 8)
    {
        DrawLineEx(start, end, thickness, GREEN);
    }else
    {
        DrawLineEx(start, end, thickness, BROWN);
    }
    
 
    draw_fractal(x_end, y_end, new_lenght_right, new_right_angle, thickness * 0.7, depth, growing, seed*2);
    draw_fractal(x_end, y_end, new_lenght_left, new_left_angle, thickness * 0.7, depth, growing, (seed*2)+1);
}

void draw_window() 
{
    InitWindow(WIDTH, HEIGHT, "Fractals");
    SetTargetFPS(4);
    int growing = 0;
    

    while (!WindowShouldClose()) {
        
        BeginDrawing();
        ClearBackground(BACKGROUND);
        
        draw_fractal(WIDTH/2, HEIGHT - 20, 200, 0, STARTING_THICKNESS, 0, growing, 1);
        if(growing <= MAX_DEPTH)
        {
            growing++;
        }else
        {
            TakeScreenshot(TextFormat("screenshots/frame_%02i.png", growing));
            EndDrawing();
            return;
        }
        
        EndDrawing();
        TakeScreenshot(TextFormat("screenshots/frame_%02i.png", growing));
        
    }
    
    CloseWindow();
}

int main() 
{
    system("mkdir -p screenshots"); //the -p argument tells the system "create that if it doesnt exists, if it does, just ignore me"
    draw_window();
    system("ffmpeg -framerate 4 -i screenshots/frame_%02d.png -lavfi 'palettegen [p]; [0:v][p] paletteuse' fractal_growth.gif -y");
    
    return 0;
}