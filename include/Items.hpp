#ifndef ITEMS_HPP_
#define ITEMS_HPP_

#include <map>
#include <string>

namespace Items {
  struct Item {
    std::string name;
    std::string type;
    std::string subtype;
    std::map<std::string, int> attributes;
  };

  struct Slot {
    Item item;
    int quantity;
  };

  int load_items(std::string executable_path);
  Item lookup_item(std::string item_name);
}

#endif