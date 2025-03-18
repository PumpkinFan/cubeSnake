#include <iostream>
#include <vector>
#include "raylib.h"
#include "cube.h"

#define PLATFORM_WEB

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
const int screenWidth = 800;
const int screenHeight = 450;


// Global struct for tracking game state variables
struct GameState {
    Camera3D camera;
    std::vector<Cube> cubes = createCubes(5, 5, 5);
};

GameState game;

//----------------------------------------------------------------------------------
// Module functions declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void);     // Update and Draw one frame

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "cubeSnake");

    // Define camera into 3D world
    game.camera.position = Vector3 { 10.0f, 10.0f, 10.0f }; // Camera position
    game.camera.target = Vector3 { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    game.camera.up = Vector3 { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    game.camera.fovy = 90.0f;                                // Camera field-of-view Y
    game.camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type


#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void)
{
    // Update
    //----------------------------------------------------------------------------------
    UpdateCamera(&game.camera, CAMERA_FREE);
    
    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(RAYWHITE);


        BeginMode3D(game.camera);
            // DrawSphere({ 0.0f, 0.0f, 0.0f }, 1.0f, BLUE);
            for (Cube cube : game.cubes) {
                cube.draw();
            }
        EndMode3D();
    

    EndDrawing();
    //----------------------------------------------------------------------------------
}