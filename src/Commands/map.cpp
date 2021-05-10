#include "Commands.hpp"
#include "Player.hpp"
#include "Prompt.hpp"

#include <iostream>
#include <string>

namespace Commands {
  int map(Player::Player &player, std::string) {
    Prompt::firstUsage("MAP");
    std::cout << "\nFloor " << player.floor + 1 << ":\n";
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        if (player.coordinates.x != x || player.coordinates.y != y) {
          switch (player.dungeon->floors[player.floor].getVariant({x, y})) {
          case 0:
            std::cout << "- ";
            break;
        
          case 1:
            std::cout << "x ";
            break;

          case 2:
            std::cout << "^ ";
            break;

          case 3:
            std::cout << "v ";
            break;

          default:
            std::cout << "? ";
            break;
          }
        } else {
          std::cout << "P ";
        }
      }
      std::cout << "\n";
    }
    return 0;
  }
}