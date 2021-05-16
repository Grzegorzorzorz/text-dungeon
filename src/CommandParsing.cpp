#include "Commands.hpp"
#include "Mainloop.hpp"
#include "Player.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

namespace Commands {
  int parser(std::string input, Player::Player &player) {
    for (long unsigned int letter = 0; letter < input.size(); letter++) {
      input[letter] = std::toupper(input[letter]);
    }
    
    typedef int (*command_function) (Player::Player&, std::string);
    std::map<std::string, command_function> commands;
    commands["ASCEND"] = Commands::ascend;
    commands["DESCEND"] = Commands::descend;
    commands["EXIT"] = Commands::exit;
    commands["LICENSE"] = Commands::license;
    commands["MAP"] = Commands::map;
    commands["MOVE"] = Commands::move;

    for (int substring_size = input.size(); substring_size > 0; substring_size--) {
      if (commands.contains(input.substr(0, substring_size))) {
        if (input[substring_size] == ' ' || input.substr(0, substring_size) == input) {
          commands[input.substr(0, substring_size)] (player, input);
          return 0;
        }
      }
    }
    std::cout << "Command not recognised." << std::endl;
    return 1;
  }
}