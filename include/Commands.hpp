#ifndef COMMANDS_HPP_
#define COMMANDS_HPP_

#include "Player.hpp"

#include <string>

namespace Commands {
  int parser(std::string, Player::Player&);

  int ascend(Player::Player&, std::string);
  int descend(Player::Player&, std::string);
  int exit(Player::Player&, std::string);
  int license(Player::Player&, std::string);
  int map(Player::Player&, std::string);
  int move(Player::Player&, std::string);
}

#endif