#include "Commands.hpp"
#include "Console.hpp"
#include "Player.hpp"
#include "Prompt.hpp"
#include "Mainloop.hpp"

namespace Mainloop {
  static int op_code;
  
  int loop(Player::Player &player) {
    /* OP CODE DEFINITIONS:
     *   0 - Exit;
     *   1 - Standard gameplay;
     */
    
    while (op_code != 0){
      while (op_code == 1) {
        std::string command = "";
        command = Prompt::getInput(" > ");
        Console::output("\n > " + command + "\n\n");
        Commands::parser(command, player);
      }
    }
    return 0;
  }

  int setOpCode(int new_op_code) {
    op_code = new_op_code;
    return 0;
  }
}