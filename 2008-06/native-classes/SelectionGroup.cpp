#include "SelectionGroup.h"
#include "v8tree/Instance.h"
#include <algorithm>

namespace RBX {
void SelectionGroup::add(Instance* instance)
{
    const Reflection::ClassDescriptor* key = &instance->getDescriptor();
    (*this)[key].push_back(shared_from(instance));
}

void SelectionGroup::remove(Instance* instance)
{
    const Reflection::ClassDescriptor* key = &instance->getDescriptor();
    iterator found = find(key);
    if (found != end()) {
        std::vector<boost::shared_ptr<Instance> >::iterator current =
            std::find(found->second.begin(), found->second.end(), shared_from(instance));
        if (current != found->second.end()) found->second.erase(current);
    }
}
}
