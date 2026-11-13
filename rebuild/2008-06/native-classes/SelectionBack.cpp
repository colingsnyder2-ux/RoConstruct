// >>> native-status (generated) -- do not edit >>>
// SelectionBack | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src deb0cea9 | roc native-status --write
#include "v8datamodel/Selection.h"

namespace RBX {

boost::shared_ptr<Instance> Selection::back() const
{
    return selection->size() > 0 ? selection->back() : boost::shared_ptr<Instance>();
}

}
