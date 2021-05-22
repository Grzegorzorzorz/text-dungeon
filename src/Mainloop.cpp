#include "Commands.hpp"
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
        Commands::parser(Prompt::getInput(" > "), player);
      }
    }
    return 0;
  }

  int setOpCode(int new_op_code) {
    op_code = new_op_code;
    return 0;
  }
}