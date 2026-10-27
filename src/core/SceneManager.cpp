#include "SceneManager.hpp"
#include "../scenes/Scene.hpp"

SceneManager::SceneManager() = default;
SceneManager::~SceneManager() = default;

void SceneManager::ChangeScene(std::unique_ptr<Scene> newScene) {
    //今のシーンを指すポインタの指す先を渡されたnewsceneに変更
    currentScene = std::move(newScene);
}

void SceneManager::Update(float deltaTime) {
    // currentSceneがnullptrでなければそのシーンのupdateを実行
    if(currentScene) currentScene -> Update(deltaTime);
}

void SceneManager::Draw() {
    if(currentScene) currentScene -> Draw();
}
