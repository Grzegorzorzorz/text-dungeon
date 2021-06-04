#include "Console.hpp"
#include "Prompt.hpp"

#include <iostream>
#include <ncurses.h>
#include <string>
#include <vector>

namespace Prompt {
  static int HEIGHT = 3;
  static int WIDTH = 60;
  static int Y_COORD = 40;
  static int X_COORD = 0;
  static WINDOW* PROMPT;

  int initialise(int height, int width, int y_coord, int x_coord) {
    HEIGHT = height;
    WIDTH = width;
    Y_COORD = y_coord;
    X_COORD = x_coord;
    
    PROMPT = newwin(HEIGHT, WIDTH, Y_COORD, X_COORD);
    refresh();
    box(PROMPT, 0, 0);
    wprintw(PROMPT, "Input");
    wrefresh(PROMPT);
    return 0;
  }
  
  std::string getInput(std::string prompt_symbol) {
    // Clear the prompt.
    move(Y_COORD + 1, X_COORD + 1);
    for (int character = 1; character < WIDTH - 1; character++) {
      printw(" ");
    }
    move(Y_COORD + 1, X_COORD + 1);
    
    // Display prompt symbol.
    char *printable_prompt = new char[prompt_symbol.size() + 1];
    std::copy(prompt_symbol.begin(), prompt_symbol.end(), printable_prompt);
    printable_prompt[prompt_symbol.size()] = '\0';
    printw(printable_prompt);
    delete[] printable_prompt;

    std::string user_input = "";
    char last_char[2];
    last_char[1] = '\0';
    
    bool do_input = true;
    while (do_input == true) {
      last_char[0] = getch();

      switch (last_char[0]) {
        case 0x0A: // New line
          do_input = false;
          break;
        
        case 0x7F: // Backspace
          if (user_input.size() != 0) {
            user_input.erase(user_input.size() - 1);
            user_input.append("");

            move(Y_COORD + 1, getcurx(stdscr) - 1);
            printw(" ");
            move(Y_COORD + 1, getcurx(stdscr) - 1);
          }
          break;

        default:
          if (last_char[0] >= 0x20 && last_char[0] <= 0x7E) {
            if (user_input.size() < WIDTH - prompt_symbol.size() - 3) {
              printw(last_char);
              user_input.append(last_char);
            }
          }
          break;
      }
    }
    return user_input;  
  }

  int firstUsage(std::string command) {
    static std::vector<std::string> previous_commands;
    bool command_used = false;
    for (long unsigned int item = 0; item < previous_commands.size(); item++) {
      if (command == previous_commands[item]) {
        command_used = true;
      }
    }

    if (command_used == false) {
      previous_commands.push_back(command);
      Console::output("New command discovered: " + command + std::string("\n\n"));
      return 1;
    } else {
      return 0;
    }
  }
}