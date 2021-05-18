#include "Console.hpp"

#include <ncurses.h>
#include <string>
#include <vector>

namespace Console {
  static const int HEIGHT = 40;
  static const int WIDTH = 60;
  static const int Y_COORD = 0;
  static const int X_COORD = 0;
  static WINDOW* console;
  static std::vector<std::string> line_buffer;

  int initialise() {
    console = newwin(HEIGHT, WIDTH, Y_COORD, X_COORD);
    refresh();
    box(console, 0, 0);
    wprintw(console, "Console Log");
    wrefresh(console);
    return 0;
  }

  int output(std::string output) {
    if (line_buffer.size() < HEIGHT - 2) {
      line_buffer.push_back({output});
    } else {
      line_buffer.erase(line_buffer.begin());
      line_buffer.push_back({output});
    }
    for (int line = 0; line < line_buffer.size(); line++) {
      move(Y_COORD + (HEIGHT - 2) - line, X_COORD + 1);
      for (int character = 0; character < WIDTH - 2; character++) {
        printw(" ");
      }
      move(Y_COORD + (HEIGHT - 2) - line, X_COORD + 1);
      char * writable = new char[line_buffer[line_buffer.size() - line - 1].size() + 1];
      std::copy(line_buffer[line_buffer.size() - line - 1].begin(), line_buffer[line_buffer.size() - line - 1].end(), writable);
      writable[line_buffer[line_buffer.size() - line - 1].size()] = '\0';
      printw(writable);
      delete[] writable;
      refresh();
    }
    return 0;
  }
}