/*
 *  Dungeon Quest
 *  Copyright (C) 2021 Grzegorz Ciołek
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "Dungeon.hpp"
#include "Mainloop.hpp"
#include "Player.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  int seed = std::time(NULL);
  std::srand(seed);
  std::cout << "Seed: " << seed << std::endl;

  // TODO: Move the world and player definitions into a game 
  //       initiation function.
  Dungeon::Dungeon *dungeon = new Dungeon::Dungeon;
  Player::Player player;  
  player.dungeon = dungeon;
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      if (dungeon->floors[0].getVariant({x, y}) == 2) {
        player.coordinates = {x, y};
        break;
      }
    }
  }

  Mainloop::setOpCode(1);
  Mainloop::loop(player);
  
  delete dungeon;

  return 0;
}