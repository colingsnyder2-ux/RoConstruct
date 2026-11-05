// from server: 78% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Decal.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Decal.h"

#include "reflection/property.h"

namespace RBX {

char sTexture[] = "Texture";

char sDecal[] = "Decal";

using namespace Reflection;

const PropDescriptor<Decal, TextureId> Decal::prop_Texture(
	"Texture",
	"Appearance",
	&RBX::Decal::getTexture,
	&RBX::Decal::setTexture
);

const PropDescriptor<Decal, float> Decal::prop_Specular(
	"Specular",
	"Appearance",
	&RBX::Decal::getSpecular,
	&RBX::Decal::setSpecular
);

const PropDescriptor<Decal, float> Decal::prop_Shiny(
	"Shiny",
	"Appearance",
	&RBX::Decal::getShiny,
	&RBX::Decal::setShiny
);

const PropDescriptor<Texture, float> Texture::prop_StudsPerTileU(
	"StudsPerTileU",
	"Appearance",
	&RBX::Texture::getStudsPerTileU,
	&RBX::Texture::setStudsPerTileU
);

const PropDescriptor<Texture, float> Texture::prop_StudsPerTileV(
	"StudsPerTileV",
	"Appearance",
	&RBX::Texture::getStudsPerTileV,
	&RBX::Texture::setStudsPerTileV
);

// FUNCTION: WEBSERVICE 0x100fff70
Decal::Decal() : specular(0.0f), shiny(20.0f)
{
	setName("Decal");
}

// FUNCTION: WEBSERVICE 0x10100170
void Decal::setTexture(TextureId value)
{
	if (texture != value) {
		texture = value;
		raisePropertyChanged(prop_Texture);
	}
}

// FUNCTION: WEBSERVICE 0x101001f0
void Decal::setSpecular(float value)
{
	if (specular != value && value >= 0.0f) {
		specular = value;
		raisePropertyChanged(prop_Specular);
	}
}

// FUNCTION: WEBSERVICE 0x10100230
void Decal::setShiny(float value)
{
	if (shiny != value && value > 0.0f) {
		shiny = value;
		raisePropertyChanged(prop_Shiny);
	}
}

// FUNCTION: WEBSERVICE 0x10100270
void Texture::setStudsPerTileU(float value)
{
	if (studsPerTile.x != value && value > 0.0f) {
		studsPerTile.x = value;
		raisePropertyChanged(prop_StudsPerTileU);
	}
}

// FUNCTION: WEBSERVICE 0x101002b0
void Texture::setStudsPerTileV(float value)
{
	if (studsPerTile.y != value && value > 0.0f) {
		studsPerTile.y = value;
		raisePropertyChanged(prop_StudsPerTileV);
	}
}

// FUNCTION: WEBSERVICE 0x101003c0
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

template class RBX::FactoryProduct<RBX::Texture, RBX::Decal, RBX::sTexture>;
template class RBX::Reflection::
	Described<RBX::Texture, RBX::sTexture, RBX::FactoryProduct<RBX::Texture, RBX::Decal, RBX::sTexture> >;
template class RBX::DescribedCreatable<RBX::Texture, RBX::Decal, RBX::sTexture>;
