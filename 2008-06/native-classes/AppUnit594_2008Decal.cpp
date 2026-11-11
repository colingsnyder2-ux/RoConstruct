// 2008-06 native RBX::Decal / RBX::Texture unit (Decal.cpp) of the application range 00594000..005a0000 (inactive),
// against the committed native v8datamodel/Decal.h and FaceInstance.h (read-only). Original unit 00597350..0059898c,
// dynamic initializers 007f4190..007f42c7, atexit 007fdae0..007fdba9. Verified by
// tests/record_native_app_unit594_2008.py (receipt work/2008-06/shared-layouts/app-unit594-2008-working.json).
// Layout (constructors 00598400 / 00598870, destructor 00597d30): texture +0x144 (TextureId, 0x20), specular +0x164
// (0.0f), shiny +0x168 (20.0f 008222f0), Texture studsPerTile +0x16c/+0x170 (2.0f 0081c434).
// The Decal / Texture constructors are the bodies of native-classes/DecalLifetime.cpp (counted by
// decal-lifetime-trial.json); they are defined here only so this unit emits the Decal / Texture vtables, ??_G and the
// ??_E adjustor thunks.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
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

	// Dynamic initializers 007f4190, 007f41d0, 007f4210, 007f4250, 007f4290 (this order; "Appearance" 008329ac,
	// Functionality 5 = STANDARD).
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

// boost::any instantiations for the TextureId property values (boost 1.34.1 any.hpp; the unit's Value helpers use them):
//   holder<TextureId> (vtable 0083236c .?AV?$holder@VTextureId@RBX@@@any@boost@@): constructor 005973b0, type 00597410
//   (typeid(TextureId) 00949c78), clone 00597420 (new 0x24), ??_G 0059eff0 (ICF-shared with holder<MeshId>);
//   any(const TextureId&) 00597620, any::operator=(const TextureId&) 00597700, any_cast<TextureId>(any*) 00597370,
//   any_cast<const TextureId&>(const any&) 00597a00 (throws bad_any_cast through 0040a3f0).
template class boost::any::holder<RBX::TextureId>;
template boost::any::any(const RBX::TextureId&);
template boost::any& boost::any::operator=(const RBX::TextureId&);
template RBX::TextureId* boost::any_cast<RBX::TextureId>(boost::any*);
template const RBX::TextureId& boost::any_cast<const RBX::TextureId&>(const boost::any&);
