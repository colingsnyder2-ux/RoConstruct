#include "v8tree/Instance.h"
#include "v8xml/XmlElement.h"
#include "v8xml/SerializerV2.h"
#include <memory>

boost::shared_ptr<RBX::Instance> RBX::Instance::clone()
{
    XmlElement* rawRoot = SerializerV2::newRootElement();
    rawRoot->addChild(write());
    std::auto_ptr<XmlElement> root(rawRoot);
    return fromXmlRoot(root.get());
}
