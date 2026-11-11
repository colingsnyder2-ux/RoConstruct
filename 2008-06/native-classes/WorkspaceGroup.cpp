// >>> native-status (generated) -- do not edit >>>
// WorkspaceGroup | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 3e481797 | roc native-status --write
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
