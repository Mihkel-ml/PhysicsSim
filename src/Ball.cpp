#include "Ball.h"
#include "raylib.h"

// Constructor: Initializes the ball's properties when created
Ball::Ball(float startX, float startY, float startRadius) {
    position.x = startX;
    position.y = startY;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    acceleration.x = 0.0f;
    acceleration.y = 300.0f; // Downward gravity acceleration
    radius = startRadius;
}

// Update: Computes kinematics step calculations and ground containment
void Ball::Update(float dt) {

    // drag
    float drag = 0.99f;
    velocity.x *= drag;
    velocity.y *= drag;

    // 1. Velocity changes because of acceleration (v = v0 + at)
    velocity.x += acceleration.x * dt;
    velocity.y += acceleration.y * dt;

    // 2. Position changes because of velocity (d = d0 + vt)
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    // 3. Ground Boundary Collision: Keeps ball contained above floor limit
    if (position.y + radius >= GetScreenHeight()) {
        position.y = (float)GetScreenHeight() - radius; // Hard reset to surface level so it doesn't sink
        velocity.y *= -0.8f;          // Flip direction and lose 20% impact energy
    }

    if (position.y + radius <= 0.0f) {
        position.y = 0.0f - radius;
        velocity.y *= -0.8f;
    }


    // wall boundary collision
    if (position.x + radius <= 0.0f) { // left wall
        position.x = 0.0f - radius;
        velocity.x *= -0.8f;
    }

    if (position.x + radius >= GetScreenWidth()) { // right wall
        position.x = (float)GetScreenWidth() - radius;
        velocity.x *= -0.8f;
    }
}

// Draw: Renders the physical entity state visually using raylib commands
void Ball::Draw() {
    DrawCircleV(position, radius, BLACK);

    // debugline
    Vector2 velocityEnd;
    velocityEnd.x = position.x + (velocity.x * 0.1f);
    velocityEnd.y = position.y + (velocity.y * 0.1f);

    DrawLineV(position, velocityEnd, BLUE);

    // trajectory
    Vector2 ghostPos = position;
    Vector2 ghostVel = velocity;

    float fakeDt = 0.05f;
    float fakeRad = 5.0f;
    for (int i = 0; i < 30; i++) {

        Vector2 prevPos = ghostPos;

        float t = i * fakeDt; // how much time has passed in the future
        
        // ---- THE GRAPH EQUATIONS ----
        // Apply: d = d0 + v0*t + 0.5*a*t^2
        ghostPos.x = position.x + (velocity.x * t);
        ghostPos.y = position.y + (velocity.y * t) + (0.5f * acceleration.y * t * t);
       
        // Only draw every other segment to keep it looking beautifully dashed!
        if (i % 2 == 0) {
            DrawLineV(prevPos, ghostPos, BLUE);
        }

    }

}
