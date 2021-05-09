#ifndef COMMANDS_HPP_
#define COMMANDS_HPP_

#include "Player.hpp"

#include <string>

namespace Commands {
  int parser(std::string, Player::Player&);

  int ascend(Player::Player&, std::string);
  int descend(Player::Player&, std::string);
  int exit();
  int license();
  int map(Player::Player);
  int move(Player::Player&, std::string);
}

#endif