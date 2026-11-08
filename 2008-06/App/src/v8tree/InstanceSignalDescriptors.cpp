// >>> native-status (generated) -- do not edit >>>
// InstanceSignalDescriptors | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src c8200758 | roc native-status --write
#include "v8tree/Instance.h"

namespace RBX {
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_descendentAdded("DescendantAdded", "descendant");
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_descendentRemoving("DescendantRemoving", "descendant");
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_ancestryChanged("AncestryChanged", "child");
}
