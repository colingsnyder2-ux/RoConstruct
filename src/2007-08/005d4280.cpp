// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/CharacterAppearance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/CharacterAppearance.h"

#include "v8datamodel/Decal.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {

const char sShirt[] = "Shirt";

const char sShirtGraphic[] = "ShirtGraphic";

using namespace Reflection;

BoundProp<TextureId, 1> ShirtGraphic::prop_Graphic(
	"Graphic", "Appearance", &ShirtGraphic::graphic, &ShirtGraphic::dataChanged
);

BoundProp<BrickColor, 1> Shirt::prop_leftSleeveColor(
	"LeftSleeveColor", "Appearance", &Shirt::leftSleeveColor, &Shirt::dataChanged
);

BoundProp<BrickColor, 1> Shirt::prop_rightSleeveColor(
	"RightSleeveColor", "Appearance", &Shirt::rightSleeveColor, &Shirt::dataChanged
);

BoundProp<BrickColor, 1> Shirt::prop_torsoColor("TorsoColor", "Appearance", &Shirt::torsoColor, &Shirt::dataChanged);

const char sSkin[] = "Skin";

BoundProp<BrickColor, 1> Skin::prop_skinColor("SkinColor", "Appearance", &Skin::skinColor, &Skin::dataChanged);

const char sBodyColors[] = "BodyColors";

BoundProp<BrickColor, 1> BodyColors::prop_HeadColor(
	"HeadColor", "Appearance", &BodyColors::headColor, &BodyColors::dataChanged
);

BoundProp<BrickColor, 1> BodyColors::prop_LeftArmColor(
	"LeftArmColor", "Appearance", &BodyColors::leftArmColor, &BodyColors::dataChanged
);

BoundProp<BrickColor, 1> BodyColors::prop_RightArmColor(
	"RightArmColor", "Appearance", &BodyColors::rightArmColor, &BodyColors::dataChanged
);

BoundProp<BrickColor, 1> BodyColors::prop_TorsoColor(
	"TorsoColor", "Appearance", &BodyColors::torsoColor, &BodyColors::dataChanged
);

BoundProp<BrickColor, 1> BodyColors::prop_LeftLegColor(
	"LeftLegColor", "Appearance", &BodyColors::leftLegColor, &BodyColors::dataChanged
);

BoundProp<BrickColor, 1> BodyColors::prop_RightLegColor(
	"RightLegColor", "Appearance", &BodyColors::rightLegColor, &BodyColors::dataChanged
);

// FUNCTION: WEBSERVICE 0x10059c10 FOLDED
// FUNCTION: ROBLOX 0x00564b10 FOLDED
bool CharacterAppearance::askSetParent(const Instance* instance) const
{
	return dynamic_cast<const ModelInstance*>(instance) != NULL;
}

// FUNCTION: WEBSERVICE 0x100e0420
// FUNCTION: ROBLOX 0x005e5f50
void CharacterAppearance::onAncestorChanged(const AncestorChanged& event)
{
	if (event.child == this) {
		apply();
	}
}

