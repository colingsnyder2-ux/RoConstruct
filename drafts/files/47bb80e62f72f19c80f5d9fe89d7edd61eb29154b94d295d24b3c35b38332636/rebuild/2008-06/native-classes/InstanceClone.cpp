#include "v8tree/Instance.h"
#include "v8xml/XmlElement.h"
#include "v8xml/SerializerV2.h"
#include <memory>

boost::shared_ptr<RBX::Instance> RBX::Instance::clone()
{
    std::auto_ptr<XmlElement> root(SerializerV2::newRootElement());
    root->addChild(write());
    return fromXmlRoot(root.get());
}
