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
