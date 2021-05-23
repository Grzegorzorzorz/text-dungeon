#include "Commands.hpp"
#include "Console.hpp"
#include "Dungeon.hpp"
#include "Player.hpp"

#include <cstdlib>
#include <string>

namespace Commands {
  int dev(Player::Player &player, std::string command) {
    Console::output("Please note that using using these commands is cheating ;)\n");
    command.erase(0, 4);
    Dungeon::Floor *player_floor = &player.dungeon->floors[player.floor];
    if (command == "DISCOVER") {
      for (int room = 0; room < player_floor->generated_rooms->size(); room++) {
        player_floor->setDiscovered(
          {player_floor->generated_rooms->at(room).x, player_floor->generated_rooms->at(room).y},
          true
        );
      }
      Console::output("\nDiscovered all generated rooms on floor!\n");
    } else if (command == "LONG TEXT") {
      std::string random_words[25] = {
        "I",
        "shop",
        "cow",
        "dog",
        "house",
        "went",
        "purchased",
        "a",
        "the",
        "your",
        "mum",
        "how",
        "when",
        "saw",
        "throne",
        "magic",
        "hot",
        "cold",
        "he",
        "walked",
        "she",
        "they",
        "all",
        "decided",
        "ball",
      };
      for (int word = 0; word < 100; word++) {
        Console::output(random_words[std::rand() % 25] + " ");
      }
    }
    return 0;
  }
}