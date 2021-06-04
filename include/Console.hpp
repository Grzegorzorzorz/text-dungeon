#ifndef CONSOLE_HPP_
#define CONSOLE_HPP_

#include <string>

namespace Console {
  int initialise(int height, int width, int x_coord, int y_coord);
  int output(std::string output, bool load_buffer = false);
}

#endif