#include "Commands.hpp"
#include "Mainloop.hpp"

#include <iostream>
#include <string>

namespace Commands {
  int exit(Player::Player&, std::string) {
    std::string response;
    std::cout << "Really quit? (y/N) > ";
    std::getline(std::cin, response);

    if (response[0] == 'Y' || response[0] == 'y') {
      Mainloop::setOpCode(0);
      return 0;
    }
    return 1;
  }
}