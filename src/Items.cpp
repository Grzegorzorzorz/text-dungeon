#include "Items.hpp"

#include <exception>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <nlohmann/json.hpp>
#include <map>
#include <string>
#include <vector>

namespace Items {
  static std::map <std::string, Item> dictionary;
  
  int load_items(std::string executable_path) {
    // Load the fall back item file.
    dictionary["nothing"] = Item {
      "", // Name
      "nothing", // Type
      "nothing", // Subtype
      {} // Attributes 
    };

    // Isolate the items directory with an absolute path.
    std::string item_directory = executable_path;
    item_directory = std::filesystem::absolute(item_directory);
    for (int character = item_directory.length(); character > 0; character--) {
      if (item_directory.back() == '/') {
        break;
      } else {
        item_directory.pop_back();
      }
    }
    item_directory.append("items");

    // Load each JSON file, parse it, and add it to the item dictionary.
    std::vector<std::string> file_names;
    for (auto& file: std::filesystem::directory_iterator(item_directory)) {
      file_names.push_back("");
      file_names.back().append(file.path());
    }

    for (int file = 0; file < file_names.size(); file++) {
      try {
        std::ifstream item_file;
        item_file.open(file_names[file]);
        std::string raw_item_data ((std::istreambuf_iterator<char>(item_file)),(std::istreambuf_iterator<char>()));
        nlohmann::json item_json;

        item_json = nlohmann::json::parse(raw_item_data);
        std::string item_key = item_json["key"].get<std::string>();
        dictionary[item_key] = Item {
          item_json["name"].get<std::string>(),
          item_json["type"].get<std::string>(),
          item_json["subtype"].get<std::string>(),
          item_json["attributes"].get<std::map<std::string, int>>()
        };
      } catch (...) {
        std::cout << "Failed to parse item file: '" << file_names[file] << "'.\n";
      }
    }
    return 0;
  }

  Item get_item(std::string item_name) {
    if (dictionary.contains(item_name)) {
      return dictionary[item_name];
    }
  return dictionary["nothing"];
  }
}