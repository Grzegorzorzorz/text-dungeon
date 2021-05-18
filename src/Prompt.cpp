#include "Console.hpp"
#include "Prompt.hpp"

#include <iostream>
#include <ncurses.h>
#include <string>
#include <vector>

namespace Prompt {
  static const int HEIGHT = 3;
  static const int WIDTH = 60;
  static const int Y_COORD = 40;
  static const int X_COORD = 0;
  static WINDOW* prompt;

  int initialise() {
    prompt = newwin(HEIGHT, WIDTH, Y_COORD, X_COORD);
    refresh();
    box(prompt, 0, 0);
    wprintw(prompt, "Input");
    wrefresh(prompt);
    return 0;
  }
  
  std::string getInput(std::string user_prompt) {
      std::string command;
      char input[2];
      input[1] = '\0';
      move(Y_COORD + 1, X_COORD + 1);
      for (int character = 1; character < WIDTH - 1; character++) {
            printw(" ");
      }
      move(Y_COORD + 1, X_COORD + 1);
      printw(" > ");
      while (true) {
        input[0] = getch();
        
        if (input[0] == '\n') {
          Console::output(command);
          return command;   
        } else if (input[0] == 127) {
          if (command.size() != 0) {
            command.erase(command.size());
            move(Y_COORD + 1, getcurx(stdscr) - 1);
            printw(" ");
            command.erase(getcurx(stdscr) - 4);
            command.erase(getcurx(stdscr) - 5);
            command.append("");
            move(Y_COORD + 1, getcurx(stdscr) - 1);
          }
        } else {
          if (command.size() <= 53)
          printw(input);
          command.append(input);
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
      std::cout << "New command discovered: \x1b[1;30;42m"
                << command << "\x1b[0m!\n" << std::endl;
      return 1;
    } else {
      return 0;
    }
  }
}