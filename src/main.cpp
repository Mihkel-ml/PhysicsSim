#include "raylib.h"
#include "Ball.h"
#include <string>

int main() {
    InitWindow(1280, 720, "Physics Simulation");
    SetTargetFPS(60);

    Ball myBall(400.0f, 100.0f, 20.0f);
    Vector2 mouseStartPos = { 0.0f, 0.0f };
<<<<<<< Updated upstream
=======
    float currentGravity = 300.0f;
>>>>>>> Stashed changes

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            mouseStartPos = GetMousePosition();
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            myBall.position.x = (float)GetMouseX();
            myBall.position.y = (float)GetMouseY();
            myBall.velocity.x = 0.0f;
            myBall.velocity.y = 0.0f;
            myBall.acceleration.y = 0.0f; 
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            Vector2 mouseEndPos = GetMousePosition();
<<<<<<< Updated upstream

            myBall.velocity.x = (mouseEndPos.x - mouseStartPos.x) * 5.0f;
            myBall.velocity.y = (mouseEndPos.y - mouseStartPos.y) * 5.0f;

            myBall.acceleration.y = 300.0f;
        }

        if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            myBall.Update(dt);
        }

=======
            myBall.velocity.x = (mouseStartPos.x - mouseEndPos.x) * 5.0f;
            myBall.velocity.y = (mouseStartPos.y - mouseEndPos.y) * 5.0f;
            myBall.acceleration.y = currentGravity;
        }

        if (IsKeyDown(KEY_UP)) {
            currentGravity -= 5.0f;
        }
        if (IsKeyDown(KEY_DOWN)) {
            currentGravity += 5.0f;
        }

        if (IsKeyPressed(KEY_R)) {
            myBall.position.x = 400.0f;
            myBall.position.y = 100.0f;
            myBall.velocity.x = 0.0f;
            myBall.velocity.y = 0.0f;
            currentGravity = 300.0f;
            myBall.acceleration.y = currentGravity;
        }

        if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            myBall.acceleration.y = currentGravity;
            myBall.Update(dt);
        }

>>>>>>> Stashed changes
        BeginDrawing();
        ClearBackground(WHITE); 

        myBall.Draw();          

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            DrawLineV(GetMousePosition(), mouseStartPos, RED);
        }

        std::string fpsText = "FPS: " + std::to_string(GetFPS()); 
        DrawText(fpsText.c_str(), 20, 20, 20, DARKGREEN);

        std::string posText = "Pos X: " + std::to_string((int)myBall.position.x) + " Y: " + std::to_string((int)myBall.position.y);
        DrawText(posText.c_str(), 20, 45, 20, DARKGREEN);
        
        std::string velText = "Vel X: " + std::to_string((int)myBall.velocity.x) + " Y: " + std::to_string((int)myBall.velocity.y);
        DrawText(velText.c_str(), 20, 70, 20, DARKGREEN);

<<<<<<< Updated upstream


=======
        std::string gravText = "Grav: " + std::to_string((int)myBall.acceleration.y);
        DrawText(gravText.c_str(), 20, 95, 20, DARKGREEN);
>>>>>>> Stashed changes

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
