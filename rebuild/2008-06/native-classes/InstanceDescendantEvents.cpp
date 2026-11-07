// Inactive candidate: listener and signal ABI still under investigation.
// >>> native-status (generated) -- do not edit >>>
// InstanceDescendantEvents | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src e833f3be | roc native-status --write
#include "v8tree/InstanceEvents.h"

namespace RBX {
struct DescendantRemoving {
    const boost::shared_ptr<Instance> instance;
    const boost::shared_ptr<Instance> parent;
    DescendantRemoving(const boost::shared_ptr<Instance>& value, const boost::shared_ptr<Instance>& owner)
        : instance(value), parent(owner) {}
};
#if !defined(NATIVE_DESCENDANT_HELPERS_ONLY) && !defined(NATIVE_DESCENDANT_REMOVE_ONLY)
void Instance::onDescendentAdded(Instance* instance)
{
    if (Notifier<Instance, DescendantAdded>::hasListeners())
        Notifier<Instance, DescendantAdded>::raise(DescendantAdded(instance, instance->getParent()));
    event_descendentAdded.fire(this, shared_from(instance));
}
#endif

#if !defined(NATIVE_DESCENDANT_HELPERS_ONLY) && !defined(NATIVE_DESCENDANT_ADD_ONLY)
void Instance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
{
    event_descendentRemoving.fire(this, instance);
    if (Notifier<Instance, DescendantRemoving>::hasListeners())
        Notifier<Instance, DescendantRemoving>::raise(DescendantRemoving(instance, shared_from(instance->parent)));
}
#endif
}
