#include "Commands.hpp"
#include "Console.hpp"
#include "Player.hpp"
#include "Prompt.hpp"

#include <iostream>
#include <string>

namespace Commands {
  int move(Player::Player &player, std::string command) {
    Prompt::firstUsage("MOVE");
    command.erase(0, 5);
    if (command == "NORTH") {
      if (player.dungeon->floors[player.floor].getVariant(
          {player.coordinates.x, player.coordinates.y - 1}) != 0) {
            player.coordinates.y--;
            Console::output("You went North.\n");
      }
    } else if (command == "EAST") {
      if (player.dungeon->floors[player.floor].getVariant(
          {player.coordinates.x + 1, player.coordinates.y}) != 0) {
            player.coordinates.x++;
            Console::output("You went East.\n");
      }
    } else if (command == "SOUTH") {
      if (player.dungeon->floors[player.floor].getVariant(
          {player.coordinates.x, player.coordinates.y + 1}) != 0) {
            player.coordinates.y++;
            Console::output("You went South.\n");
      }
    } else if (command == "WEST") {
      if (player.dungeon->floors[player.floor].getVariant(
          {player.coordinates.x - 1, player.coordinates.y}) != 0) {
            player.coordinates.x--;
            Console::output("You went West.\n");
      } 
    }
    return 0;
  }
}