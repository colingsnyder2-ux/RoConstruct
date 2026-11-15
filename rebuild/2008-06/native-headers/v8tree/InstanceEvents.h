#pragma once
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
