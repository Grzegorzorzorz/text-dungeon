#include "Commands.hpp"
#include "Mainloop.hpp"
#include "Player.hpp"

#include <algorithm>
#include <iostream>
#include <string>

namespace Commands {
  int parser(std::string command, Player::Player &player) {
    for (long unsigned int letter = 0; letter < command.size(); letter++) {
      command[letter] = std::toupper(command[letter]);
    }

    if (command.substr(0, 3) == "MAP") {
      Commands::map(player);
      return 0;
    } else if (command.substr(0, 4) == "EXIT") {
      Commands::exit();
      return 0;
    } else if (command.substr(0, 7) == "LICENSE") {
      Commands::license();
      return 0;
    } else if (command.substr(0, 4) == "MOVE") {
      Commands::move(player, command);
      return 0;
    } else if (command.substr(0, 7) == "DESCEND") {
      Commands::descend(player, command);
    } else if (command.substr(0, 6) == "ASCEND") {
      Commands::ascend(player, command);
    } else {
      std::cout << "Command not recognised." << std::endl;
      return 1;
    }
  }
}