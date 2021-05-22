#ifndef PROMPT_HPP_
#define PROMPT_HPP_

#include <ncurses.h>
#include <string>

namespace Prompt {
  int initialise();
  std::string getInput(std::string);
  int firstUsage(std::string);
}

#endif