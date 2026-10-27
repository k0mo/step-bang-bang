#pragma once

#include "Scene.hpp"

class TitleScene : public Scene {
private:
    float enteredBpm;
public:
    // 基底クラス(Sceneクラス)がマネージャー向けのポインタを保持する設計なので
    // 受け取った参照をそのままSceneに送り、Sceneにある変数managerに参照を保持させる
    explicit TitleScene(SceneManager *m) : Scene(m) {};
    void Update(float deltaTime) override;
    void Draw() override;
};
