#include <stdio.h>
#include <raylib.h>
#include <math.h> 
#include <stdlib.h> // for the rand() function

#define WIDTH 800
#define HEIGHT 600

#define STARTING_THICKNESS 26
#define OFF_ANGLE 20*DEG2RAD

#define MAX_DEPTH 10

float rand_float(float x, float percentage)
{

    float min = percentage * x;
    float max = x;
    float random = (float)rand() / RAND_MAX;

    return min + random * (max - min);
}

float variations_position(float a)
{
    float max_variation = a * 0.20;
    float x = (float)rand()/(float)(RAND_MAX/1);
    return a + (x * max_variation);
}

void draw_fractal(float x, float y, float lenght, float angle, float thickness, int depth) 
{
    if (depth > MAX_DEPTH) return;
    depth++;
    
    //float fator = rand_float(lenght, 0.8);

    

    float x_end = (x + sinf(angle) * rand_float(lenght, 0.7));
    float y_end = (y - cosf(angle) * rand_float(lenght, 0.6));
    Vector2 end = {x_end, y_end};
    Vector2 start = {x, y};

   // printf("fator: %f\n x: %f\n y: %f\n\n", fator, x_end, y_end);

 


    DrawLineEx(start, end, thickness, BLACK);
    float new_lenght = lenght * 0.7;
    float new_right_angle = angle + OFF_ANGLE;
    float new_left_angle = angle - OFF_ANGLE;
    draw_fractal(x_end, y_end, rand_float(new_lenght, 0.9), variations_position(new_right_angle), thickness * 0.7, depth);
    draw_fractal(x_end, y_end, rand_float(new_lenght, 0.9), variations_position(new_left_angle), thickness * 0.7, depth);
}

void draw_window() 
{
    InitWindow(WIDTH, HEIGHT, "Fractals");
    SetTargetFPS(2);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_fractal(WIDTH/2, HEIGHT - 20, 170, 0, STARTING_THICKNESS, 0);
        EndDrawing();
    }
    CloseWindow();
}

int main() 
{
    draw_window();
    return 0;
}