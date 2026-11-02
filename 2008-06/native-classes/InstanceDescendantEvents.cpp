// Inactive candidate: listener and signal ABI still under investigation.
#include "v8tree/Instance.h"

namespace RBX {
struct DescendantAdded {
    const boost::shared_ptr<Instance> instance;
    const boost::shared_ptr<Instance> parent;
    DescendantAdded(Instance* value, Instance* owner)
        : instance(shared_from(value)), parent(shared_from(owner)) {}
};
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
