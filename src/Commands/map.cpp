#include "Commands.hpp"
#include "Console.hpp"
#include "Player.hpp"
#include "Prompt.hpp"

#include <string>

namespace Commands {
  int map(Player::Player &player, std::string) {
    Prompt::firstUsage("MAP");
    Console::output("Floor " + std::to_string(player.floor + 1) + std::string(":\n"));
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        if (player.coordinates.x != x || player.coordinates.y != y) {
          switch (player.dungeon->floors[player.floor].getVariant({x, y})) {
          case 0:
            Console::output("- ");
            break;
        
          case 1:
            Console::output("x ");
            break;

          case 2:
            Console::output("^ ");
            break;

          case 3:
            Console::output("v ");
            break;

          default:
            Console::output("? ");
            break;
          }
        } else {
          Console::output("P ");
        }
      }
      Console::output("\n");
    }
    return 0;
  }
}