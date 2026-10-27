#include <raylib.h>
#include "Game.hpp"
#include "../scenes/TitleScene.hpp"

Game::Game() {
    InitWindow(1280, 800, "Test 1");
    SetTargetFPS(60);
    sceneManager.ChangeScene(std::make_unique<TitleScene>(&sceneManager));
};

Game::~Game() {
    CloseWindow();
}

void Game::Run() {
    while(WindowShouldClose() == false){
    float dt = GetFrameTime();

        //event handling

        //updating positions
        sceneManager.Update(dt);

        //drawing
        BeginDrawing(); //preparing canvas

        ClearBackground(BLACK);

        sceneManager.Draw();

        EndDrawing();   //close canvas
    }
}
