#pragma once
#include <raylib.h>

class Enemy {
protected:
    int hp;
    int assignedLane;
    int progressNumber = 0;

public:
    Enemy(int h, int l) {
        hp = h;
        assignedLane = l;
    }
    virtual ~Enemy() = default;

    virtual void Draw(Vector2 center) const = 0;
    virtual void Advance() = 0;
    virtual void TakeDamage() {
        hp--;
    };

    bool IsDead() const {
        return hp <= 0;
    };

    int GetLane() const {
        return assignedLane;
    };

    int GetProgress() const {
        return progressNumber;
    }
};
