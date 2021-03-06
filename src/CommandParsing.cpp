#include "Commands.hpp"
#include "Console.hpp"
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
    commands["CLIMB"] = Commands::climb;
    commands["EXIT"] = Commands::exit;
    commands["LICENSE"] = Commands::license;
    commands["MAP"] = Commands::map;
    commands["MOVE"] = Commands::move;
    #define DEV_COMMANDS
    #ifdef DEV_COMMANDS
    commands["DEV"] = Commands::dev;
    #endif

    for (int substring_size = input.size(); substring_size > 0; substring_size--) {
      if (commands.contains(input.substr(0, substring_size))) {
        if (input[substring_size] == ' ' || input.substr(0, substring_size) == input) {
          commands[input.substr(0, substring_size)] (player, input);
          return 0;
        }
      }
    }
    Console::output("I don't understand that.\n");
    return 1;
  }
}