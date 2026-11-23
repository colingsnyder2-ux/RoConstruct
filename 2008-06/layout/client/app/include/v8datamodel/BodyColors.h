// =============================================================================
// BodyColors.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/BodyColors.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
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
