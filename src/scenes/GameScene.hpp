#include <raylib.h>
#include <iostream>
#include <vector>
#include "../core/Sequencer.hpp"
#include "../entities/Enemy.hpp"
#include "../entities/Gun.hpp"
#include "../entities/Bullet.hpp"
#include "Scene.hpp"

class SceneManager;

class GameScene :  public Scene {
private:
    float gameTimer = 0.0f;
    int score = 0;
    int screenW = GetScreenWidth();
    int screenH = GetScreenHeight();
    Sequencer sequencer;
    Gun gun;
    std::vector<Enemy> enemies;
    std::vector<Bullet> bullets;

    void DrawGrid(Vector2 center, int activeStep) const;

public:
    explicit GameScene(SceneManager *m);
    void Update(float dt) override;
    void Draw() override;
};
