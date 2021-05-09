#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Data.hpp"
#include "Dungeon.hpp"

#include <string>
#include <vector>

namespace Player {
  class Player {
    public:
      int floor;
      Dungeon::Coordinates coordinates;
      Dungeon::Dungeon *dungeon;
      std::vector<std::string> discovered_commands;
      Player();
      int getHealth();
      int modifyHealth(int);
    private:
      int level;
      int health;
  };
}

#endif