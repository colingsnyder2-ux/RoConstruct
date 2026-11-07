// >>> native-status (generated) -- do not edit >>>
// CPropGridItem | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 06bef08f | roc native-status --write
#include "CPropGrid.h"
#include "reflection/object.h"
#include <algorithm>
#include <boost/bind.hpp>

CPropGrid::Item::Item(const RBX::Reflection::PropertyDescriptor* descriptor, CPropGrid* owner)
    : grid(owner)
{
    addClass(&descriptor->owner);
}

void CPropGrid::Item::addClass(const RBX::Reflection::ClassDescriptor* descriptor)
{
    classes.push_back(descriptor);
    std::for_each(descriptor->derivedClasses_begin(), descriptor->derivedClasses_end(),
                  boost::bind(&Item::addClass, this, _1));
}
