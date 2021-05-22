#include "Commands.hpp"
#include "Console.hpp"
#include "Prompt.hpp"

#include <iostream>

namespace Commands {
  int license(Player::Player&, std::string) {
    Prompt::firstUsage("LICENSE");
    Console::output("Dungeon Quest Copyright (C) 2021 Grzegorz Ciolek\nThis program comes with ABSOLUTELY NO WARRANTY; for details see COPYING.\nThis is free software, and you are welcome to redistribute it\nunder certain conditions.\nThe licence can also be found at <https://www.gnu.org/licenses/>\n");
    return 0;
  }
}