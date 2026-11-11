// >>> native-status (generated) -- do not edit >>>
// CPropGridItem | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src d46c7ffa | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::_bi::value<CPropGrid::Item *>;
template class boost::_mfi::mf1<void,CPropGrid::Item,RBX::Reflection::ClassDescriptor const *>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Reflection::ClassDescriptor const *> >;
template class std::_Vector_const_iterator<RBX::Reflection::ClassDescriptor const *,std::allocator<RBX::Reflection::ClassDescriptor const *> >;
template class std::_Vector_iterator<RBX::Reflection::ClassDescriptor const *,std::allocator<RBX::Reflection::ClassDescriptor const *> >;
template class std::vector<RBX::Reflection::ClassDescriptor const *,std::allocator<RBX::Reflection::ClassDescriptor const *> >;
