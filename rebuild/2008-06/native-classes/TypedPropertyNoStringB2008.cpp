// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native TypedPropertyDescriptor<T> string members for the property types that have no string form
// (BrickColor, CoordinateFrame): getStringValue 005eecf0 forwards to the out-of-line PropertyDescriptor::getStringValue
// (00491480, Inferred_00491480.cpp); BrickColor::setStringValue 005eedf0 is hasStringValue() then false, the same body as
// TPD_cframe_string.cpp's CoordinateFrame setStringValue (identical-code folded). Addresses from the types' RTTI vtables
// (BrickColor 00821690, CoordinateFrame 00830cc0, slots 7 / 8; work/donorfree-route/rtti_vtable.py).
#include "v8datamodel/BrickColor.h"
#include "G3D/CoordinateFrame.h"
#include "reflection/property.h"

namespace RBX {
namespace Reflection {

// 005eecf0 (vtable 00830cc0 slot 7)
template<>
std::string TypedPropertyDescriptor<G3D::CoordinateFrame>::getStringValue(const DescribedBase* instance) const
{
	return PropertyDescriptor::getStringValue(instance);
}

// 005eecf0 (vtable 00821690 slot 7)
template<>
std::string TypedPropertyDescriptor<BrickColor>::getStringValue(const DescribedBase* instance) const
{
	return PropertyDescriptor::getStringValue(instance);
}

// 005eedf0 (vtable 00821690 slot 8)
template<>
bool TypedPropertyDescriptor<BrickColor>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	hasStringValue();
	return false;
}

}
}
