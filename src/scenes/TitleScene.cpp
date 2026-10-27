#include "TitleScene.hpp"
#include "../core/SceneManager.hpp"
#include "GameScene.hpp"
#include "raylib.h"

void TitleScene::Update(float deltaTime) {
    if (IsKeyPressed(KEY_ENTER)) {
        manager -> SetBpm(enteredBpm);
        manager -> ChangeScene(std::make_unique<GameScene>(manager));
    }
}

void TitleScene::Draw() {
    DrawText("TITLE", GetScreenWidth() / 2 - MeasureText("TITLE", 150) / 2, GetScreenHeight() / 2 - MeasureText("TITLE", 150) / 2, 150, DARKGRAY);
    DrawText("push enter to start", GetScreenWidth() / 2 - MeasureText("push enter to start", 50) / 2, 500 , 50, DARKGRAY);
}
