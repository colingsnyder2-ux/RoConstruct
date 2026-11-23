// =============================================================================
// CharacterAppearance.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/CharacterAppearance.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Clothing.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
#include "Network/Players.h"
#include "v8datamodel/ChangeHistoryService.h"

#include "v8datamodel/ModelInstance.h"   // complete type for the askSetParent dynamic_cast (005d7640)
#include "v8datamodel/Decal.h"   // native Decal (ShirtGraphic::apply 005d4240, findFirstChildOfType<Decal> 005d41a0)

namespace RBX
{

	const char sShirt[] = "Shirt";
	const char sPants[] = "Pants";
	const char sShirtGraphic[] = "ShirtGraphic";
	const char sClothing[] = "Clothing";
	const char sSkin[] = "Skin";

	// Factory/reflection template members (the generic definitions are not in the shared headers yet).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	template<> Reflection::ClassDescriptor& Reflection::Described<Clothing, sClothing,
		FactoryProduct<Clothing, CharacterAppearance, sClothing> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), sClothing);
		return descriptor;
	}
	template<> Reflection::ClassDescriptor& Reflection::Described<ShirtGraphic, sShirtGraphic,
		FactoryProduct<ShirtGraphic, CharacterAppearance, sShirtGraphic> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), sShirtGraphic);
		return descriptor;
	}
	template<> Reflection::ClassDescriptor& Reflection::Described<Skin, sSkin,
		FactoryProduct<Skin, CharacterAppearance, sSkin> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), sSkin);
		return descriptor;
	}
	template<> Reflection::ClassDescriptor& Reflection::Described<Shirt, sShirt,
		FactoryProduct<Shirt, Clothing, sShirt> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Clothing::classDescriptor(), sShirt);
		return descriptor;
	}
	template<> Reflection::ClassDescriptor& Reflection::Described<Pants, sPants,
		FactoryProduct<Pants, Clothing, sPants> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Clothing::classDescriptor(), sPants);
		return descriptor;
	}

	template class FactoryProduct<Clothing, CharacterAppearance, sClothing>;
	template class FactoryProduct<ShirtGraphic, CharacterAppearance, sShirtGraphic>;
	template class FactoryProduct<Skin, CharacterAppearance, sSkin>;
	template class FactoryProduct<Shirt, Clothing, sShirt>;
	template class FactoryProduct<Pants, Clothing, sPants>;
	template DescribedCreatable<Clothing, CharacterAppearance, sClothing>::DescribedCreatable();
	template DescribedCreatable<ShirtGraphic, CharacterAppearance, sShirtGraphic>::DescribedCreatable();
	template DescribedCreatable<Skin, CharacterAppearance, sSkin>::DescribedCreatable();
	template DescribedCreatable<Shirt, Clothing, sShirt>::DescribedCreatable();
	template DescribedCreatable<Pants, Clothing, sPants>::DescribedCreatable();

	Reflection::BoundProp<TextureId, 1> ShirtGraphic::prop_Graphic(
		"Graphic",
		"Appearance",
		&ShirtGraphic::graphic,
		static_cast<void (ShirtGraphic::*)(const Reflection::PropertyDescriptor&)>(&ShirtGraphic::dataChanged),
		Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Clothing::prop_Outfit1(
		"Outfit1",
		"Appearance",
		&Clothing::outfit1,
		static_cast<void (Clothing::*)(const Reflection::PropertyDescriptor&)>(&Clothing::dataChanged),
		Reflection::PropertyDescriptor::LEGACY);
	Reflection::BoundProp<TextureId, 1> Clothing::prop_Outfit2(
		"Outfit2",
		"Appearance",
		&Clothing::outfit2,
		static_cast<void (Clothing::*)(const Reflection::PropertyDescriptor&)>(&Clothing::dataChanged),
		Reflection::PropertyDescriptor::LEGACY);
	static Reflection::PropDescriptor<Shirt, TextureId> prop_ShirtTemplate(
		"ShirtTemplate",
		"Appearance",
		&Shirt::getTemplate,
		&Shirt::setTemplate,
		Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Pants, TextureId> prop_PantsTemplate(
		"PantsTemplate",
		"Appearance",
		&Pants::getTemplate,
		&Pants::setTemplate,
		Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<BrickColor, 1> Skin::prop_SkinColor(
		"SkinColor",
		"Appearance",
		&Skin::skinColor,
		static_cast<void (Skin::*)(const Reflection::PropertyDescriptor&)>(&Skin::dataChanged),
		Reflection::PropertyDescriptor::STANDARD);

	bool CharacterAppearance::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const ModelInstance*>(instance) != NULL;
	}

	void CharacterAppearance::dataChanged(const Reflection::PropertyDescriptor&)
	{
		if (Network::Players::backendProcessing(this, false))
		{
			if (Humanoid* humanoid = Humanoid::modelIsCharacter(getParent()))
				apply(humanoid);
		}
	}

	void CharacterAppearance::onAncestorChanged(const AncestorChanged& event)
	{
		Instance::onAncestorChanged(event);
		if (event.child == this)
		{
			if (Clothing* clothing = dynamic_cast<Clothing*>(this))
				clothing->resetLimbs();
			else if (Network::Players::backendProcessing(this, false))
			{
				if (Humanoid* humanoid = Humanoid::modelIsCharacter(getParent()))
					apply(humanoid);
			}
		}
	}

	// Clothing
	Clothing::Clothing()
	{
		setName("Clothing");
	}

	void Clothing::apply(Humanoid* humanoid)
	{
		if (PartInstance* part = humanoid->getLeftLeg()) part->outfitChanged();
		if (PartInstance* part = humanoid->getRightLeg()) part->outfitChanged();
		if (PartInstance* part = humanoid->getTorso()) part->outfitChanged();
		if (PartInstance* part = humanoid->getLeftArm()) part->outfitChanged();
		if (PartInstance* part = humanoid->getRightArm()) part->outfitChanged();
	}

	// Limb lookups (analog names): a fresh shared_ptr each call, unlike the cached Humanoid getters.
	PartInstance* Clothing::getTorso()      // 005d4510
	{
		boost::shared_ptr<PartInstance> part;
		if (getParent())
			part = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Torso"));
		return part.get();
	}

	PartInstance* Clothing::getLeftLeg()    // 005d4640
	{
		boost::shared_ptr<PartInstance> part;
		if (getParent())
			part = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Leg"));
		return part.get();
	}

	PartInstance* Clothing::getRightLeg()   // 005d4770
	{
		boost::shared_ptr<PartInstance> part;
		if (getParent())
			part = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Leg"));
		return part.get();
	}

	PartInstance* Clothing::getLeftArm()    // 005d48a0
	{
		boost::shared_ptr<PartInstance> part;
		if (getParent())
			part = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Arm"));
		return part.get();
	}

	PartInstance* Clothing::getRightArm()   // 005d49d0
	{
		boost::shared_ptr<PartInstance> part;
		if (getParent())
			part = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Arm"));
		return part.get();
	}

	void Clothing::resetLimbs()
	{
		if (PartInstance* part = getLeftLeg()) part->outfitChanged();
		if (PartInstance* part = getRightLeg()) part->outfitChanged();
		if (PartInstance* part = getTorso()) part->outfitChanged();
		if (PartInstance* part = getLeftArm()) part->outfitChanged();
		if (PartInstance* part = getRightArm()) part->outfitChanged();
	}

	TextureId Shirt::getTemplate() const { return outfit2; }
	void Shirt::setTemplate(TextureId value) { prop_Outfit2.setValue(this, value); }

	TextureId Pants::getTemplate() const { return outfit1; }
	void Pants::setTemplate(TextureId value) { prop_Outfit1.setValue(this, value); }   // 005d4120, as above

	// ShirtGraphic
	ShirtGraphic::ShirtGraphic()
	{
		setName("Shirt Graphic");   // literal 0083c8f8 has a space
	}

	void ShirtGraphic::apply(Humanoid* humanoid)
	{
		if (PartInstance* torso = humanoid->getTorso())
			if (Decal* decal = torso->findFirstChildOfType<Decal>())
				decal->setTexture(graphic);
	}

	// Skin
	Skin::Skin() : skinColor(BrickColor::lego_226)
	{
		setName("Skin");
	}

	void Skin::apply(Humanoid* humanoid)
	{
		if (PartInstance* part = humanoid->getHead()) part->setColor(skinColor);
		if (PartInstance* part = humanoid->getLeftLeg()) part->setColor(skinColor);
		if (PartInstance* part = humanoid->getRightLeg()) part->setColor(skinColor);
		if (PartInstance* part = humanoid->getTorso()) part->setColor(skinColor);
		if (PartInstance* part = humanoid->getLeftArm()) part->setColor(skinColor);
		if (PartInstance* part = humanoid->getRightArm()) part->setColor(skinColor);
	}
}

template void RBX::Name::callDoDeclare<RBX::sShirtGraphic>();
template void RBX::Name::callDoDeclare<RBX::sClothing>();
template void RBX::Name::callDoDeclare<RBX::sSkin>();
