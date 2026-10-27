#include "Sequencer.hpp"

void Sequencer::Update(float dt) {
    elapsedTime += dt;
    if (elapsedTime >= duration) {
        elapsedTime = 0.0f;
        currentStep = (currentStep + 1) % 16;
        isRotationTime = true;
    }
}
