#pragma once
// >>> native-status (generated) -- do not edit >>>
// GuidItem | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src c5b82919 | roc native-status --write
#include "util/Guid.h"

namespace RBX {
// Original Instance RTTI has GuidItem<Instance> as its primary base.
// Virtual slot follows roc_instance_guid_callback_5e8a3f385d045a38.cpp; the active donor
// Instance stores Guid elsewhere and must not use this candidate yet.
template<class T>
class __declspec(novtable) GuidItem {
public:
    GuidItem() : registeredGuid(false) {}
    ~GuidItem();
    void registerGuid();
protected:
    virtual void onGuidChanged() {}
    bool registeredGuid;
    Guid guid;
};
}

