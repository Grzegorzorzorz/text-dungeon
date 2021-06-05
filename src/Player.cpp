#include "Data.hpp"
#include "Items.hpp"
#include "Player.hpp"

namespace Player {
  Player::Player() {
    floor = 0;
    level = 1;
    health = 20;
    coordinates = {4, 4};
    equipped_weapon = Items::lookup_item("fists");
    equipped_armour = Items::lookup_item("cloth_tunic");
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 5; x++) {
        inventory[x][y].item = Items::lookup_item("nothing");
        inventory[x][y].quantity = 0;
      }
    }
  }

  int Player::getHealth() {return health;}
  int Player::modifyHealth(int value) {health += value; return 0;}
}