#pragma once                   
#include "raylib.h"            

class Ball {                   
public:                        
    // Variables
    Vector2 position;         
    Vector2 velocity;         
    Vector2 acceleration;     
    float radius;         
    
    // Functions
    Ball(float startX, float startY, float startRadius);
    void Update(float dt);
    void Draw();
};
