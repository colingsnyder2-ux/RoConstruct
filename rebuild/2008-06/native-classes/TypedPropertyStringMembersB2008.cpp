// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /fp:fast
// TypedPropertyDescriptor<T> string / XML members that no other native unit defines (donor-free trial,
// rebuild/2008-06/out/donorfree/report-all-native.json). Addresses from each type's RTTI vtable (vtable slots
// 7 getStringValue, 8 setStringValue, 10 writeValue, 11 readValue; work/donorfree-route/rtti_vtable.py). Same shapes as the
// sibling specializations in TypedPropertyScalarMembers.cpp (flags line copied from it).
#include "reflection/property.h"
#include "v8xml/XmlElement.h"
#include "util/ContentProvider.h"
#include "util/MeshId.h"
#include <G3D/Color3.h>
#include <G3D/Color3uint8.h>
#include <G3D/Vector3.h>
#include "util/TextureId.h"
#include "util/Sound.h"

namespace RBX {
namespace Reflection {

// 0056e7e0 (vtable 00815908 slot 11)
template<>
void TypedPropertyDescriptor<int>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		int value;
		if (element->getValue(value))
			getset->setValue(instance, value);
	}
}

// 0056e6e0 (vtable 0080b9e8 slot 11)
template<>
void TypedPropertyDescriptor<bool>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		bool value;
		if (element->getValue(value))
			getset->setValue(instance, value);
	}
}

// 0056e1c0 (vtable 00815dd4 slot 8)
template<>
bool TypedPropertyDescriptor<float>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	float value;
	if (StringConverter<float>::convertToValue(text, value))
	{
		getset->setValue(instance, value);
		return true;
	}
	return false;
}

// 0056f560 (vtable 00832bf4 slot 7)
template<>
std::string TypedPropertyDescriptor<G3D::Color3>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<G3D::Color3>::convertToString(getValue(instance));
}

// 0056f5a0 (vtable 00832bf4 slot 8)
template<>
bool TypedPropertyDescriptor<G3D::Color3>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	G3D::Color3 value;
	if (StringConverter<G3D::Color3>::convertToValue(text, value))
	{
		getset->setValue(instance, value);
		return true;
	}
	return false;
}

// 00597b50 (vtable 008312e0 slot 7)
template<>
std::string TypedPropertyDescriptor<ContentId>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<ContentId>::convertToString(getValue(instance));
}

// 00597bd0 (vtable 008312e0 slot 8)
template<>
bool TypedPropertyDescriptor<ContentId>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	ContentId value;
	if (StringConverter<ContentId>::convertToValue(text, value))
	{
		getset->setValue(instance, value);
		return true;
	}
	return false;
}

// 00597b50 (vtable 00833318 slot 7) - identical-code folded with ContentId
template<>
std::string TypedPropertyDescriptor<MeshId>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<MeshId>::convertToString(getValue(instance));
}

// 00597bd0 (vtable 00833318 slot 8)
template<>
bool TypedPropertyDescriptor<MeshId>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	MeshId value;
	if (StringConverter<MeshId>::convertToValue(text, value))
	{
		getset->setValue(instance, value);
		return true;
	}
	return false;
}

// 0056e0c0 (vtable 008158d4 slot 7)
template<>
std::string TypedPropertyDescriptor<std::string>::getStringValue(const DescribedBase* instance) const
{
	return getValue(instance);
}

// 0056e310 (vtable 00832c28 slot 7)
template<>
std::string TypedPropertyDescriptor<G3D::Vector3>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<G3D::Vector3>::convertToString(getValue(instance));
}

// 00597b50 (vtable 00837810 slot 7) - identical-code folded with ContentId
template<>
std::string TypedPropertyDescriptor<Soundscape::SoundId>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<Soundscape::SoundId>::convertToString(getValue(instance));
}

// 00597bd0 (vtable 00837810 slot 8)
template<>
bool TypedPropertyDescriptor<Soundscape::SoundId>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	Soundscape::SoundId value;
	if (StringConverter<Soundscape::SoundId>::convertToValue(text, value))
	{
		getset->setValue(instance, value);
		return true;
	}
	return false;
}

// 00597b50 (vtable 00832494 slot 7) - identical-code folded with ContentId
template<>
std::string TypedPropertyDescriptor<TextureId>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<TextureId>::convertToString(getValue(instance));
}

// 0056f6e0 (vtable 00832bf4 slot 10): the colour is stored as an unsigned 0xFFRRGGBB (XmlElement type 6 = UINT).
template<>
void TypedPropertyDescriptor<G3D::Color3>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	G3D::Color3uint8 color(getValue(instance));
	element->setValue((unsigned)(0xff000000 + (color.r << 16) + (color.g << 8) + color.b));
}

// 0056f5f0 (vtable 00832bf4 slot 11): packed 0xFFRRGGBB unsigned first (XmlNameValuePair::getValue(unsigned&) 0057c550),
// else the older <R>/<G>/<B> float children (tag_R 0097536c, tag_G 0097533c, tag_B 00975340).
template<>
void TypedPropertyDescriptor<G3D::Color3>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		unsigned packed;
		if (element->getValue(packed))
		{
			G3D::Color3uint8 bytes;
			bytes.r = (unsigned char)(packed >> 16);
			bytes.g = (unsigned char)(packed >> 8);
			bytes.b = (unsigned char)packed;
			G3D::Color3 value(bytes);
			getset->setValue(instance, value);
		}
		else
		{
			const XmlElement* R = element->findFirstChildByTag(tag_R);
			const XmlElement* G = element->findFirstChildByTag(tag_G);
			const XmlElement* B = element->findFirstChildByTag(tag_B);
			G3D::Color3 legacy;
			R->getValue(legacy.r);
			G->getValue(legacy.g);
			B->getValue(legacy.b);
			getset->setValue(instance, legacy);
		}
	}
}

}
}
