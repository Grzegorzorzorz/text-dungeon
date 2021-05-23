#ifndef DUNGEON_HPP_
#define DUNGEON_HPP_

#include "Data.hpp"

#include <vector>

namespace Dungeon {
  class Room {
    public:
      bool is_discovered;
      /* 
       * Variant definitions:
       *   0 - Empty/not generated
       *   1 - Generated, generic
       *   2 - Ascend room
       *   3 - Descend room
       */
      unsigned int variant;
      Room();
  };

  class Floor {
    public:
      std::vector<Coordinates> *generated_rooms = new std::vector<Coordinates>;
      int getVariant(Coordinates);
      int setVariant(Coordinates, int);
      int setDiscovered(Coordinates, bool);
      ~Floor();
      int generateLayout();
    private:
      int assignRoomVariants();
      Room rooms[8][8];
  };
  
  class Dungeon {
    public:
      std::vector<Floor> floors;
      unsigned int active_floor;
      Dungeon();
      ~Dungeon();
      int createFloor();
  };
}

#endif