#include "Dungeon.hpp"

namespace Dungeon {
  Room::Room() {
    is_discovered = false;
    /*
     * Variant definitions:
     *   0 - Not generated/inaccessable
     *   1 - Generated, generic type
     *   2 - Entrance room
     *   3 - Exit room
     */  
    variant = 0;
  }
}