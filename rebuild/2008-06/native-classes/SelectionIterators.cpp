// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
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

namespace RBX {
Selection::~Selection()
{
}
}

