#pragma once
#include "raylib.h"

class Gun {
private:
    int currentLane = 0;
    int centerX = GetScreenWidth() / 2;
    int centerY = GetScreenHeight() / 2;
    Vector2 centerPos = {(float)centerX,(float)centerY};
    Vector2 direction;
    float GetAngleRadians();
    Vector2 GetDirection();
public:
    void Update(int lane);
    void Rotate();
    void Shoot();
    void Draw();

    int GetCurrentLane() {
        return currentLane;
    }
};
