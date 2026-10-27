#pragma once

#include <raylib.h>

class Bullet {
private:
    float speed = 4000.0f;
    float thickness = 4.0f;
    int currentLane = 0;
    float distance = 40.0f;
    float maxDistance = 900.0f;

public:
    Bullet(int lane) {
        currentLane = lane;
    }
    void Update(float dt);
    void Draw (Vector2 center) const;

    bool IsOutOfBounds();
};
