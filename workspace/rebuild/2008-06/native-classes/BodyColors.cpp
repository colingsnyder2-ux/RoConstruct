// Inactive native recovery of RBX::BodyColors (CharacterAppearance subclass).
// Layout and evidence: native-headers/v8datamodel/BodyColors.h. Verified by tests/record_native_appearance.py.
// In the original, BodyColors shares the CharacterAppearance unit with Clothing/Shirt/Pants/ShirtGraphic/Skin
// (native-classes/Clothing.cpp, another owner); CharacterAppearance::dataChanged 005d3b50 is defined there.
// >>> native-status (generated) -- do not edit >>>
// BodyColors | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src a6da4090 | roc native-status --write
#include "v8datamodel/BodyColors.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
#ifdef NATIVE_BODYCOLORS_PENDING
#include "v8datamodel/ModelInstance.h"
#endif

namespace RBX
{
	const char sBodyColors[] = "BodyColors";

	// Factory/reflection template members (the generic definitions are not in the shared headers yet;
	// same local definitions as native-classes/Clothing.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	template<> Reflection::ClassDescriptor& Reflection::Described<BodyColors, sBodyColors,
		FactoryProduct<BodyColors, CharacterAppearance, sBodyColors> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), sBodyColors);
		return descriptor;
	}

	template class FactoryProduct<BodyColors, CharacterAppearance, sBodyColors>;
	template DescribedCreatable<BodyColors, CharacterAppearance, sBodyColors>::DescribedCreatable();

	// Property descriptors (static initializers 007f6150..007f6240).
	Reflection::BoundProp<BrickColor, 1> BodyColors::prop_HeadColor("HeadColor", "Appearance", &BodyColors::headColor, static_cast<void (BodyColors::*)(const Reflection::PropertyDescriptor&)>(&BodyColors::dataChanged), Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<BrickColor, 1> BodyColors::prop_LeftArmColor("LeftArmColor", "Appearance", &BodyColors::leftArmColor, static_cast<void (BodyColors::*)(const Reflection::PropertyDescriptor&)>(&BodyColors::dataChanged), Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<BrickColor, 1> BodyColors::prop_RightArmColor("RightArmColor", "Appearance", &BodyColors::rightArmColor, static_cast<void (BodyColors::*)(const Reflection::PropertyDescriptor&)>(&BodyColors::dataChanged), Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<BrickColor, 1> BodyColors::prop_TorsoColor("TorsoColor", "Appearance", &BodyColors::torsoColor, static_cast<void (BodyColors::*)(const Reflection::PropertyDescriptor&)>(&BodyColors::dataChanged), Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<BrickColor, 1> BodyColors::prop_LeftLegColor("LeftLegColor", "Appearance", &BodyColors::leftLegColor, static_cast<void (BodyColors::*)(const Reflection::PropertyDescriptor&)>(&BodyColors::dataChanged), Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<BrickColor, 1> BodyColors::prop_RightLegColor("RightLegColor", "Appearance", &BodyColors::rightLegColor, static_cast<void (BodyColors::*)(const Reflection::PropertyDescriptor&)>(&BodyColors::dataChanged), Reflection::PropertyDescriptor::STANDARD);

	BodyColors::BodyColors()
		: headColor(BrickColor::lego_226),
		  leftArmColor(BrickColor::lego_226),
		  rightArmColor(BrickColor::lego_226),
		  torsoColor(BrickColor::lego_28),
		  leftLegColor(BrickColor::lego_23),
		  rightLegColor(BrickColor::lego_23)
	{
		setName("Body Colors");
	}

#ifdef NATIVE_BODYCOLORS_PENDING
	// 005d4b60: skips when the parent model carries a Skin modifier. 005d4460 walks ModelInstance's
	// vector<IModelModifier*> (+0x1ec) with dynamic_cast<Skin*>; needs a ModelInstance member template
	// (proposal findModifierOfType<T>) and a native ModelInstance.h that compiles standalone.
	void BodyColors::apply(Humanoid* humanoid)
	{
		if (Instance* parent = getParent())
			if (ModelInstance* model = dynamic_cast<ModelInstance*>(parent))
				if (model->findModifierOfType<Skin>())
					return;
		if (PartInstance* part = humanoid->getHead()) part->setColor(headColor);
		if (PartInstance* part = humanoid->getLeftLeg()) part->setColor(leftLegColor);
		if (PartInstance* part = humanoid->getRightLeg()) part->setColor(rightLegColor);
		if (PartInstance* part = humanoid->getTorso()) part->setColor(torsoColor);
		if (PartInstance* part = humanoid->getLeftArm()) part->setColor(leftArmColor);
		if (PartInstance* part = humanoid->getRightArm()) part->setColor(rightArmColor);
	}
#endif
}

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sBodyColors>();
