#include "Data.hpp"
#include "Dungeon.hpp"

#include <cstdlib>
#include <ctime>

namespace Dungeon {
  Floor::~Floor() {
    generated_rooms->clear();
  }

  int Floor::getVariant(Coordinates coordinates) {
    return rooms[coordinates.x][coordinates.y].variant;
  }

  int Floor::setVariant(Coordinates coordinates, int variant) {
    rooms[coordinates.x][coordinates.y].variant = variant;
    return 0;
  }

  int Floor::setDiscovered(Coordinates coordinates, bool is_discovered) {
    rooms[coordinates.x][coordinates.y].is_discovered = is_discovered;
    return 0;
  }

  int Floor::generateLayout() {
    const int MAX_BRANCHES = 4;
    Coordinates branches[MAX_BRANCHES];
    for (int branch = 0; branch < MAX_BRANCHES; branch++) {
      branches[branch] = {-1, -1}; 
    }

    // This chooses a random room near the centre of the level to start
    // generation from.
    int working_branch = 0;
    branches[0] = {std::rand() % 2 + 3, std::rand() % 2 + 3};
    rooms[branches[0].x][branches[0].y].variant = 1;
    generated_rooms->push_back({branches[0].x, branches[0].y});
    
    for (int new_rooms = std::rand() % 5 + 7; new_rooms > 0; new_rooms--) {
      // Check for a branch other than the most recently developed to develop
      // for a round-robin approach for adding rooms to the map.
      for (int branch = working_branch + 1; branch != working_branch; branch++) {
        if (branch == MAX_BRANCHES) {
          branch = 0;
        }
        if (branches[branch].x != -1 && branches[branch].y != -1) {
          working_branch = branch;
          break;
        }
      }

      // Check if the rooms surrounding the current room are clear/undeveloped.
      // This will be used to determine where we can place new rooms on the map.
      bool is_clear[4] = {false};
      int clear_directions = 0;
      // North
      if (branches[working_branch].y != 0) {
        if (getVariant({branches[working_branch].x, branches[working_branch].y - 1}) < 1) {
          is_clear[0] = true;
          clear_directions++;
        }
      }
      // East
      if (branches[working_branch].x != 7) {
        if (getVariant({branches[working_branch].x + 1, branches[working_branch].y}) < 1) {
          is_clear[1] = true;
          clear_directions++;
        }
      }
      // South
      if (branches[working_branch].y != 7) {
        if (getVariant({branches[working_branch].x, branches[working_branch].y + 1}) < 1) {
          is_clear[2] = true;
          clear_directions++;
        }
      }
      // West
      if (branches[working_branch].x != 0) {
        if (getVariant({branches[working_branch].x - 1, branches[working_branch].y}) < 1) {
          is_clear[3] = true;
          clear_directions++;
        }
      }
      // Check for empty branch slots (value of {-1, -1}), so we know how many
      // more branches we can add in this rotation.
      int available_branches = 0;
      for (int branch = 0; branch < MAX_BRANCHES; branch++) {
        if (branches[branch].x == -1 && branches[branch].y == -1) {
          available_branches++;
        }
      }
      if (available_branches > clear_directions) {
        available_branches = clear_directions;
      }
      if (available_branches > new_rooms) {
        available_branches = new_rooms;
      }

      // Determine how many branches are to be added.
      int new_branches = 0;
      if (available_branches >= 1) {
        switch (std::rand() % 20) {
          case 0: case 1: case 2: case 3: case 4:
            new_branches = 2;
            break;
        
          case 5: case 6:
            new_branches = 3;
            break;

          case 16: case 17: case 18: case 19:
            new_branches = 0;
            break;
            
          default:
            new_branches = 1;
            break;
        }
      } 
      if (new_branches > available_branches) {
        new_branches = available_branches;
      }

      for (new_branches > 0; available_branches--; new_branches--) {
        // Try to decide a bearing for the new room.
        bool bearing = false;
        Coordinates new_room = {branches[working_branch].x, branches[working_branch].y};
        while (bearing == false) {
          int try_bearing = std::rand() % 4;
          switch (try_bearing) {
            case 0:
              if (is_clear[0] == true) {
                is_clear[0] = false;
                new_room.y--;
                bearing = true;
              }
              break;

            case 1:
              if (is_clear[1] == true) {
                is_clear[1] = false;
                new_room.x++;
                bearing = true;
              }
              break;
        
            case 2:
              if (is_clear[2] == true) {
                is_clear[2] = false;
                new_room.y++;
                bearing = true;
              }
              break;
          
            case 3:
              if (is_clear[3] == true) {
                is_clear[3] = false;
                new_room.x--;
                bearing = true;
              }
              break;
          }
        }
        // Set the new room onto the room array with the default variant of 1.
        rooms[new_room.x][new_room.y].variant = 1;
        generated_rooms->push_back({new_room.x, new_room.y});

        for (int branch = working_branch + 1; branch != working_branch; branch++) {
          if (branch == MAX_BRANCHES) {
            branch = 0;
          }
          if (branches[branch].x == -1 && branches[branch].y == -1) {
            branches[branch] = {new_room.x, new_room.y};
            break;
          }
        }
      }
      branches[working_branch] = {-1, -1};
    }
    assignRoomVariants();
    return 0;
  }
  int Floor::assignRoomVariants() {
    Coordinates room_coordinates = {-1, -1};
    rooms[generated_rooms->at(0).x][generated_rooms->at(0).y].variant = 2;

    room_coordinates = generated_rooms->at(std::rand() %
      (generated_rooms->size() / 4) + (generated_rooms->size() / 4) * 3);
    rooms[room_coordinates.x][room_coordinates.y].variant = 3;

    return 0;
  }
}