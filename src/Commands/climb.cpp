#include "Commands.hpp"
#include "Console.hpp"
#include "Player.hpp"
#include "Prompt.hpp"

#include <string>

namespace Commands {
  int climb(Player::Player &player, std::string command) {
    Prompt::firstUsage("CLIMB");
    command.erase(0, 6);
    if (command.substr(0, 2) == "UP" || command.substr(0, 4) == "DOWN") {
      if (command.substr(0, 2) == "UP") {
        if (player.dungeon->floors[player.floor].getVariant(player.coordinates) == 2) {
          if (player.floor != 0) {
            player.floor--;
            for (int y = 0; y < 8; y++) {
              for (int x = 0; x < 8; x++) {
                if (player.dungeon->floors[player.floor].getVariant({x, y}) == 3) {
                  player.coordinates = {x, y};
                  Console::output("You hauled yourself up the ladder.\n");
                  break;
                }
              }
            }
          } else {
            Console::output("One does not simply leave text dungeon!\n");
            return 3;
          }
        } else {
          if (player.dungeon->floors[player.floor].getVariant(player.coordinates) == 3) {
            Console::output("The ladder here is going down.\n");
            return 2;
          } else {
            Console::output("You need a ladder to climb up on.\n");
            return 2;
          }
        }
      } else {
        if (player.dungeon->floors[player.floor].getVariant(player.coordinates) == 3) {
          player.floor++;
          if (player.dungeon->floors.size() - 1 <= player.floor) {
            player.dungeon->createFloor();
          }
          for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
              if (player.dungeon->floors[player.floor].getVariant({x, y}) == 2) {
                player.coordinates = {x, y};
                Console::output("You slid down the ladder.\n");
                break;
              }
            }
          }
        } else {
          if (player.dungeon->floors[player.floor].getVariant(player.coordinates) == 2) {
            Console::output("The ladder here is going up.\n");
            return 2;
          } else {
            Console::output("You need a ladder to climb down on.\n");
            return 2;
          }
        }
      }
      return 0;
    } else {
      Console::output("Climb up or down?\n");
      return 1;
    }
  }
}