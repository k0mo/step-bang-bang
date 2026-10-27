// シーンのための抽象クラス
// すべてのシーンに共通する処理を作る必要にならない限りScene.cppは作らなくていい
// また、hppファイルだけを作ること=抽象クラス　ではない

#pragma once

class SceneManager;

class Scene {
protected:
    // この抽象クラスを継承するシーンはシーンマネージャー
    SceneManager *manager = nullptr;
public:
    explicit Scene(SceneManager *m) : manager(m) {}
    virtual ~Scene() = default;

    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;
};
