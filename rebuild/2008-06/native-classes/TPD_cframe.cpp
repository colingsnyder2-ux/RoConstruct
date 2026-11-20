// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /fp:fast
// TypedPropertyDescriptor<G3D::CoordinateFrame>::readValue (0059acb0) / writeValue (0059aeb0)
#include "reflection/property.h"
#include "G3D/CoordinateFrame.h"
#include "v8xml/XmlElement.h"

// INFERRED: 0059aeb0 builds each child in place (tag at +0x10, FLOAT 7 at +0x14, float at +0x18) with no call and no
// EH frame, so the (tag, float) constructor that v8xml/XmlElement.h only declares was inline in the original header.
inline XmlNameValuePair::XmlNameValuePair(const RBX::Name& tag, float value)
	: tag(tag),
	  valueType(FLOAT),
	  floatValue(value)
{
}

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


// 0059aeb0
template<>
void TypedPropertyDescriptor<G3D::CoordinateFrame>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	G3D::CoordinateFrame frame = getValue(instance);
	element->addChild(new XmlElement(tag_X, frame.translation.x));
	element->addChild(new XmlElement(tag_Y, frame.translation.y));
	element->addChild(new XmlElement(tag_Z, frame.translation.z));
	element->addChild(new XmlElement(tag_R00, frame.rotation[0][0]));
	element->addChild(new XmlElement(tag_R01, frame.rotation[0][1]));
	element->addChild(new XmlElement(tag_R02, frame.rotation[0][2]));
	element->addChild(new XmlElement(tag_R10, frame.rotation[1][0]));
	element->addChild(new XmlElement(tag_R11, frame.rotation[1][1]));
	element->addChild(new XmlElement(tag_R12, frame.rotation[1][2]));
	element->addChild(new XmlElement(tag_R20, frame.rotation[2][0]));
	element->addChild(new XmlElement(tag_R21, frame.rotation[2][1]));
	element->addChild(new XmlElement(tag_R22, frame.rotation[2][2]));
}

}
}
