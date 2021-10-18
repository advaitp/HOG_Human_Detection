///============================================================================
/// @file        : Tracker.h
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : Tracker.h include file
///============================================================================

#include "Human.h"
#include <unordered_map>

class Box {
 public:
  unordered_map<Human> storage;
  bool is_same(storage);
};
