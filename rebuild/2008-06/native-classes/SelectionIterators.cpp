// >>> native-status (generated) -- do not edit >>>
// SelectionIterators | 2008-06 | selection unverified
// unmapped (no binary link) | by -
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
