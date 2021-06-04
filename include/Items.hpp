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

  int load_items(std::string executable_path);
}

#endif