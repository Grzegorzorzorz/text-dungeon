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

    line_buffer.push_back({""});
    return 0;
  }

  int output(std::string output) {
    /*
    Values that need to be tested:
    - If a new line is requested.
    - If a line is too long
    ^-- Ideally, splice the line at the most recent space character.
    */

    for (int character = 0; character < output.size(); character++) {
      bool new_line = false;
      
      // This code here is pretty unreadable.
      // I wrote it yesterday and don't understand it.
      // I'll probably do a refactor later.

      // Check if a new-line has been requested, or if the line is overrunning width.
      // If so, add a new line to the line buffer, and continue output there.
      
      // RIP hyphenation, we won't miss your incorrect implementation.
      
      if (output[character] == '\n' || line_buffer.back().size() == WIDTH -2) {
        if (output[character] == '\n') {
          output.erase(0, character);
          new_line = true;  
        } else {
          output.erase(0, character - 1);
        }
        character = 0;
        if (output[1] == ' ') {
          output.erase(1, 1);
        }

        if (line_buffer.size() < HEIGHT - 2) {
          line_buffer.push_back({""});
        } else {
          line_buffer.erase(line_buffer.begin());
          line_buffer.push_back({""});
        }
      } else {
        line_buffer.back().append(1, output[character]);
      }
    }


    // Line output system: line by line, starting from the bottom.
    // Creates a nice scroll effect ;)
    //
    // Not the lightest, could do with a rework.
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