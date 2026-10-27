#include "raylib.h"
#include "Gun.hpp"
#include <cmath>


void Gun::Update(int lane) {
    currentLane = lane;
    direction = GetDirection();
}

float Gun::GetAngleRadians() {
    return currentLane * (PI / 8.0f) - (PI/ 2.0f) -((PI / 8.0f) / 2.0f);
}

Vector2 Gun::GetDirection () {
    float angle = GetAngleRadians();
    return {(float)cos(angle), (float)sin(angle)};
}

void Gun::Draw() {
    float barrelLength = 40.0f;
    float thickness = 6.0f;
    Vector2 endPos = {
        centerPos.x + direction.x * barrelLength,
        centerPos.y + direction.y * barrelLength
    };
    DrawLineEx(centerPos, endPos, thickness, WHITE);

}
