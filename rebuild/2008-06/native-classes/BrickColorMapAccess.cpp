// >>> native-status (generated) -- do not edit >>>
// BrickColorMapAccess | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by auto (+1) (deepseek:deepseek-flash)
// <<< native-status | src 16ffac63 | roc native-status --write
#include "v8datamodel/BrickColor.h"
#include <cstdlib>

namespace RBX {
G3D::Color4uint8 BrickColor::color4uint8() const
{
    return BrickMap::singleton().map1.find(number)->second;
}

BrickColor BrickColor::closest(G3D::Color4uint8 color)
{
    Number number = lego_194;
    int closestDistance = 10000;
    std::map<Number, G3D::Color4uint8>::iterator it = BrickMap::singleton().map1.begin();
    std::map<Number, G3D::Color4uint8>::iterator end = BrickMap::singleton().map1.end();
    for (; it != end; ++it) {
        int distance = abs(it->second.r - color.r);
        distance += abs(it->second.g - color.g);
        distance += abs(it->second.b - color.b);
        if (distance < closestDistance) {
            number = it->first;
            if (distance == 0) break;
            closestDistance = distance;
        }
    }
    return BrickColor(number);
}
}
