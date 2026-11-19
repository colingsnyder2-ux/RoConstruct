// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// TypedPropertyDescriptor<G3D::CoordinateFrame>::setStringValue (005eedf0): CoordinateFrame has no string form.
// INFERRED: the asm only calls vtable slot 6 (no arguments, hasStringValue in the declared order) and returns false.
#include "G3D/CoordinateFrame.h"
#include "reflection/property.h"

namespace RBX {
namespace Reflection {

template<>
bool TypedPropertyDescriptor<G3D::CoordinateFrame>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	hasStringValue();
	return false;
}

}
}
