#include "Commands.hpp"
#include "Console.hpp"
#include "Mainloop.hpp"
#include "Prompt.hpp"

#include <iostream>
#include <string>

namespace Commands {
  int exit(Player::Player&, std::string) {
    std::string response;
    Console::output("Are you sure you want to leave? (y/N) > ");
    response = Prompt::getInput(" (y/N) > ");
    Console::output(response + "\n");

    if (response[0] == 'Y' || response[0] == 'y') {
      Mainloop::setOpCode(0);
      return 0;
    }
    return 1;
  }
}