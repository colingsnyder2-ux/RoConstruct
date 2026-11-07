// >>> native-status (generated) -- do not edit >>>
// SelectionBack | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src deb0cea9 | roc native-status --write
#include "v8datamodel/Selection.h"

namespace RBX {

boost::shared_ptr<Instance> Selection::back() const
{
    return selection->size() > 0 ? selection->back() : boost::shared_ptr<Instance>();
}

}
