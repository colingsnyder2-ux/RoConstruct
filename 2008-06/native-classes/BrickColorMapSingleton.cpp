// >>> native-status (generated) -- do not edit >>>
// BrickColorMapSingleton | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 3fd94132 | roc native-status --write
#include "v8datamodel/BrickColor.h"

namespace RBX {
BrickColor::BrickMap& BrickColor::BrickMap::singleton()
{
    static BrickMap map;
    return map;
}
}
