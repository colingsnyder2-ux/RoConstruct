// >>> native-status (generated) -- do not edit >>>
// SelectionFront | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 2aa88ff0 | roc native-status --write
#include "v8datamodel/Selection.h"

boost::shared_ptr<RBX::Instance> RBX::Selection::front() const
{
    return selection->size() > 0 ? *selection->begin() : boost::shared_ptr<Instance>();
}
