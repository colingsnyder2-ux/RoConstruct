// =============================================================================
// Clothing.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Clothing.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8tree/Instance.h"
#include "util/TextureId.h"
#include "v8datamodel/BrickColor.h"

namespace RBX
{
	class Humanoid;
	class PartInstance;

	extern const char sShirt[];        // 0083c190 "Shirt"
	extern const char sPants[];        // 0083c198 "Pants"
	extern const char sShirtGraphic[]; // 0083c1a0 "ShirtGraphic"
	extern const char sClothing[];     // 0083c1b0 "Clothing"
	extern const char sSkin[];         // 0083c1bc "Skin"

	class __declspec(novtable) IModelModifier
	{
	public:
		virtual ~IModelModifier() {}
	};

	class __declspec(novtable) CharacterAppearance : public Instance, public IModelModifier
	{
	protected:
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
		const TextureId& getOutfit1() const { return outfit1; }
		const TextureId& getOutfit2() const { return outfit2; }
		void resetLimbs();                                               // 005d4b00 (called from onAncestorChanged)
	private:
		PartInstance* getTorso();                                        // 005d4510 "Torso" (00832a1c)
		PartInstance* getLeftLeg();                                      // 005d4640 "Left Leg" (0083c4b8)
		PartInstance* getRightLeg();                                     // 005d4770 "Right Leg" (0083c4c4)
		PartInstance* getLeftArm();                                      // 005d48a0 "Left Arm" (0083c4d0)
		PartInstance* getRightArm();                                     // 005d49d0 "Right Arm" (0083c4dc)
	protected:
		virtual void apply(Humanoid* humanoid);                          // 005d3a30
	};

	class Shirt : public DescribedCreatable<Shirt, Clothing, sShirt>
	{
	public:
		Shirt() {}
		TextureId getTemplate() const;                                   // 005d3a00 (+0x154)
		void setTemplate(TextureId value);                               // 005d40c0 (prop_Outfit2)
	};

	class Pants : public DescribedCreatable<Pants, Clothing, sPants>
	{
	public:
		Pants() {}
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
