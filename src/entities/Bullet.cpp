#include "Bullet.hpp"
#include <raylib.h>
#include <cmath>

    void Bullet::Update(float dt) {
        distance += speed * dt;
    }

    void Bullet::Draw (Vector2 center) const{
        float angle = currentLane * (PI / 8.0f) - (PI / 2.0f) - ((PI / 8.0f) / 2);

        Vector2 pos = {
            center.x + cosf(angle) * distance,
            center.y + sinf(angle) * distance,
        };


        DrawCircleV(pos, thickness, YELLOW);
    }

    bool Bullet::IsOutOfBounds() {
        if (distance > maxDistance) {
            return true;
        }
        else return false;
    }
