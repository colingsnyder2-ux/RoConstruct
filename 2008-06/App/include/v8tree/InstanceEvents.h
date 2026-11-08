#pragma once
// >>> native-status (generated) -- do not edit >>>
// InstanceEvents | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src fa84d459 | roc native-status --write
#include "v8tree/Instance.h"

namespace RBX {
struct ChildAdded {
    boost::shared_ptr<Instance> child;
    ChildAdded(Instance* value) : child(shared_from(value)) {}
    ChildAdded(const ChildAdded&); // 004116f0
};
struct DescendantAdded {
    const boost::shared_ptr<Instance> instance;
    const boost::shared_ptr<Instance> parent;
    DescendantAdded(Instance* value, Instance* owner)
        : instance(shared_from(value)), parent(shared_from(owner)) {}
};
}
