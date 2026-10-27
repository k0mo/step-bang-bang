#pragma once

class Sequencer {
private:
    float bpm;
    int currentStep = 0;
    float duration;
    float elapsedTime = 0.0f;
    bool isRotationTime = false;
    bool hasGoneAround = false;

public:
    Sequencer(float bpm = 120.0f){
        this -> bpm = bpm;
        duration = 60.0f / bpm;
    }
    void Update(float dt);

    void SetBpm(float selectedBpm) {
        bpm = selectedBpm;
    }

    bool ConsumeRotationTrigger() {
        if (isRotationTime) {
            isRotationTime = false;
            return true;
        }
        return false;
    }
    int getCurrentStep() {
        return currentStep;
    }
};
