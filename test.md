```mermaid
%%{init: {'theme': 'dark'}}%%

classDiagram
    Game *-- SceneManager
    SceneManager o-- Scene

    TitleScene --|> Scene
    GameScene --|> Scene
    ResultScene --|> Scene

    GameScene *-- Enemy
    GameScene *-- Gun
    GameScene *-- Bullet
    GameScene *-- Sequencer


    class Game {
        +Run()
    }

    class Enemy {
        -EnemyType type
        -int hp
        -int lane
        +Enemy(EnemyType type, int lane)
        +Advance()
    }

    class EnemyType {
        <<enumeration>>
        Normal
        Tank
    }

    class Sequencer {
        -float bpm
        -int currentStep
        -float duration
        -float elapsedTime
        -bool isRotationTime
        -bool isGoAround
        +Update(float deltaTime)
    }

    class Scene {
        <<abstract>>
        +virtual ~Scene()
        +virtual Update()*
        +virtual Draw()*
    }

    class SceneType {
        <<enumeration>>
        Title
        Game
        Result
    }

    class SceneManager {
        -Scene* currentScene
        +ChangeScene(SceneType type)
        +Update()
        +Draw()
    }

    class TitleScene {
        +Update()
        +Draw()
    }

    class GameScene {
        -int score
        -Scquencer sequencer
        -Gun gun
        -vector~Bullet~ bullets
        -vector~Enemy~ enemies
        +Update()
        +Draw()
    }

    class ResultScene {
        +Update()
        +Draw()
    }

    class Gun {
        int currentLane
        +Rotate()
        +Shoot()
    }

    class Bullet {
        -int lane
        +Update()
        +Draw()

    }


````