// FUNCTION: WEBSERVICE 0x100e0980
// FUNCTION: ROBLOX 0x005e6440
void ShirtGraphic::apply(Humanoid* humanoid)
{
	if (PartInstance* torso = humanoid->getTorso()) {
		if (Decal* decal = torso->findFirstChildOfType<Decal>()) {
			decal->setTexture(graphic);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100e09d0
// FUNCTION: ROBLOX 0x005e6490
void Shirt::apply(Humanoid* humanoid)
{
	ShirtGraphic::apply(humanoid);

	if (PartInstance* torso = humanoid->getTorso()) {
		torso->setColor(torsoColor);
	}
	if (PartInstance* leftArm = humanoid->getLeftArm()) {
		leftArm->setColor(leftSleeveColor);
	}
	if (PartInstance* rightArm = humanoid->getRightArm()) {
		rightArm->setColor(rightSleeveColor);
	}
}

// FUNCTION: WEBSERVICE 0x100e0a90
// FUNCTION: ROBLOX 0x005e6550
void Skin::apply(Humanoid* humanoid)
{
	bool hasShirt = getParent()->findFirstChildOfType<Shirt>() != NULL;

	if (PartInstance* head = humanoid->getHead()) {
		head->setColor(skinColor);
	}
	if (PartInstance* leftLeg = humanoid->getLeftLeg()) {
		leftLeg->setColor(skinColor);
	}
	if (PartInstance* rightLeg = humanoid->getRightLeg()) {
		rightLeg->setColor(skinColor);
	}
	if (!hasShirt) {
		if (PartInstance* torso = humanoid->getTorso()) {
			torso->setColor(skinColor);
		}
		if (PartInstance* leftArm = humanoid->getLeftArm()) {
			leftArm->setColor(skinColor);
		}
		if (PartInstance* rightArm = humanoid->getRightArm()) {
			rightArm->setColor(skinColor);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100e0b60
// FUNCTION: ROBLOX 0x005e6620
void BodyColors::apply(Humanoid* humanoid)
{
	bool hasSkin = getParent()->findFirstChildOfType<Skin>() != NULL;

	if (!hasSkin) {
		bool hasShirt = getParent()->findFirstChildOfType<Shirt>() != NULL;

		if (PartInstance* head = humanoid->getHead()) {
			head->setColor(headColor);
		}
		if (PartInstance* leftLeg = humanoid->getLeftLeg()) {
			leftLeg->setColor(leftLegColor);
		}
		if (PartInstance* rightLeg = humanoid->getRightLeg()) {
			rightLeg->setColor(rightLegColor);
		}
		if (!hasShirt) {
			if (PartInstance* torso = humanoid->getTorso()) {
				torso->setColor(torsoColor);
			}
			if (PartInstance* leftArm = humanoid->getLeftArm()) {
				leftArm->setColor(leftArmColor);
			}
			if (PartInstance* rightArm = humanoid->getRightArm()) {
				rightArm->setColor(rightArmColor);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100e1440
// FUNCTION: ROBLOX 0x005e6f40
ShirtGraphic::ShirtGraphic()
{
	setName("Shirt Graphic");
}

// FUNCTION: WEBSERVICE 0x100e15c0
// FUNCTION: ROBLOX 0x005e70c0
Skin::Skin() : skinColor(BrickColor::lego_226)
{
	setName("Skin");
}

// FUNCTION: WEBSERVICE 0x100e16d0
// FUNCTION: ROBLOX 0x005e71e0
BodyColors::BodyColors()
	: headColor(BrickColor::lego_226), leftArmColor(BrickColor::lego_226), rightArmColor(BrickColor::lego_226),
	  torsoColor(BrickColor::lego_28), leftLegColor(BrickColor::lego_23), rightLegColor(BrickColor::lego_23)
{
	setName("Body Colors");
}

// FUNCTION: WEBSERVICE 0x100e1990
// FUNCTION: ROBLOX 0x005e74f0
Shirt::Shirt()
	: leftSleeveColor(BrickColor::lego_23), rightSleeveColor(BrickColor::lego_23), torsoColor(BrickColor::lego_1)
{
	setName("Shirt");
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors>;
template class RBX::Reflection::Described<
	RBX::BodyColors,
	RBX::sBodyColors,
	RBX::FactoryProduct<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors> >;
template class RBX::DescribedCreatable<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors>;

template class RBX::FactoryProduct<RBX::ShirtGraphic, RBX::CharacterAppearance, RBX::sShirtGraphic>;
template class RBX::Reflection::Described<
	RBX::ShirtGraphic,
	RBX::sShirtGraphic,
	RBX::FactoryProduct<RBX::ShirtGraphic, RBX::CharacterAppearance, RBX::sShirtGraphic> >;
template class RBX::DescribedCreatable<RBX::ShirtGraphic, RBX::CharacterAppearance, RBX::sShirtGraphic>;

template class RBX::FactoryProduct<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin>;
template class RBX::Reflection::
	Described<RBX::Skin, RBX::sSkin, RBX::FactoryProduct<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin> >;
template class RBX::DescribedCreatable<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin>;

template class RBX::FactoryProduct<RBX::Shirt, RBX::ShirtGraphic, RBX::sShirt>;
template class RBX::Reflection::
	Described<RBX::Shirt, RBX::sShirt, RBX::FactoryProduct<RBX::Shirt, RBX::ShirtGraphic, RBX::sShirt> >;
template class RBX::DescribedCreatable<RBX::Shirt, RBX::ShirtGraphic, RBX::sShirt>;
