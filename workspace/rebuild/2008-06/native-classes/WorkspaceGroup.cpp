#include "v8datamodel/Workspace.h"
#include "v8datamodel/ModelInstance.h"

namespace RBX {

extern template boost::shared_ptr<ModelInstance> Creatable<Instance>::create<ModelInstance>();

boost::shared_ptr<ModelInstance> Workspace::group(std::vector<boost::shared_ptr<Instance> >::const_iterator first,
                                                   std::vector<boost::shared_ptr<Instance> >::const_iterator last) {
    boost::shared_ptr<ModelInstance> result = Creatable<Instance>::create<ModelInstance>();
    result->setParent(this);
    for (; first != last; ++first) (*first)->setParent(result.get());
    return result;
}

}
