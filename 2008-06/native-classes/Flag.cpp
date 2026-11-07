// 2008-06 native RBX::Flag (inactive): part of the original Flag unit (00618380..00619a60, initializer 007f7cc0,
// atexit 00800310). Evidence in native-headers/v8datamodel/Flag.h.
// Built against the native v8datamodel/Tool.h and Hopper.h (Tool / BackpackItem with the 2008 const-char-array
// DescribedCreatable); tests/record_native_flag_family.py verifies every row and the Flag vtables.
// >>> native-status (generated) -- do not edit >>>
// Flag | 2008-06 | linked
// 1/1 exact by name (100%) | 1/1 exact bodies | no strings | verified 2026-11-07| by EspClaude (deepseek:deepseek-chat)
// <<< native-status | src f4ad378a | roc native-status --write
#include "v8datamodel/Flag.h"
#include "Network/Player.h"

namespace RBX
{
	const char sFlag[] = "Flag"; // 00843c90 (doDeclare 005a0320, classDescriptor 005c3880, constructor setName)

	// Template members the shared headers only declare (same definitions as Team.cpp / SpawnLocation.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	// Dynamic initializer 007f7cc0.
	static Reflection::PropDescriptor<Flag, BrickColor> prop_Color("TeamColor", "Data", &Flag::getTeamColor, &Flag::setTeamColor, Reflection::PropertyDescriptor::STANDARD);

	BrickColor Flag::getTeamColor() const
	{
		return teamColor;
	}

	bool Flag::canBePickedUpByPlayer(Network::Player* p)
	{
		return p->getNeutral() ? false : (p->getTeamColor() != getTeamColor());
	}

	Flag::~Flag()
	{
	}

	Flag::Flag()
		: timer(NULL)
	{
		setName(sFlag);
	}

	void Flag::setTeamColor(BrickColor color)
	{
		teamColor = color;
		raisePropertyChanged(prop_Color);
	}
}
