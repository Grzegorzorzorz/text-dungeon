#include "Commands.hpp"
#include "Console.hpp"
#include "Prompt.hpp"

#include <iostream>

namespace Commands {
  int license(Player::Player&, std::string) {
    Prompt::firstUsage("LICENSE");
    Console::output("Dungeon Quest Copyright (C) 2021 Grzegorz Ciolek\nThis program comes with ABSOLUTELY NO WARRANTY; for details see COPYING.\n\nThis is free software, and you are welcome to redistribute it under certain conditions.\n\nThe licence can also be found at:\n<https://www.gnu.org/licenses/>\n");
    return 0;
  }
}