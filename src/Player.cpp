#include "Data.hpp"
#include "Items.hpp"
#include "Player.hpp"

namespace Player {
  Player::Player() {
    floor = 0;
    level = 1;
    health = 20;
    coordinates = {4, 4};
    equipped_weapon = Items::get_item("fists");
    for (int slot = 0; slot < 3; slot++) {
      inventory[slot].item = Items::get_item("nothing");
      inventory[slot].quantity = 0;
    }
  }

  int Player::getHealth() {return health;}
  int Player::modifyHealth(int value) {health += value; return 0;}
}