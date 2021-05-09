#include "Commands.hpp"
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
            std::cout << "You went North." << std::endl;
      }
    } else if (command == "EAST") {
      if (player.dungeon->floors[player.floor].getVariant(
          {player.coordinates.x + 1, player.coordinates.y}) != 0) {
            player.coordinates.x++;
            std::cout << "You went East." << std::endl;
      }
    } else if (command == "SOUTH") {
      if (player.dungeon->floors[player.floor].getVariant(
          {player.coordinates.x, player.coordinates.y + 1}) != 0) {
            player.coordinates.y++;
            std::cout << "You went South." << std::endl;
      }
    } else if (command == "WEST") {
      if (player.dungeon->floors[player.floor].getVariant(
          {player.coordinates.x - 1, player.coordinates.y}) != 0) {
            player.coordinates.x--;
            std::cout << "You went West." << std::endl;
      } 
    } else {std::cout << "move: invalid direction.";}
    return 0;
  }
}