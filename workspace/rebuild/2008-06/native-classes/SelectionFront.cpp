// >>> native-status (generated) -- do not edit >>>
// SelectionFront | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by Espeon (roc repair)
// <<< native-status | src 2aa88ff0 | roc native-status --write
#include "v8datamodel/Selection.h"

boost::shared_ptr<RBX::Instance> RBX::Selection::front() const
{
    return selection->size() > 0 ? *selection->begin() : boost::shared_ptr<Instance>();
}
