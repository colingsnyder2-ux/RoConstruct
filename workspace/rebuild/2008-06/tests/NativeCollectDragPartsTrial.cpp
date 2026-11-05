#include "v8datamodel/PartInstance.h"
#include <boost/weak_ptr.hpp>
#include <vector>
namespace RBX {
void __cdecl collectDragParts(const std::vector<Instance*>& instances, std::vector<boost::weak_ptr<PartInstance> >& parts) {
    for (unsigned i = 0; i < instances.size(); ++i) PartInstance::findParts(instances[i], parts);
}
}
