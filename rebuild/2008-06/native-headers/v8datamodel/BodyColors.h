#pragma once
// >>> native-status (generated) -- do not edit >>>
// BodyColors | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 12768267 | roc native-status --write
// 2008-06 native layout of RBX::BodyColors (a CharacterAppearance subclass). Inactive: no build list or
// swap uses it. CharacterAppearance / IModelModifier come from native-headers/v8datamodel/Clothing.h.
//
// Evidence (2008-06 Roblox.exe):
//  * RTTI (vtable 0083cc1c): BodyColors -> DescribedCreatable<BodyColors, CharacterAppearance, sBodyColors>
//    -> Described -> FactoryProduct -> CharacterAppearance -> Instance, IModelModifier at mdisp 0x130.
//    sBodyColors is a .rdata `const char[]` at 0083c1c4 (RTTI template argument 3QBDB).
//  * Class descriptor 005c0240 (static 00977b58) uses Instance::classDescriptor() as base, as the other
//    appearance classes do (CharacterAppearance has no descriptor of its own).
//  * Constructor 005d59c0 (only caller Creator::create 0048ffb4): six BrickColor words at +0x134..+0x148,
//    initialised 0xe2 (226) for +0x134/+0x138/+0x13c, 0x1c (28) for +0x140 and 0x17 (23) for +0x144/+0x148;
//    then setName("Body Colors") (literal 0083cb88).
//  * Allocation size: Creator<BodyColors>::create 0048ff70 calls new(0x14c) (0048ff8f).
//  * Property descriptors (static initializers 007f6150..007f6240, BoundProp<BrickColor> ctor 005d4f90,
//    category "Appearance", changed callback CharacterAppearance::dataChanged 005d3b50):
//      "HeadColor" +0x134 (00979fa8), "LeftArmColor" +0x138 (0097a06c), "RightArmColor" +0x13c (0097a0dc),
//      "TorsoColor" +0x140 (0097a0a4), "LeftLegColor" +0x144 (0097a088), "RightLegColor" +0x148 (00979fc4).
//  * apply 005d4b60 (primary vtable slot 16) reads the same offsets for head/leftLeg/rightLeg/torso/leftArm/
//    rightArm, which confirms the field-to-property pairing.
// Field names are analog names (no symbols); class and property strings are original.
#include "v8datamodel/Clothing.h"

namespace RBX
{
	extern const char sBodyColors[];   // 0083c1c4 "BodyColors"

	class BodyColors : public DescribedCreatable<BodyColors, CharacterAppearance, sBodyColors>
	{
		friend struct NativeAppearanceLayout;  // tests/NativeAppearanceLayout.cpp
	protected:
		BrickColor headColor;                                            // +0x134 "HeadColor", default 226
		BrickColor leftArmColor;                                         // +0x138 "LeftArmColor", default 226
		BrickColor rightArmColor;                                        // +0x13c "RightArmColor", default 226
		BrickColor torsoColor;                                           // +0x140 "TorsoColor", default 28
		BrickColor leftLegColor;                                         // +0x144 "LeftLegColor", default 23
		BrickColor rightLegColor;                                        // +0x148 "RightLegColor", default 23
	public:
		static Reflection::BoundProp<BrickColor, 1> prop_HeadColor;
		static Reflection::BoundProp<BrickColor, 1> prop_LeftArmColor;
		static Reflection::BoundProp<BrickColor, 1> prop_RightArmColor;
		static Reflection::BoundProp<BrickColor, 1> prop_TorsoColor;
		static Reflection::BoundProp<BrickColor, 1> prop_LeftLegColor;
		static Reflection::BoundProp<BrickColor, 1> prop_RightLegColor;
		BodyColors();
	protected:
		virtual void apply(Humanoid* humanoid);                          // 005d4b60
	};
}
