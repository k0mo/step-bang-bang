#pragma once
#include <memory>

class Scene;

class SceneManager {
private:
    std::unique_ptr<Scene> currentScene;
    float selectedBpm = 120.0f;
    bool isRunning = true;

public:
    SceneManager();
    ~SceneManager();

    void ChangeScene(std::unique_ptr<Scene> nextScene);
    void Update(float deltaTime);
    void Draw();

    void SetBpm(float bpm) {selectedBpm = bpm;}
    float GetBpm() const {return selectedBpm;}
    void Quit() {isRunning = false;}
    bool IsRunnning() const {return isRunning;}
};
