#include "raylib.h"
#include "Ball.h"
#include <string>

int main() {
    InitWindow(1280, 720, "Physics Simulation");
    SetTargetFPS(60);

    Ball myBall(400.0f, 100.0f, 20.0f);

    Vector2 mouseStartPos = { 0.0f, 0.0f };

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

            myBall.velocity.x = (mouseEndPos.x - mouseStartPos.x) * 5.0f;
            myBall.velocity.y = (mouseEndPos.y - mouseStartPos.y) * 5.0f;

            myBall.acceleration.y = 300.0f;
        }

        if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            myBall.Update(dt);
        }

        BeginDrawing();
        ClearBackground(WHITE); 

        myBall.Draw();          

        std::string fpsText = "FPS: " + std::to_string(GetFPS()); 
        DrawText(fpsText.c_str(), 20, 20, 20, DARKGREEN);

        std::string posText = "Pos X: " + std::to_string((int)myBall.position.x) + "Y: " + std::to_string((int)myBall.position.y);
        DrawText(posText.c_str(), 20, 45, 20, DARKGREEN);
        
        std::string velText = "Vel X: " + std::to_string((int)myBall.velocity.x) + " Y: " + std::to_string((int)myBall.velocity.y);
        DrawText(velText.c_str(), 20, 70, 20, DARKGREEN);




        EndDrawing();
    }

    CloseWindow();

    return 0;
}
