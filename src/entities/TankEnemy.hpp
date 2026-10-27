#include "Enemy.hpp"

class TankEnemy : public Enemy  {

   explicit TankEnemy(int lane) : Enemy(2, lane) {}
   void Advance() override;
   void Draw(Vector2 center) const override;
};
