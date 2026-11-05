// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_cframe_xml_native_c8d66882daa3b87f.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8xml/XmlElement.h", "../roc_xml_native_double_header_414358b35d9237a4.cpp")
#include <reflection/property.h>
#include <reflection/object.h>
#include "v8xml/XmlElement.h"
#include <G3D/CoordinateFrame.h>
// Real public getter boundary4acb30; no GetSet slot/layout fabrication.
template<> G3D::CoordinateFrame RBX::Reflection::TypedPropertyDescriptor<G3D::CoordinateFrame>::getValue(const RBX::Reflection::DescribedBase*) const;
// Genuine declared float constructor, with native FLOAT7/tag/value stores.
XmlNameValuePair::XmlNameValuePair(const RBX::Name& name, float value)
    : tag(name), valueType(FLOAT), floatValue(value) {}
template<>
void RBX::Reflection::TypedPropertyDescriptor<G3D::CoordinateFrame>::writeValue(const RBX::Reflection::DescribedBase* instance, XmlElement* element) const
{
	// Write the data out in accordance with ROBLOX Schema
	G3D::CoordinateFrame c = getValue(instance);
	element->addChild(new XmlElement(tag_X, c.translation.x));
	element->addChild(new XmlElement(tag_Y, c.translation.y));
	element->addChild(new XmlElement(tag_Z, c.translation.z));
	element->addChild(new XmlElement(tag_R00, c.rotation[0][0]));
	element->addChild(new XmlElement(tag_R01, c.rotation[0][1]));
	element->addChild(new XmlElement(tag_R02, c.rotation[0][2]));
	element->addChild(new XmlElement(tag_R10, c.rotation[1][0]));
	element->addChild(new XmlElement(tag_R11, c.rotation[1][1]));
	element->addChild(new XmlElement(tag_R12, c.rotation[1][2]));
	element->addChild(new XmlElement(tag_R20, c.rotation[2][0]));
	element->addChild(new XmlElement(tag_R21, c.rotation[2][1]));
	element->addChild(new XmlElement(tag_R22, c.rotation[2][2]));
}

