// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /fp:fast
// TypedPropertyDescriptor<T> string / XML members for bool, int, float, G3D::Vector3, G3D::Vector2int16 and
// RBX::BrickColor that no other native unit defines. Flags line copied from the sibling specialization unit
// TypedPropertySpecializations2008.cpp (same 0056e0c0..0056e900 run). Identity: registry decorated names
// (?getStringValue@?$TypedPropertyDescriptor@_N@..., ?writeValue@?$TypedPropertyDescriptor@M@..., etc.); each body
// calls its type's StringConverter (005bde30 / 005bde60 bool, 005be040 float, 005bdef0 / 005be5a0 int, 005bebb0
// Vector3, 005be8a0 Vector2int16) or the XmlNameValuePair accessors (getValue float 0057c610, int 0057c4f0,
// clearValue 0057c2d0, isXsiNil 0057c810) and the getset vtable slots +8 (getValue) / +0xc (setValue).
#include "reflection/property.h"
#include "v8xml/XmlElement.h"
#include "v8datamodel/BrickColor.h"
#include <G3D/Vector3.h>
#include <G3D/Vector2int16.h>

namespace RBX {
namespace Reflection {

// 0056e100
template<>
std::string TypedPropertyDescriptor<bool>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<bool>::convertToString(getValue(instance));
}

// 0056e140
template<>
bool TypedPropertyDescriptor<bool>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	bool value;
	if (StringConverter<bool>::convertToValue(text, value))
	{
		getset->setValue(instance, value);
		return true;
	}
	return false;
}

// 0056e180
template<>
std::string TypedPropertyDescriptor<float>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<float>::convertToString(getValue(instance));
}

// 0056e290
template<>
std::string TypedPropertyDescriptor<int>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<int>::convertToString(getValue(instance));
}

// 0056e2d0
template<>
bool TypedPropertyDescriptor<int>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	int value;
	if (StringConverter<int>::convertToValue(text, value))
	{
		getset->setValue(instance, value);
		return true;
	}
	return false;
}

// 0056e350
template<>
bool TypedPropertyDescriptor<G3D::Vector3>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	G3D::Vector3 value;
	if (StringConverter<G3D::Vector3>::convertToValue(text, value))
	{
		getset->setValue(instance, value);
		return true;
	}
	return false;
}

// 0056e510
template<>
std::string TypedPropertyDescriptor<G3D::Vector2int16>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<G3D::Vector2int16>::convertToString(getValue(instance));
}

// 0056e660
template<>
void TypedPropertyDescriptor<float>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		float value;
		if (element->getValue(value))
			getset->setValue(instance, value);
	}
}

// 0056e6a0
template<>
void TypedPropertyDescriptor<float>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

// 0056e7b0
template<>
void TypedPropertyDescriptor<bool>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

// 0056e820
template<>
void TypedPropertyDescriptor<int>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

// 0056f750: reads the colour number (getValue(int&) 0057c4f0) and converts it with BrickColor(int) 005b6090.
template<>
void TypedPropertyDescriptor<BrickColor>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		int value;
		if (element->getValue(value))
			setValue(instance, BrickColor(value));
	}
}

// 0056f7a0: stores the colour number as an INT (type 5) value.
template<>
void TypedPropertyDescriptor<BrickColor>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance).asInt());
}

// 00445b10: equalValues for float. The target reads a first and compares the second value against the stored
// float (fcomp dword, which needs /fp:fast), the same shape as the double specialization in TPD_double.cpp. Kept
// inline like the in-class property.h body so other units' COMDAT copies do not collide at link time.
template<>
inline bool TypedPropertyDescriptor<float>::equalValues(const DescribedBase* a, const DescribedBase* b) const
{
	const float value = getValue(a);
	return getValue(b) == value;
}

template class TypedPropertyDescriptor<float>; // emits the equalValues specialization through the vtable (as TPD_double.cpp)

}
}
