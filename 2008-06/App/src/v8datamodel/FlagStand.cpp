// 2008-06 native RBX::FlagStand (inactive): the FlagStand half of the original FlagStand/FlagStandService unit
// (0062b8f0..0062cf40, initializers 007f7e90/007f7ef0, atexit 00800450/00800470). The FlagStandService half lives in
// native-classes/FlagStandService.cpp (another contributor). Evidence in native-headers/v8datamodel/FlagStand.h.
// Verified by tests/record_native_flag_family.py.
// >>> native-status (generated) -- do not edit >>>
// FlagStand | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 7d2ca4f8 | roc native-status --write
#include "v8datamodel/FlagStand.h"
#include "reflection/signal.h"

namespace RBX
{
	char sFlagStand[] = "FlagStand"; // 0095be6c (doDeclare 005bf8e0, classDescriptor 005c38f0, constructor setName)

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

	// Dynamic initializers 007f7e90, 007f7ef0 (in this order).
	static Reflection::PropDescriptor<FlagStand, BrickColor> prop_Color("TeamColor", "Data", &FlagStand::getTeamColor, &FlagStand::setTeamColor, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::SignalDesc<FlagStand, void(boost::shared_ptr<Instance>)> event_FlagCaptured("FlagCaptured", "Player");

	BrickColor FlagStand::getTeamColor() const
	{
		return teamColor;
	}

	FlagStand::FlagStand()
	{
		setName(sFlagStand);
	}

	void FlagStand::setTeamColor(BrickColor color)
	{
		teamColor = color;
		raisePropertyChanged(PartInstance::prop_Color);
	}
}
