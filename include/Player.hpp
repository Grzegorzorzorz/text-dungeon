#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Data.hpp"
#include "Dungeon.hpp"
#include "Items.hpp"

#include <string>
#include <vector>

namespace Player {
  class Player {
    public:
      int floor;
      Dungeon::Coordinates coordinates;
      Dungeon::Dungeon *dungeon;
      std::vector<std::string> discovered_commands;
      Items::Item equipped_weapon;
      Items::Item equipped_armour;
      Items::Slot inventory[5][4];
      Player();
      int getHealth();
      int modifyHealth(int);
    private:
      int level;
      int health;
  };
}

#endif