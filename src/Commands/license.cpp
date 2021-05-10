#include "Commands.hpp"
#include "Prompt.hpp"

#include <iostream>

namespace Commands {
  int license(Player::Player&, std::string) {
    Prompt::firstUsage("LICENSE");
    std::cout << "Dungeon Quest Copyright (C) 2021 Grzegorz Ciołek\nThis program comes with ABSOLUTELY NO WARRANTY; for details see COPYING.\nThis is free software, and you are welcome to redistribute it\nunder certain conditions.\nThe licence can also be found at <https://www.gnu.org/licenses/>" << std::endl;
    return 0;
  }
}