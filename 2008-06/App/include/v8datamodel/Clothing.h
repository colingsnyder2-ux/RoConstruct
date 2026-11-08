#pragma once
// >>> native-status (generated) -- do not edit >>>
// Clothing | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 167ef866 | roc native-status --write
// 2008-06 native layout of RBX::CharacterAppearance and its subclasses Clothing, Shirt, Pants,
// ShirtGraphic and Skin. Inactive: no build list or swap uses it.
//
// Evidence (2008-06 Roblox.exe):
//  * RTTI (vtable 0083ca6c Clothing, 00822114 Shirt, 00822044 Pants, 0083c994 ShirtGraphic, 0083cb44 Skin):
//      Shirt/Pants -> DescribedCreatable<X, Clothing, sX> -> Described -> FactoryProduct -> Clothing
//      Clothing/ShirtGraphic/Skin -> DescribedCreatable<X, CharacterAppearance, sX> -> ... -> CharacterAppearance -> Instance.
//    CharacterAppearance has no vtable of its own (abstract) and no class descriptor: the Clothing,
//    ShirtGraphic and Skin descriptors (004909f0, 005c01d0, 005d4cb0) use Instance::classDescriptor() as base.
//  * Class-name arrays are .rdata `const char[]` (RTTI template argument 3QBDB): sShirt 0083c190,
//    sPants 0083c198, sShirtGraphic 0083c1a0, sClothing 0083c1b0, sSkin 0083c1bc (defined in this unit).
//  * Allocation sizes from Creator::create: Clothing/Shirt/Pants new(0x174) (0048f71f, 0049426f, 004941ef),
//    ShirtGraphic new(0x154) (0048f4af), Skin new(0x138) (004901ff).
//  * Primary vtable (17 slots, identical prefix for all five classes): slot 3 askSetParent 005d7640
//    (ICF-folded with ModelInstance::askSetParent: dynamic_cast<const ModelInstance*>), slot 4
//    onAncestorChanged 005d4c40, slot 16 apply(Humanoid*) (Clothing/Shirt/Pants 005d3a30,
//    ShirtGraphic 005d4240, Skin 005d3aa0).
//  * Fields from constructors and destructors: Clothing ctor 005d5700 builds two TextureIds at +0x134 and
//    +0x154 (std::string + Name::getNullName()), ~Clothing 0048fa50 destroys +0x154 then +0x134;
//    ShirtGraphic ctor 005d5510 one TextureId at +0x134 (~ShirtGraphic 005d5690); Skin ctor 005d58c0 stores
//    BrickColor 0xe2 (226) at +0x134.
//  * Property descriptors (static initializers): Clothing "Outfit1" 007f6040 (BoundProp<TextureId>, +0x134)
//    and "Outfit2" 007f6070 (+0x154); ShirtGraphic "Graphic" 007f6010 (+0x134); Skin "SkinColor" 007f6120
//    (BoundProp<BrickColor>, +0x134); all four pass the changed callback 005d3b50. Shirt "ShirtTemplate"
//    007f60a0 (PropDescriptor<Shirt,TextureId>, get 005d3a00 -> +0x154, set 005d40c0 via Outfit2) and
//    Pants "PantsTemplate" 007f60e0 (get 005d3b90 -> +0x134, set 005d4120 via Outfit1). Category "Appearance".
// Method and field names are analog names (no symbols); only the class names and property strings are original.
#include "v8tree/Instance.h"
#include "util/TextureId.h"
#include "v8datamodel/BrickColor.h"

namespace RBX
{
	class Humanoid;

	extern const char sShirt[];        // 0083c190 "Shirt"
	extern const char sPants[];        // 0083c198 "Pants"
	extern const char sShirtGraphic[]; // 0083c1a0 "ShirtGraphic"
	extern const char sClothing[];     // 0083c1b0 "Clothing"
	extern const char sSkin[];         // 0083c1bc "Skin"

	// Second base of CharacterAppearance at +0x130 (RTTI base list of 0083ca6c: IModelModifier mdisp 0x130).
	// Its only virtual is the destructor (each class's +0x130 vtable has one slot, an adjustor thunk to the
	// scalar deleting destructor, e.g. 005d5890 -> 005d58a0). No IModelModifier vtable exists in the binary
	// and the factory constructors/destructors store none, hence novtable. native ModelInstance.h keeps a
	// vector<IModelModifier*>; this definition belongs there or in its own header (proposal).
	class __declspec(novtable) IModelModifier
	{
	public:
		virtual ~IModelModifier() {}
	};

	// CharacterAppearance: abstract, no vtable or class descriptor in the binary; the FactoryProduct
	// constructors (e.g. 005d3e50) call Instance::Instance directly and the destructors (005d3bc0) jump to
	// Instance::~Instance, so neither CharacterAppearance nor IModelModifier stores a vtable (novtable).
	class __declspec(novtable) CharacterAppearance : public Instance, public IModelModifier
	{
	protected:
		// 005d3b50: BoundProp changed callback of every appearance property.
		void dataChanged(const Reflection::PropertyDescriptor&);
		virtual bool askSetParent(const Instance* instance) const;       // slot 3, 005d7640
		virtual void onAncestorChanged(const AncestorChanged& event);    // slot 4, 005d4c40
		virtual void apply(Humanoid* humanoid) = 0;                      // slot 16
	};

	class Clothing : public DescribedCreatable<Clothing, CharacterAppearance, sClothing>
	{
		friend struct NativeClothingLayout;  // tests/NativeClothingLayout.cpp
	protected:
		TextureId outfit1;                                               // +0x134 "Outfit1" (Pants template)
		TextureId outfit2;                                               // +0x154 "Outfit2" (Shirt template)
	public:
		static Reflection::BoundProp<TextureId, 1> prop_Outfit1;
		static Reflection::BoundProp<TextureId, 1> prop_Outfit2;
		Clothing();
		void resetLimbs();                                               // 005d4b00 (called from onAncestorChanged)
	protected:
		virtual void apply(Humanoid* humanoid);                          // 005d3a30
	};

	class Shirt : public DescribedCreatable<Shirt, Clothing, sShirt>
	{
	public:
		Shirt();
		TextureId getTemplate() const;                                   // 005d3a00 (+0x154)
		void setTemplate(TextureId value);                               // 005d40c0 (prop_Outfit2)
	};

	class Pants : public DescribedCreatable<Pants, Clothing, sPants>
	{
	public:
		Pants();
		TextureId getTemplate() const;                                   // 005d3b90 (+0x134)
		void setTemplate(TextureId value);                               // 005d4120 (prop_Outfit1)
	};

	class ShirtGraphic : public DescribedCreatable<ShirtGraphic, CharacterAppearance, sShirtGraphic>
	{
		friend struct NativeClothingLayout;  // tests/NativeClothingLayout.cpp
	protected:
		TextureId graphic;                                               // +0x134 "Graphic"
	public:
		static Reflection::BoundProp<TextureId, 1> prop_Graphic;
		ShirtGraphic();
	protected:
		virtual void apply(Humanoid* humanoid);                          // 005d4240
	};

	class Skin : public DescribedCreatable<Skin, CharacterAppearance, sSkin>
	{
		friend struct NativeClothingLayout;  // tests/NativeClothingLayout.cpp
	protected:
		BrickColor skinColor;                                            // +0x134 "SkinColor", default 226
	public:
		static Reflection::BoundProp<BrickColor, 1> prop_SkinColor;
		Skin();
	protected:
		virtual void apply(Humanoid* humanoid);                          // 005d3aa0
	};
}
