#pragma once
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

