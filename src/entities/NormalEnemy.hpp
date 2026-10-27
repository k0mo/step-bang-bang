#include "Enemy.hpp"

class NormalEnemy : public Enemy {
public:
   explicit NormalEnemy(int lane) : Enemy(1, lane) {}
   void Advance() override;
   void Draw(Vector2 center) const override;

};
