// 2008-06 native rows of the RBX::Network::Player translation unit (Network/Player.cpp, 004897a0..) inside
// 00480000..0048c000 that no other receipt counts (inactive). Verified by tests/record_native_app_unit480_2008.py.
// Headers are read-only here.
//
//   * ServiceProvider::findServiceProvider(const Instance*) 004898d0 (57 B): walks the parent chain (+0x104) until
//     __RTDynamicCast(context, 0, Instance 0092907c, ServiceProvider 0092e15c, 0) succeeds; NULL at the root. The
//     native v8tree/Service.h declares it without a body; its first copy in the binary sits in this unit.
//   * Instance::numChildren() const 0048ae20 (23 B): the v8tree/Instance.h inline, emitted out of line here.
//   * the file-level helpers named by the evidence (?addChild@@YAX..., ?setAppearanceParent@@YAX...,
//     ?setAppearanceParentNull@@YAX...): addChild 0048a670 (child->setParent(parent), 19 B),
//     setAppearanceParent 0048a690 (CharacterAppearance 00934d68 / Accoutrement 00934f48 casts, else throws
//     runtime_error with the literal 008215c0) and setAppearanceParentNull 004899b0 (CharacterAppearance cast,
//     setParent(NULL) 0055a8f0). They are defined with external linkage so this build emits them (the original
//     binds them through boost::bind / for_eachChild); the evidence mangling is the same.
//   * Player::setUnder13 0048b910 / setSuperSafeChat 0048b940: the Network/Player.h inlines (BoundProp GetSet call
//     through prop_Under13 / prop_SuperSafeChat + 0x18), emitted out of line here.
#include "Network/Player.h"
#include "v8tree/Service.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Clothing.h"
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/TimerService.h"
#include "reflection/reflection.h"
#include <stdexcept>

namespace RBX
{
	// Template members the shared headers only declare (the same definitions NetworkPlayer.cpp / Team.cpp use).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	const ServiceProvider* ServiceProvider::findServiceProvider(const Instance* context)
	{
		while (context)
		{
			if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(context))
				return provider;
			context = context->getParent();
		}
		return NULL;
	}
}

void addChild(const boost::shared_ptr<RBX::ModelInstance>& parent, const boost::shared_ptr<RBX::Instance>& child)
{
	child->setParent(parent.get());
}

void setAppearanceParent(boost::shared_ptr<RBX::Instance> parent, boost::shared_ptr<RBX::Instance> instance)
{
	if (dynamic_cast<RBX::CharacterAppearance*>(instance.get()))
	{
		instance->setParent(parent.get());
	}
	else if (dynamic_cast<RBX::Accoutrement*>(instance.get()))
	{
		instance->setParent(parent.get());
	}
	else
	{
		throw std::runtime_error("Attempt to add a non-CharacterAppearance/Accoutrement object to a character");
	}
}

void setAppearanceParentNull(RBX::Instance* instance)
{
	if (dynamic_cast<RBX::CharacterAppearance*>(instance))
		instance->setParent(NULL);
}

// Out-of-line copies of the header inlines (address taken so this build emits the COMDAT bodies).
size_t (RBX::Instance::*const numChildrenOutOfLine)() const = &RBX::Instance::numChildren;
void (RBX::Network::Player::*const setUnder13OutOfLine)(bool) = &RBX::Network::Player::setUnder13;
void (RBX::Network::Player::*const setSuperSafeChatOutOfLine)(bool) = &RBX::Network::Player::setSuperSafeChat;

