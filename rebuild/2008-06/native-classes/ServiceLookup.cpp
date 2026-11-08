#include "v8tree/Service.h"

size_t RBX::ServiceProvider::newIndex()
{
    static size_t index = 0xffffffff;
    return InterlockedIncrement(reinterpret_cast<LONG*>(&index));
}

boost::shared_ptr<RBX::Instance> RBX::ServiceProvider::findServiceByClassName(const Name& name) const
{
    std::map<const Name*, boost::shared_ptr<Instance> >::const_iterator it = serviceMap.find(&name);
    if (it != serviceMap.end()) return it->second;
    return boost::shared_ptr<Instance>();
}
