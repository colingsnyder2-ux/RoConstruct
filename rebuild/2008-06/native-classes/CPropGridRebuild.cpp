// >>> native-status (generated) -- do not edit >>>
// CPropGridRebuild | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 82bb43f0 | roc native-status --write
#include "CPropGrid.h"
#include "reflection/object.h"
#include <algorithm>
#include <boost/bind.hpp>

void CPropGrid::rebuild(const RBX::Reflection::ClassDescriptor* descriptor)
{
    boost::recursive_mutex::scoped_lock lock(RBX::Reflection::sync());
    std::for_each(descriptor->derivedClasses_begin(), descriptor->derivedClasses_end(),
                  boost::bind(&CPropGrid::rebuild, this, _1));
    std::for_each(descriptor->RBX::Reflection::PropertyContainer::descriptors_begin(),
                  descriptor->RBX::Reflection::PropertyContainer::descriptors_end(),
                  boost::bind(&CPropGrid::addProperty, this, descriptor, _1));
}
