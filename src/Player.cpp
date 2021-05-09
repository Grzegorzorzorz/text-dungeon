#include "Data.hpp"
#include "Player.hpp"

namespace Player {
  Player::Player() {
    floor = 0;
    level = 1;
    health = 20;
    coordinates = {4, 4};
  }

  int Player::getHealth() {return health;}
  int Player::modifyHealth(int value) {health += value; return 0;}
}