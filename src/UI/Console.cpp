#include "Console.hpp"

#include <ncurses.h>
#include <string>
#include <vector>

namespace Console {
  static int HEIGHT = 40;
  static int WIDTH = 60;
  static int Y_COORD = 0;
  static int X_COORD = 0;
  static WINDOW* console;
  static std::vector<std::string> line_buffer;

  int initialise(int height, int width, int x_coord, int y_coord) {
    HEIGHT = height;
    WIDTH = width;
    X_COORD = x_coord;
    Y_COORD = y_coord;
    console = newwin(HEIGHT, WIDTH, Y_COORD, X_COORD);
    refresh();
    box(console, 0, 0);
    wprintw(console, "Console Log");
    wrefresh(console);

    for (int lines = 0; lines < HEIGHT - 2; lines++) {
      line_buffer.push_back({""});
    }
    return 0;
  }

  int output(std::string output, bool load_buffer) {
    bool is_new_line = false;
    for (int character = 0; character < output.size(); character++) {
      if (output[character ] == '\n') { // New line
        output.erase(0, character);
        is_new_line = true;
      }
      if (line_buffer.back().size() == WIDTH - 2) { // Carriage return / line wrapping
        output.erase(0, character - 1);
        is_new_line = true;
      }
      if (is_new_line == true) {
        // Add new line to the line buffer.
        character = 0;
        line_buffer.erase(line_buffer.begin());
        line_buffer.push_back({""});
        is_new_line = false;
        // Remove leading space if present on line wrap.
        if (output[1] == ' ') {
          output.erase(1, 1);
        } 
      } else {
        line_buffer.back().append(1, output[character]);
      }
    }

    if (load_buffer == false) {
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
    }
    return 0;
  }
}