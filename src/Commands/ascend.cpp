#include "Commands.hpp"
#include "Player.hpp"
#include "Prompt.hpp"

#include <iostream>
#include <string>

namespace Commands {
  int ascend(Player::Player &player, std::string) {
    Prompt::firstUsage("ASCEND");
    if (player.dungeon->floors[player.floor].getVariant(player.coordinates) == 2) {
      if (player.floor != 0) {
        player.floor--;
        for (int y = 0; y < 8; y++) {
          for (int x = 0; x < 8; x++) {
            if (player.dungeon->floors[player.floor].getVariant({x, y}) == 3) {
              player.coordinates = {x, y};
              break;
            }
          }
        }
      } else {
        std::cout << "\x1b[1;0;31mOne does not simply leave text dungeon!\x1b[0m\n";
      }
    } else {
      std::cout << "You need a ladder to climb up on.\n";
    }
    return 0;
  }
}
