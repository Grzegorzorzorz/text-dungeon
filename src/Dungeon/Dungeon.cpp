#include "Dungeon.hpp"

#include <iostream>
#include <vector>

namespace Dungeon {
  Dungeon::Dungeon() {
    active_floor = 0;
    createFloor();
  }

  Dungeon::~Dungeon(){
    floors.clear();
  }

  int Dungeon::createFloor() {
    floors.push_back({});
    floors[floors.size() - 1].generateLayout();
    return 0;
  }
}