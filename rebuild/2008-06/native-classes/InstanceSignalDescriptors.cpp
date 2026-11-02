#include "v8tree/Instance.h"

namespace RBX {
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_descendentAdded("DescendantAdded", "descendant");
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_descendentRemoving("DescendantRemoving", "descendant");
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_ancestryChanged("AncestryChanged", "child");
}
