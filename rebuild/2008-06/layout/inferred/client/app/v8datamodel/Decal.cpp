#include "AppUnit594_2008/TextureIdType2008.h"   // Type::singleton<TextureId> = singleton<ContentId> (005978a0)
#include "v8datamodel/Decal.h"

namespace RBX
{
	char sDecal[] = "Decal";      // 00949c68 (pushed by classDescriptor 00598020)
	char sTexture[] = "Texture";  // 00949c70 (pushed by classDescriptor 00598090)

	// Template members the shared headers only declare (same definitions as SpecialShape.cpp / Team.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	const Reflection::PropDescriptor<Decal, TextureId> Decal::prop_Texture("Texture", "Appearance", &Decal::getTexture, &Decal::setTexture, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<Decal, float> Decal::prop_Specular("Specular", "Appearance", &Decal::getSpecular, &Decal::setSpecular, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<Decal, float> Decal::prop_Shiny("Shiny", "Appearance", &Decal::getShiny, &Decal::setShiny, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<Texture, float> Texture::prop_StudsPerTileU("StudsPerTileU", "Appearance", &Texture::getStudsPerTileU, &Texture::setStudsPerTileU, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<Texture, float> Texture::prop_StudsPerTileV("StudsPerTileV", "Appearance", &Texture::getStudsPerTileV, &Texture::setStudsPerTileV, Reflection::PropertyDescriptor::STANDARD);

	Decal::Decal() : specular(0.0f), shiny(20.0f) { setName("Decal"); }       // 00598400
	Texture::Texture() : studsPerTile(2.0f, 2.0f) { setName("Texture"); }   // 00598870

	void Decal::setTexture(TextureId value)   // 00598610 (ret 0x20: TextureId by value)
	{
		if (texture != value)
		{
			texture = value;
			raisePropertyChanged(prop_Texture);
		}
	}

	void Decal::setSpecular(float value)      // 00598690 (`specular != value` first: fld value; fcom [this+0x164]); 0 <= value
	{
		if (specular != value && value >= 0.0f)
		{
			specular = value;
			raisePropertyChanged(prop_Specular);
		}
	}

	void Decal::setShiny(float value)         // 005986d0: 0 < value (test ah, 5)
	{
		if (shiny != value && value > 0.0f)
		{
			shiny = value;
			raisePropertyChanged(prop_Shiny);
		}
	}

	void Texture::setStudsPerTileU(float value)   // 00598710
	{
		if (studsPerTile.x != value && value > 0.0f)
		{
			studsPerTile.x = value;
			raisePropertyChanged(prop_StudsPerTileU);
		}
	}

	void Texture::setStudsPerTileV(float value)   // 00598750
	{
		if (studsPerTile.y != value && value > 0.0f)
		{
			studsPerTile.y = value;
			raisePropertyChanged(prop_StudsPerTileV);
		}
	}
}

template class boost::any::holder<RBX::TextureId>;
template boost::any::any(const RBX::TextureId&);
template boost::any& boost::any::operator=(const RBX::TextureId&);
template RBX::TextureId* boost::any_cast<RBX::TextureId>(boost::any*);
template const RBX::TextureId& boost::any_cast<const RBX::TextureId&>(const boost::any&);
