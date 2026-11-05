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
