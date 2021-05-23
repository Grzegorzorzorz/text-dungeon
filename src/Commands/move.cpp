#include "Commands.hpp"
#include "Console.hpp"
#include "Player.hpp"
#include "Prompt.hpp"

#include <iostream>
#include <map>
#include <string>

namespace Commands {
  int move(Player::Player &player, std::string command) {
    Prompt::firstUsage("MOVE");
    command.erase(0, 5);
    std::map<std::string, int> direction;
    direction["NORTH"] = 0;
    direction["EAST"] = 1;
    direction["SOUTH"] = 2;
    direction["WEST"] = 3;

    if (direction.contains(command)) {
      switch (direction[command]) {
        case 0:
          if (player.dungeon->floors[player.floor].getVariant({player.coordinates.x, player.coordinates.y - 1}) != 0) {
            player.coordinates.y--;
            Console::output("You went North.\n");
          }
          break;

        case 1:
          if (player.dungeon->floors[player.floor].getVariant({player.coordinates.x + 1, player.coordinates.y}) != 0) {
            player.coordinates.x++;
            Console::output("You went East.\n");
          }
          break;
        
        case 2:
          if (player.dungeon->floors[player.floor].getVariant({player.coordinates.x, player.coordinates.y + 1}) != 0) {
            player.coordinates.y++;
            Console::output("You went South.\n");
          }
          break;
        
        case 3:
          if (player.dungeon->floors[player.floor].getVariant({player.coordinates.x - 1, player.coordinates.y}) != 0) {
            player.coordinates.x--;
            Console::output("You went West.\n");
          }
          break;   
      }
    } else {
      Console::output("I don't recognise that direction.\n");
      return 1;
    }
    return 0;
  }
}