// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// Inactive native recovery of RBX::CharacterAppearance / Clothing / Shirt / Pants / ShirtGraphic / Skin.
// Layout and evidence: native-headers/v8datamodel/Clothing.h. Verified by tests/record_native_clothing.py.
// >>> native-status (generated) -- do not edit >>>
// Clothing | 2008-06 | 5 byte-exact, inactive (not link-selected)
// 5/9 mapped addresses byte-exact | named 1 | 4 unproved | 2 referenced strings (not rechecked) | by king_originala (+2) (mixed 4)
// <<< native-status | src b7b4a88d | roc native-status --write
#include "v8datamodel/Clothing.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
#include "Network/Players.h"
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

	// Property descriptors (static initializers 007f6010..007f6120).
	Reflection::BoundProp<TextureId, 1> ShirtGraphic::prop_Graphic("Graphic", "Appearance", &ShirtGraphic::graphic, static_cast<void (ShirtGraphic::*)(const Reflection::PropertyDescriptor&)>(&ShirtGraphic::dataChanged), Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<TextureId, 1> Clothing::prop_Outfit1("Outfit1", "Appearance", &Clothing::outfit1, static_cast<void (Clothing::*)(const Reflection::PropertyDescriptor&)>(&Clothing::dataChanged), Reflection::PropertyDescriptor::LEGACY);
	Reflection::BoundProp<TextureId, 1> Clothing::prop_Outfit2("Outfit2", "Appearance", &Clothing::outfit2, static_cast<void (Clothing::*)(const Reflection::PropertyDescriptor&)>(&Clothing::dataChanged), Reflection::PropertyDescriptor::LEGACY);
	static Reflection::PropDescriptor<Shirt, TextureId> prop_ShirtTemplate("ShirtTemplate", "Appearance", &Shirt::getTemplate, &Shirt::setTemplate, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<Pants, TextureId> prop_PantsTemplate("PantsTemplate", "Appearance", &Pants::getTemplate, &Pants::setTemplate, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<BrickColor, 1> Skin::prop_SkinColor("SkinColor", "Appearance", &Skin::skinColor, static_cast<void (Skin::*)(const Reflection::PropertyDescriptor&)>(&Skin::dataChanged), Reflection::PropertyDescriptor::STANDARD);

	// CharacterAppearance
#ifdef NATIVE_CLOTHING_PENDING_MODEL
	// ICF-folded with ModelInstance::askSetParent (005d7640); needs a native ModelInstance.h that compiles
	// standalone (the current one pulls the donor Camera.h, which still passes &sName).
	bool CharacterAppearance::askSetParent(const Instance* instance) const
	{
		return dynamic_cast<const ModelInstance*>(instance) != NULL;
	}
#endif

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

#ifdef NATIVE_CLOTHING_PENDING
	// Needs PartInstance::outfitChanged() (0059e3a0: fires PartInstance event "OutfitChanged", descriptor
	// 009761d4 built by 007f4b90; name provisional) in native-headers/v8datamodel/PartInstance.h.
	void Clothing::apply(Humanoid* humanoid)
	{
		if (PartInstance* part = humanoid->getLeftLeg()) part->outfitChanged();
		if (PartInstance* part = humanoid->getRightLeg()) part->outfitChanged();
		if (PartInstance* part = humanoid->getTorso()) part->outfitChanged();
		if (PartInstance* part = humanoid->getLeftArm()) part->outfitChanged();
		if (PartInstance* part = humanoid->getRightArm()) part->outfitChanged();
	}
#endif

	// Shirt / Pants
	Shirt::Shirt() {}
	TextureId Shirt::getTemplate() const { return outfit2; }
	// 005d40c0 calls GetSet::setValue through vtable slot 3: the 2008 TypedPropertyDescriptor::GetSet has two
	// bool virtuals before getValue (every GetSet vtable here starts 0060a2f0, 0060a2f0 = `xor al,al; ret`).
	void Shirt::setTemplate(TextureId value) { prop_Outfit2.setValue(this, value); }

	Pants::Pants() {}
	TextureId Pants::getTemplate() const { return outfit1; }
	void Pants::setTemplate(TextureId value) { prop_Outfit1.setValue(this, value); }   // 005d4120, as above

	// ShirtGraphic
	ShirtGraphic::ShirtGraphic()
	{
		setName("Shirt Graphic");   // literal 0083c8f8 has a space
	}

	// 005d4240: Instance::findFirstChildOfType<Decal> (005d41a0) and the native Decal.h.
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

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sShirtGraphic>();
template void RBX::Name::callDoDeclare<RBX::sClothing>();
template void RBX::Name::callDoDeclare<RBX::sSkin>();