// Templates the unit instantiates for the teamColor (BrickColor) property and the character (ModelInstance) casts:
//   * boost::any::holder<BrickColor> (vtable 008216c4 .?AV?$holder@VBrickColor@RBX@@@any@boost@@): ??_G 0048b250,
//     type 0048b1f0 (&typeid(BrickColor) 00935398), clone 0048b200 (new 8);
//   * Reflection::Value::isType<BrickColor>() 0048b230 (typeid(BrickColor) == type().type);
//   * TypedPropertyDescriptor<BrickColor> (vtable 00821690): constructor 0048b180 (Type::singleton<BrickColor>
//     0056d120, PropertyDescriptor 0056c650, vtable store, getset at +0x18), equalValues slot 3 0048bb40;
//   * boost::shared_dynamic_cast<ModelInstance, Instance> 0048b150 and the shared_ptr<ModelInstance>
//     dynamic_cast_tag constructor 0048a9e0 it calls (ModelInstance 00932a40).
template class boost::any::holder<RBX::BrickColor>;
template bool RBX::Reflection::Value::isType<RBX::BrickColor>() const;
template RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>::TypedPropertyDescriptor(
	RBX::Reflection::ClassDescriptor&, const char*, const char*,
	std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>::GetSet>,
	RBX::Reflection::PropertyDescriptor::Functionality);
template bool RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>::equalValues(
	const RBX::Reflection::DescribedBase*, const RBX::Reflection::DescribedBase*) const;
template boost::shared_ptr<RBX::ModelInstance> boost::shared_dynamic_cast<RBX::ModelInstance, RBX::Instance>(
	const boost::shared_ptr<RBX::Instance>&);

// BrickColor variant helpers: boost::any::operator=<BrickColor> 0048b590, any_cast<const BrickColor&> 0048b690 (throws
// bad_cast through 0040a3f0), Reflection::Value::operator=<BrickColor> 0048bca0 (Type::singleton<BrickColor> 0056d120).
template boost::any& boost::any::operator=<RBX::BrickColor>(const RBX::BrickColor&);
template const RBX::BrickColor& boost::any_cast<const RBX::BrickColor&>(const boost::any&);
template RBX::Reflection::Value& RBX::Reflection::Value::operator=<RBX::BrickColor>(const RBX::BrickColor&);

// The Backpack / TimerService instances the unit creates (loadCharacter / rebuildBackpack): Instance::
// findFirstChildOfType<Backpack> 0048bb80 (Backpack 009353ec), Creatable<Instance>::create<Backpack> 0048bc20 (malloc
// 0x16c, Backpack() 005d1a80) and create<TimerService> 0048bcf0 (malloc 0x158, TimerService() 005d71b0), with their
// shared_ptr(T*, Creatable<Instance>::Deleter) constructors 0048b4e0 / 0048b5e0 (shared_count 0048ac30 / 0048acc0).
template RBX::Backpack* RBX::Instance::findFirstChildOfType<RBX::Backpack>() const;
template boost::shared_ptr<RBX::Backpack> RBX::Creatable<RBX::Instance>::create<RBX::Backpack>();
template boost::shared_ptr<RBX::TimerService> RBX::Creatable<RBX::Instance>::create<RBX::TimerService>();

// DescribedCreatable<Player, Instance, sPlayer>: the vector deleting destructor thunks of its non-primary bases,
// 0048a610 (-0x44), 0048a620 (-0x64), 0048a630 (-0xa4), 0048a640 (-0xc4), 0048a650 (-0x14), each jumping to its ??_G
// 00492870 (counted by network-player-working.json).
template class RBX::DescribedCreatable<RBX::Network::Player, RBX::Instance, RBX::Network::sPlayer>;

// PropDescriptor<Player, std::string>::GetSetImpl (prop_characterAppearance): getValue 0048ab70.
template class RBX::Reflection::PropDescriptor<RBX::Network::Player, std::string>::GetSetImpl<
	std::string (RBX::Network::Player::*)() const, void (RBX::Network::Player::*)(const std::string&)>;

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Reflection::TypedPropertyDescriptor<bool>;
template class RBX::Reflection::TypedPropertyDescriptor<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >;
template class boost::function0<void,std::allocator<boost::function_base> >;
template class boost::function0<void,std::allocator<void> >;
template class boost::shared_ptr<RBX::Backpack>;
template class boost::shared_ptr<RBX::ModelInstance>;
template class boost::shared_ptr<RBX::TimerService>;
template class boost::weak_ptr<RBX::Instance>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<bool>::GetSet>;
template class std::deque<boost::function<void __cdecl(void),std::allocator<void> >,std::allocator<boost::function<void __cdecl(void),std::allocator<void> > > >;
