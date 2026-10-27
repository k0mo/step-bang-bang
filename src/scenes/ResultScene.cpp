#include "ResultScene.hpp"
#include "../core/SceneManager.hpp"
#include "TitleScene.hpp"
#include <raylib.h>

void ResultScene::Update(float deltaTime) {
    if (IsKeyPressed(KEY_ENTER)) {
        manager -> ChangeScene(std::make_unique<TitleScene>(manager));
    }
    else if (IsKeyPressed(KEY_ESCAPE)) {
        manager -> Quit();
    }
}

void ResultScene::Draw() {
    if (isWin) {
    DrawText("you win", 320, 200, 60, DARKGRAY);
    } else {
        DrawText("you lose", 320, 200, 60, DARKGRAY);
    }
    DrawText(TextFormat("score : %d - %d",finalCpuScore, finalPlayerScore) ,320, 300, 30, WHITE);
    DrawText("push enter to back title", 260, 400, 20, DARKGRAY);
    DrawText("push escape to quit", 300, 500, 20, DARKGRAY);
}
