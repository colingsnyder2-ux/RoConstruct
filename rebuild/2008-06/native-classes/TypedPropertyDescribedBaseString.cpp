// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native TypedPropertyDescriptor<shared_ptr<DescribedBase> >::getStringValue (inactive; runnable-link
// definition). Flags copied from TypedPropertyNoStringB2008.cpp (the no-string-form getStringValue bodies).
// LuaBridge2008Instance.cpp explicitly instantiates `template class TypedPropertyDescriptor<shared_ptr<DescribedBase> >`,
// whose vtable references this member; reflection/property.h only declares it, so the donor-free link bound a stub.
// The 2008 client has the class's RTTI type descriptor (??_R0 0095afd8, used only by dynamic_casts at 0061a84b /
// 0061aa5b) but no vtable or complete object locator for it, so no original body exists to match.
// INFERRED: a shared_ptr<DescribedBase> has no string form; the body follows the 2008 no-string-form types BrickColor /
// CoordinateFrame (005eecf0: forward to PropertyDescriptor::getStringValue 00491480), which ICF would fold with it.
#include "reflection/property.h"
#include <boost/shared_ptr.hpp>

namespace RBX {
namespace Reflection {

// No original address (see above); same body as 005eecf0.
template<>
std::string TypedPropertyDescriptor<boost::shared_ptr<DescribedBase> >::getStringValue(const DescribedBase* instance) const
{
	return PropertyDescriptor::getStringValue(instance);
}

}
}
