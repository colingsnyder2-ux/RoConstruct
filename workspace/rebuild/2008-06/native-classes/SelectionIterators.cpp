// >>> native-status (generated) -- do not edit >>>
// SelectionIterators | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 7c2d88e3 | roc native-status --write
#include "v8datamodel/Selection.h"

typedef std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator SelectionIterator;

SelectionIterator RBX::Selection::begin() const
{
    return selection->begin();
}

SelectionIterator RBX::Selection::end() const
{
    return selection->end();
}
