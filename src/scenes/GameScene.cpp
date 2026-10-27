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
        const int totalLines = 16;
        const Color gridColor = Fade(WHITE, 0.8f);
        const float step = (outerRadius - damageBorder) / 3.0f;
        const int dashCount = 128;
        const int totalSegments = dashCount * 2;
        const float angleStep = (2.0 * PI) / totalSegments;

        const float stepDegrees = 360.0f / totalLines;

        DrawCircleLines(center.x, center.y, innerRadius, WHITE);
        DrawCircleLines(center.x, center.y, outerRadius, WHITE);
        DrawCircleLines(center.x, center.y, damageBorder, WHITE);

        for (float divider = damageBorder + step; divider < outerRadius; divider += step) {
            for (int s = 0; s < totalSegments; s += 2) {
                float a1 = s * angleStep;
                float a2 = (s + 1) * angleStep;

                Vector2 p1 = {center.x + cosf(a1) * divider, center.y + sinf(a1) * divider};
                Vector2 p2 = {center.x + cosf(a2) * divider, center.y + sinf(a2) * divider};

                DrawLineV(p1, p2, gridColor);
            }
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

            DrawLineV(start, end, WHITE);
        }

    }
