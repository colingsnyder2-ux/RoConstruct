// >>> native-status (generated) -- do not edit >>>
// InstanceChildListener | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 5c7f98b6 | roc native-status --write
#include "v8tree/InstanceEvents.h"

namespace RBX {
class RaiseDescendentAdded2 {
    const Instance* notifier;
    Listener<Instance, DescendantAdded>* listener;
public:
    RaiseDescendentAdded2(const Instance* notifier, Listener<Instance, DescendantAdded>* listener)
        : notifier(notifier), listener(listener) {}
    void operator()(Instance* instance) {
        const Instance* receiver = notifier;
        Instance* parent = instance->parent;
        receiver->Notifier<Instance, DescendantAdded>::raise(DescendantAdded(instance, parent), listener);
        instance->for_eachChild(*this);
    }
};

void Instance::onAddListener(Listener<Instance, DescendantAdded>* listener) const {
    for_eachChild(RaiseDescendentAdded2(this, listener));
}

void Instance::onAddListener(Listener<Instance, ChildAdded>* listener) const {
    if (children) {
        boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > values = children.read();
        std::vector<boost::shared_ptr<Instance> >::const_iterator end = values->end();
        std::vector<boost::shared_ptr<Instance> >::const_iterator it = values->begin();
        for (; it != end; ++it)
            Notifier<Instance, ChildAdded>::raise(ChildAdded(it->get()), listener);
    }
}
}
