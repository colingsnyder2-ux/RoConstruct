#include "v8datamodel/BrickColor.h"

namespace RBX {
BrickColor::BrickMap& BrickColor::BrickMap::singleton()
{
    static BrickMap map;
    return map;
}
}
