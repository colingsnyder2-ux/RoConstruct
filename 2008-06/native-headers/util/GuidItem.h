#pragma once
#include "util/Guid.h"

namespace RBX {
// Original Instance RTTI has GuidItem<Instance> as its primary base.
// Fields follow the recovered openrbx GuidItem declaration; the active donor
// Instance stores Guid elsewhere and must not use this candidate yet.
template<class T>
class GuidItem {
public:
    virtual ~GuidItem() {}
private:
    bool registeredGuid;
    Guid guid;
};
}
