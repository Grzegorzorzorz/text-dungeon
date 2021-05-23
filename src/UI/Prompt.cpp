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
      std::string command;
      char input[2];
      input[1] = '\0';
      move(Y_COORD + 1, X_COORD + 1);
      for (int character = 1; character < WIDTH - 1; character++) {
            printw(" ");
      }
      move(Y_COORD + 1, X_COORD + 1);
      // Convert string to const char * array to display prompt symbol.
      char *user_prompt = new char[prompt_symbol.size() + 1];
      std::copy(prompt_symbol.begin(), prompt_symbol.end(), user_prompt);
      user_prompt[prompt_symbol.size()] = '\0';
      printw(user_prompt);
      delete[] user_prompt;

      while (true) {
        input[0] = getch();
        
        if (input[0] == '\n') {
          return command;   
        } else if (input[0] == 127) {
          if (command.size() != 0) {
            command.erase(command.size());
            move(Y_COORD + 1, getcurx(stdscr) - 1);
            printw(" ");
            command.erase(getcurx(stdscr) - (prompt_symbol.size() + 1));
            command.erase(getcurx(stdscr) - (prompt_symbol.size() + 2));
            // Add null-termination to string
            command.append("");
            move(Y_COORD + 1, getcurx(stdscr) - 1);
          }
        } else {
          if (command.size() < (WIDTH - prompt_symbol.size() - 3)) {
            printw(input);
            command.append(input);
          }
        }
      }
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