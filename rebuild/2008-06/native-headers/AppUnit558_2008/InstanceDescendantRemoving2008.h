// Inactive 2008-06 declaration used by native-classes/AppUnit558_2008Instance.cpp (lease 'RBX::app unit 00558000 2008').
// v8tree/Instance.h only forward-declares RBX::DescendantRemoving; v8tree/InstanceEvents.h (its owner) does not define
// it yet, so it is defined here until that header adopts the proposal (tests/record_native_app_unit558_2008.py).
// Layout from Instance::onDescendentRemoving 0055ae90: the event is built in place as two shared_ptrs, the removed
// instance copied first (+0x0/+0x4, add-ref of the source count), then shared_from(instance->parent) (+0x8/+0xc), and
// passed by value (0x10 bytes) to Notifier<Instance, DescendantRemoving>::raise 00558660.
#pragma once
// >>> native-status (generated) -- do not edit >>>
// InstanceDescendantRemoving2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 130472c5 | roc native-status --write
#include "v8tree/InstanceEvents.h"

namespace RBX {
struct DescendantRemoving {
    const boost::shared_ptr<Instance> instance;
    const boost::shared_ptr<Instance> parent;
    DescendantRemoving(const boost::shared_ptr<Instance>& value, const boost::shared_ptr<Instance>& owner)
        : instance(value), parent(owner) {}
};
}
