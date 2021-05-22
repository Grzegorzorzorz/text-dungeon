#include "Commands.hpp"
#include "Console.hpp"
#include "Player.hpp"
#include "Prompt.hpp"

#include <iostream>
#include <string>

namespace Commands {
  int descend(Player::Player &player, std::string) {
    Prompt::firstUsage("DESCEND");
    if (player.dungeon->floors[player.floor].getVariant(player.coordinates) == 3) {
      player.floor++;
      if (player.dungeon->floors.size() - 1 <= player.floor) {
        player.dungeon->createFloor();
      }
      for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
          if (player.dungeon->floors[player.floor].getVariant({x, y}) == 2) {
            player.coordinates = {x, y};
            break;
          }
        }
      }
    } else {
      Console::output("You need a ladder to climb down on.\n");
    }
    return 0;
  }
}