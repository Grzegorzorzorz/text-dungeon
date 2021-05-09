#include "Prompt.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace Prompt {
  std::string getCommand() {
      std::string input;
      std::cout << "\n> \x1b[1;0;36m";
      std::getline(std::cin, input);
      std::cout << "\n\x1b[0m";
      return input;
  }

  int firstUsage(std::string command) {
    static std::vector<std::string> previous_commands;
    bool command_used = false;
    for (long unsigned int item = 0; item < previous_commands.size(); item++) {
      if (command == previous_commands[item]) {
        command_used = true;
      }
    }

    if (command_used == false) {
      previous_commands.push_back(command);
      std::cout << "New command discovered: \x1b[1;30;42m"
                << command << "\x1b[0m!\n" << std::endl;
      return 1;
    } else {
      return 0;
    }
  }
}