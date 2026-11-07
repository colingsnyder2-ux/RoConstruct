#include "v8tree/Instance.h"

namespace RBX {
Instance* Instance::findFirstChildByName(const std::string& findName) const
{
    if (!children)
        return NULL;
    const std::vector<boost::shared_ptr<Instance> >& c = *children;
    for (size_t i = 0; i < c.size(); i++) {
        if (c[i]->name == findName)
            return c[i].get();
    }
    return NULL;
}
}
