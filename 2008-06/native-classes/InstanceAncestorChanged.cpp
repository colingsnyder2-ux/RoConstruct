#include "v8tree/Instance.h"

namespace RBX {
struct AncestorChanged {
    Instance* child;
    Instance* oldParent;
    Instance* newParent;
};

void Instance::onAncestorChanged(const AncestorChanged& event)
{
    typedef std::vector<boost::shared_ptr<Instance> >::const_iterator Iterator;
    if (children) {
        boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > copy = children.read();
        for (Iterator it = copy->begin(); it != copy->end(); ++it)
            (*it)->onAncestorChanged(event);
    }
    event_ancestryChanged.fire(this, shared_from(event.child));
    Notifier<Instance, AncestorChanged>::raise(event);
}
}
