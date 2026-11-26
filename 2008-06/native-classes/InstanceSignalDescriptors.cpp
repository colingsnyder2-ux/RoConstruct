#include "v8tree/Instance.h"

namespace RBX {
// 007f2b10 / 007f2b30: the original constructs these two before ancestryChanged (007f2b90)
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_childAdded("ChildAdded", "child");
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_childRemoved("ChildRemoved", "child");
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_descendentAdded("DescendantAdded", "descendant");
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_descendentRemoving("DescendantRemoving", "descendant");
Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>
    Instance::event_ancestryChanged("AncestryChanged", "child");
// 007f2bb0: strings 0082da38 "Changed", 0080f0f4 "property"
Reflection::SignalDesc<Instance, void(const Reflection::PropertyDescriptor*)>
    Instance::event_propertyChanged("Changed", "property");
}
