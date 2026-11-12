// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Decal.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Decal.h"

#include "reflection/property.h"
#include "util/Utilities.h"
#include "v8xml/XmlElement.h"

namespace RBX {

char sTexture[] = "Texture";

char sDecal[] = "Decal";

using namespace Reflection;

const PropDescriptor<Decal, TextureId> Decal::prop_Texture(
	"Texture", "Appearance", &Decal::getTexture, &Decal::setTexture
);

const PropDescriptor<Decal, float> Decal::prop_Specular(
	"Specular", "Appearance", &Decal::getSpecular, &Decal::setSpecular
);

const PropDescriptor<Decal, float> Decal::prop_Shiny("Shiny", "Appearance", &Decal::getShiny, &Decal::setShiny);

const PropDescriptor<Texture, float> Texture::prop_StudsPerTileU(
	"StudsPerTileU", "Appearance", &Texture::getStudsPerTileU, &Texture::setStudsPerTileU
);

const PropDescriptor<Texture, float> Texture::prop_StudsPerTileV(
	"StudsPerTileV", "Appearance", &Texture::getStudsPerTileV, &Texture::setStudsPerTileV
);

// FUNCTION: WEBSERVICE 0x100ff530 FOLDED
// FUNCTION: ROBLOX 0x005ac0a0 FOLDED
template <>
std::string StringConverter<TextureId>::convertToString(const TextureId& value)
{
	return value.toString();
}

// FUNCTION: WEBSERVICE 0x100ff580 FOLDED
// FUNCTION: ROBLOX 0x005ac0c0 FOLDED
template <>
bool StringConverter<TextureId>::convertToValue(const std::string& text, TextureId& value)
{
	value = TextureId(text);
	return true;
}

// FUNCTION: WEBSERVICE 0x10041750 FOLDED
// FUNCTION: ROBLOX 0x00620390 FOLDED
template <>
void Reflection::TypedPropertyDescriptor<TextureId>::writeValue(
	const DescribedBase* instance, XmlElement* element
) const
{
	element->setValue(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
template <>
bool Reflection::TypedPropertyDescriptor<TextureId>::hasStringValue() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x100417d0 FOLDED
// FUNCTION: ROBLOX 0x005a8230 FOLDED
template <>
std::string Reflection::TypedPropertyDescriptor<TextureId>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<TextureId>::convertToString(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x100ff890
// FUNCTION: ROBLOX 0x006202c0 FOLDED
template <>
void Reflection::TypedPropertyDescriptor<TextureId>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		ContentId value;
		if (element->getValue(value)) {
			setValue(instance, TextureId(value));
		}
	}
}

// FUNCTION: WEBSERVICE 0x100ff960 FOLDED
// FUNCTION: ROBLOX 0x005ac440 FOLDED
template <>
bool Reflection::TypedPropertyDescriptor<TextureId>::setStringValue(
	DescribedBase* instance, const std::string& text
) const
{
	TextureId value;
	if (StringConverter<TextureId>::convertToValue(text, value)) {
		setValue(instance, value);
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100fff70
// FUNCTION: ROBLOX 0x005acae0
Decal::Decal() : specular(0.0f), shiny(20.0f)
{
	setName("Decal");
}

// FUNCTION: WEBSERVICE 0x10100170
// FUNCTION: ROBLOX 0x005acce0
void Decal::setTexture(TextureId value)
{
	if (texture != value) {
		texture = value;
		raisePropertyChanged(prop_Texture);
	}
}

// FUNCTION: WEBSERVICE 0x101001f0
// FUNCTION: ROBLOX 0x005acd60
void Decal::setSpecular(float value)
{
	if (specular != value && value >= 0.0f) {
		specular = value;
		raisePropertyChanged(prop_Specular);
	}
}

// FUNCTION: WEBSERVICE 0x10100230
// FUNCTION: ROBLOX 0x005acda0
void Decal::setShiny(float value)
{
	if (shiny != value && value > 0.0f) {
		shiny = value;
		raisePropertyChanged(prop_Shiny);
	}
}

// FUNCTION: WEBSERVICE 0x10100270
// FUNCTION: ROBLOX 0x005acde0
void Texture::setStudsPerTileU(float value)
{
	if (studsPerTile.x != value && value > 0.0f) {
		studsPerTile.x = value;
		raisePropertyChanged(prop_StudsPerTileU);
	}
}

// FUNCTION: WEBSERVICE 0x101002b0
// FUNCTION: ROBLOX 0x005ace20
void Texture::setStudsPerTileV(float value)
{
	if (studsPerTile.y != value && value > 0.0f) {
		studsPerTile.y = value;
		raisePropertyChanged(prop_StudsPerTileV);
	}
}

// FUNCTION: WEBSERVICE 0x101003c0
// FUNCTION: ROBLOX 0x005acef0
Texture::Texture() : studsPerTile(2.0f, 2.0f)
{
	setName("Texture");
}

namespace Reflection {

// FUNCTION: WEBSERVICE 0x1012dd60 FOLDED
template <>
const Type& Type::singleton<TextureId>()
{
	return singleton<ContentId>();
}

} // namespace Reflection

} // namespace RBX

template class RBX::FactoryProduct<RBX::Decal, RBX::FaceInstance, RBX::sDecal>;
template class RBX::Reflection::
	Described<RBX::Decal, RBX::sDecal, RBX::FactoryProduct<RBX::Decal, RBX::FaceInstance, RBX::sDecal> >;
template class RBX::DescribedCreatable<RBX::Decal, RBX::FaceInstance, RBX::sDecal>;
template class RBX::FactoryProduct<RBX::Texture, RBX::Decal, RBX::sTexture>;
template class RBX::Reflection::
	Described<RBX::Texture, RBX::sTexture, RBX::FactoryProduct<RBX::Texture, RBX::Decal, RBX::sTexture> >;
template class RBX::DescribedCreatable<RBX::Texture, RBX::Decal, RBX::sTexture>;
