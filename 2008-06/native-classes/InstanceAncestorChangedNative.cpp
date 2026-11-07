// >>> native-status (generated) -- do not edit >>>
// InstanceAncestorChangedNative | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src d19f3f59 | roc native-status --write
#include "v8tree/Instance.h"

namespace RBX {
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
