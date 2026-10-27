#include <raylib.h>
#include "GameScene.hpp"
#include "ResultScene.hpp"
#include "../core/SceneManager.hpp"
#include "../core/Sequencer.hpp"
#include <cmath>


    GameScene::GameScene(SceneManager *m) : Scene(m) {
        sequencer.SetBpm(manager -> GetBpm());
    }

    void GameScene:: Update(float dt) {
        gameTimer += dt;
        sequencer.Update(dt);
        gun.Update(sequencer.getCurrentStep());

        if (IsKeyPressed(KEY_SPACE)) {
            bullets.emplace_back(gun.GetCurrentLane());
        }
        for (auto it = bullets.begin(); it != bullets.end(); ) {
            it -> Update(dt);

            if (it -> IsOutOfBounds()) {
                // erase()は要素を消すだけでなく次の要素をreturnする
                it = bullets.erase(it);
            } else {
                // eraseしないのであればただ次の要素に
                ++it;
            }
        }
    }

    void GameScene:: Draw() {
        Vector2 center = {(float)screenW / 2.0f, (float)screenH / 2.0f};
        DrawGrid(center, sequencer.getCurrentStep());
        gun.Draw();

        for (const auto& bullet : bullets) {
            bullet.Draw(center);
        }
    }

    void GameScene::DrawGrid(Vector2 center, int activeStep) const {
        const float innerRadius = 40.0f;
        const float outerRadius = 400.0f;
        const float damageBorder = 100.0f;
        float divider = damageBorder;
        const int totalLines = 16;
        const Color gridColor = Fade(DARKGRAY, 0.6f);

        const float stepDegrees = 360.0f / totalLines;

        DrawCircleLines(center.x, center.y, innerRadius, gridColor);
        DrawCircleLines(center.x, center.y, outerRadius, gridColor);
        DrawCircleLines(center.x, center.y, damageBorder, gridColor);
        while(divider <= outerRadius) {
            DrawCircleLines(center.x, center.y, divider, gridColor);
            divider += (outerRadius - damageBorder)/3.0f;
        }
        for (int i = 0; i < totalLines; ++i) {
            float angle = i * (PI / 8.0f) - (PI / 2.0f);
            Vector2 start = {
                center.x + cosf(angle) * innerRadius,
                center.y + sinf(angle) * innerRadius
            };

            Vector2 end = {
                center.x + cosf(angle) * outerRadius,
                center.y + sinf(angle) * outerRadius
            };

            DrawLineV(start, end, gridColor);
        }

    }
