#pragma once
#include "Scene.hpp"

class SceneManager;

class ResultScene : public Scene {
private:
    bool isWin;
    int finalPlayerScore;
    int finalCpuScore;

public:
    ResultScene(SceneManager *m, bool win, int playerScore = 0, int cpuScore = 0)
        : Scene(m), isWin(win), finalPlayerScore(playerScore), finalCpuScore(cpuScore) {}

    void Update(float deltaTime) override;
    void Draw() override;
};
