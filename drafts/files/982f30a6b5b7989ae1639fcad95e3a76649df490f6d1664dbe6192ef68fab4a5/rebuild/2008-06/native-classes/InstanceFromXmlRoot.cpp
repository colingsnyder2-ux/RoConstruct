#include "v8tree/Instance.h"
#include "v8xml/SerializerV2.h"

// Original 00559250: isolate XML handles before loading; copy first owner before cleanup.
boost::shared_ptr<RBX::Instance> RBX::Instance::fromXmlRoot(XmlElement* root)
{
    SerializerV2::isolateHandles(root);
    SerializerV2 serializer;
    std::vector<boost::shared_ptr<Instance> > items;
    serializer.loadInstances(root, items);
    if (items.size() == 0)
        return boost::shared_ptr<Instance>();
    return items.front();
}
