#include "raylib.h"
#include "Ball.h"
#include <string>

int main() {
    // 1. Initialize the Window (800x600 pixels) and cap the framerate
    InitWindow(1280, 720, "Physics Simulation");
    SetTargetFPS(60);

    // 2. Create our Ball object
    Ball myBall(400.0f, 100.0f, 20.0f);

    // A memory variable to remember where the user first clicked for the throw calculation
    Vector2 mouseStartPos = { 0.0f, 0.0f };

    // 3. The Main Game Loop
    while (!WindowShouldClose()) {
        
        // Step A: Calculate exactly how much time passed since the last frame
        float dt = GetFrameTime();

        // ---- STEP B: READ INTERACTIVE MOUSE INTERACTION FIRST ----

        // Click frame: Remember the starting point
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            mouseStartPos = GetMousePosition();
        }

        // Holding state: Pin ball to mouse position and nullify velocities
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            myBall.position.x = (float)GetMouseX();
            myBall.position.y = (float)GetMouseY();
            
            // Freeze movement forces completely while holding the ball
            myBall.velocity.x = 0.0f;
            myBall.velocity.y = 0.0f;
            myBall.acceleration.y = 0.0f; 
        }

        // Release frame: Calculate throwing vector momentum
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            Vector2 mouseEndPos = GetMousePosition();

            // Direct Throw Math: (End Position - Start Position) moves the ball
            // in the direction your hand actually dragged it.
            myBall.velocity.x = (mouseEndPos.x - mouseStartPos.x) * 5.0f;
            myBall.velocity.y = (mouseEndPos.y - mouseStartPos.y) * 5.0f;

            // Turn gravity back on so the physics engine takes over
            myBall.acceleration.y = 300.0f;
        }

        // ---- STEP C: RUN PHYSICS EQUATIONS SECOND ----
        // This ensures the fresh throwing velocities are processed cleanly
        if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            myBall.Update(dt);
        }

        // ---- STEP D: RENDER FRAME LAST ----
        BeginDrawing();
        ClearBackground(WHITE); // Paint canvas white

        myBall.Draw();          // Draw our red ball on top

        std::string fpsText = "FPS: " + std::to_string(GetFPS()); //get fps
        DrawText(fpsText.c_str(), 20, 20, 20, DARKGREEN);

        std::string posText = "Pos X: " + std::to_string((int)myBall.position.x) + "Y: " + std::to_string((int)myBall.position.y);
        DrawText(posText.c_str(), 20, 45, 20, DARKGREEN);
        
        std::string velText = "Vel X: " + std::to_string((int)myBall.velocity.x) + " Y: " + std::to_string((int)myBall.velocity.y);
        DrawText(velText.c_str(), 20, 70, 20, DARKGREEN);




        EndDrawing();
    }

    // 4. Clean up memory and close the window safely
    CloseWindow();

    return 0;
}
