#include "Commands.hpp"
#include "Console.hpp"
#include "Player.hpp"
#include "Prompt.hpp"

#include <string>

namespace Commands {
  int map(Player::Player &player, std::string) {
    Prompt::firstUsage("MAP");
    std::string map_line;
    Console::output("Floor " + std::to_string(player.floor + 1) + std::string(":\n"));
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        if (player.coordinates.x != x || player.coordinates.y != y) {
          switch (player.dungeon->floors[player.floor].getVariant({x, y})) {
          case 0:
            map_line.append("- ");
            break;
        
          case 1:
            map_line.append("x ");
            break;

          case 2:
            map_line.append("^ ");
            break;

          case 3:
            map_line.append("v ");
            break;

          default:
            map_line.append("? ");
            break;
          }
        } else {
          map_line.append("P ");
        }
      }
      map_line.append("\n");
    }
    Console::output(map_line);
    return 0;
  }
}