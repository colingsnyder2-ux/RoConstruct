#include "v8datamodel/BodyColors.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
#include "v8datamodel/ModelInstance.h"   // findModifierOfType<Skin> 005d4460 (BodyColors::apply 005d4b60)

namespace RBX
{
	const char sBodyColors[] = "BodyColors";

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
}

template void RBX::Name::callDoDeclare<RBX::sBodyColors>();
