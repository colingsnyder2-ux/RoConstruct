// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// TypedPropertyDescriptor<G3D::CoordinateFrame>::readValue (0059acb0)
#include "reflection/property.h"
#include "G3D/CoordinateFrame.h"
#include "v8xml/XmlElement.h"

namespace RBX {
namespace Reflection {

template<>
void TypedPropertyDescriptor<G3D::CoordinateFrame>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		G3D::CoordinateFrame frame;
		float value;
		element->findFirstChildByTag(tag_X)->getValue(value);
		frame.translation.x = value;
		element->findFirstChildByTag(tag_Y)->getValue(value);
		frame.translation.y = value;
		element->findFirstChildByTag(tag_Z)->getValue(value);
		frame.translation.z = value;
		element->findFirstChildByTag(tag_R00)->getValue(value);
		frame.rotation[0][0] = value;
		element->findFirstChildByTag(tag_R01)->getValue(value);
		frame.rotation[0][1] = value;
		element->findFirstChildByTag(tag_R02)->getValue(value);
		frame.rotation[0][2] = value;
		element->findFirstChildByTag(tag_R10)->getValue(value);
		frame.rotation[1][0] = value;
		element->findFirstChildByTag(tag_R11)->getValue(value);
		frame.rotation[1][1] = value;
		element->findFirstChildByTag(tag_R12)->getValue(value);
		frame.rotation[1][2] = value;
		element->findFirstChildByTag(tag_R20)->getValue(value);
		frame.rotation[2][0] = value;
		element->findFirstChildByTag(tag_R21)->getValue(value);
		frame.rotation[2][1] = value;
		element->findFirstChildByTag(tag_R22)->getValue(value);
		frame.rotation[2][2] = value;
		getset->setValue(instance, frame);
	}
}

}
}
