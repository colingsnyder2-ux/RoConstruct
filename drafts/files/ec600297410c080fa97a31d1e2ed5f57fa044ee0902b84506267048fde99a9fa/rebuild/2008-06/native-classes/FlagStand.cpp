// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-function-pod-vtable /I{headers}/part-embedded
// 2008-06 native RBX::FlagStand (inactive): the FlagStand half of the original FlagStand/FlagStandService unit
// (0062b8f0..0062cf40, initializers 007f7e90/007f7ef0, atexit 00800450/00800470). The FlagStandService half lives in
// native-classes/FlagStandService.cpp (another contributor). Evidence in native-headers/v8datamodel/FlagStand.h.
// Verified by tests/record_native_flag_family.py.
#include "v8datamodel/FlagStand.h"
#include "reflection/signal.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/FlagStandService.h"
#include "humanoid/Humanoid2008.h"
#include "Network/Player.h"
#include "Network/Players.h"
#include <boost/bind.hpp>
#include <boost/thread/once.hpp>

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

	// 0062c9c0 (425 bytes, ret 4): byte-identical (relocs masked); credited only once PartInstance.h declares setName
	// 00598c20 and PVInstance::onChildRemoving binds to 00608a60 (see Seat.cpp).
	FlagStand::FlagStand()
	{
		setName(sFlagStand);
	}

	// 0062b900: embedded Primitive +0x228, Primitive::getFirstRigid 005e7c80 / getNextRigid 005e7ca0, the joint's two
	// primitives (+0xc, +0x10), PartInstance::fromPrimitive 00599f80, parent +0x104, __RTDynamicCast Instance -> Flag
	// (RTTI 0092907c -> 0094be40). Donor tools/rbxgs v8datamodel/FlagStand.cpp FlagStand::GetFlag.
	Flag* FlagStand::GetFlag()
	{
		Primitive* primitive = getPrimitive();

		for (RigidJoint* current = primitive->getFirstRigid(); current != NULL; current = primitive->getNextRigid(current))
		{
			for (int i = 0; i < 2; i++)
			{
				Flag* flag = dynamic_cast<Flag*>(PartInstance::fromPrimitive(current->getPrimitive(i))->getParent());
				if (flag)
					return flag;
			}
		}

		return NULL;
	}

	void FlagStand::setTeamColor(BrickColor color)
	{
		teamColor = color;
		raisePropertyChanged(PartInstance::prop_Color);
	}

	// INFERRED: the 2007 openrbx FlagStand.h defines RegisterFlagStand / UnregisterFlagStand inline in the class
	// (flagStands.push_back / remove); the 2008 binary has no out-of-line copy (onServiceProvider 0062cf40 inlines the
	// push_back through _Buynode 0064d0b0 / _Incsize 005f26c0 and calls list::remove 0062c0c0 directly), while
	// v8datamodel/FlagStandService.h declares them out of line (header proposal: make them inline there).
	inline void FlagStandService::RegisterFlagStand(FlagStand* flagStand)
	{
		flagStands.push_back(flagStand);
	}

	inline void FlagStandService::UnregisterFlagStand(FlagStand* flagStand)
	{
		flagStands.remove(flagStand);
	}

	// 0062cde0 (thiscall, ret 8; bound into standTouched by onServiceProvider 0062cf40): Humanoid::modelIsCharacter
	// 005d9a20 on the parent (+0x104), findFirstChildOfType<Flag> 0062bf20, Players::getPlayerFromCharacter 0049acd0,
	// Player neutral +0x17c / teamColor +0x178 against teamColor +0x3fc, Flag::getTeamColor 00618380,
	// event_FlagCaptured (0097c060) fire 0049d200 with shared_from(player) 00618a40, create<FlagStandService>(this)
	// 00619450, FindClosestEmptyStandForFlag 0062c2e0, AffixFlag 0062bdc0. Shape: 2007 openrbx FlagStand.cpp.
	void FlagStand::onEvent_standTouched(boost::shared_ptr<Instance> other)
	{
		Instance* character = other->getParent();
		if (!Humanoid::modelIsCharacter(character))
			return;

		Flag* flag = character->findFirstChildOfType<Flag>();
		if (!flag)
			return;

		Network::Player* player = Network::Players::getPlayerFromCharacter(character);
		if (!player)
			return;
		if (player->getNeutral())
			return;

		if (player->getTeamColor() == getTeamColor() && flag->getTeamColor() != getTeamColor())
		{
			event_FlagCaptured.fire(this, shared_from(player));

			FlagStandService* flagStandService = ServiceProvider::create<FlagStandService>(this);
			FlagStand* stand = flagStandService->FindClosestEmptyStandForFlag(flag);
			if (stand)
				stand->AffixFlag(flag);
		}
	}

	// ServiceProvider::create<FlagStandService>() const 00619360 (registry placeholder func_00619360, 228 B), called
	// out of line by onServiceProvider 0062cf40 below: find<FlagStandService>() 00619080 (FlagStandServiceFind.cpp; only
	// declared here), Creatable<Instance>::create<FlagStandService> 005c12b0, getClassIndex (call_once 00557330 on
	// callDoGetClassIndex 00618650, doGetClassIndex 00618520), the serviceArray (+0x190) store 004025b0 and setParent
	// 0055a8f0. v8tree/Service.h declares these templates without bodies (definitions as AppUnit454_2008ReportStats.cpp).
	template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
	template<class Class> size_t ServiceProvider::getClassIndex()
	{
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}

	template<class Class> Class* ServiceProvider::create() const
	{
		Class* service = find<Class>();
		if (service == NULL)
		{
			boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
			service = value.get();
			size_t index = getClassIndex<Class>();
			serviceArray[index] = value;
			service->setParent(const_cast<ServiceProvider*>(this));
		}
		return service;
	}

	// 0062cf40 (vtable 0084657c slot 12, ret 8): no base-class call in the 2008 body. create<FlagStandService>
	// 00619360 on the provider, RegisterFlagStand (inline push_back), PartInstance::event_Touched (00976164)
	// connect 004a3340 with boost::bind(&FlagStand::onEvent_standTouched, this, _1) and group 10 into standTouched
	// +0x3e8 (scoped_connection::operator= 00595540); on removal list::remove 0062c0c0 and disconnect 00595230.
	// The bind's boost::slot constructor 0062c590 and function1::assign_to 0062c160 are emitted by this unit; both are
	// byte-identical only with /I{headers}/boost-function-pod-vtable (assign_to takes the functor by reference).
	void FlagStand::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (oldProvider == NULL)
		{
			FlagStandService* flagStandService = newProvider ? newProvider->create<FlagStandService>() : NULL;
			flagStandService->RegisterFlagStand(this);

			standTouched = PartInstance::event_Touched.connect(this, boost::bind(&FlagStand::onEvent_standTouched, this, _1), 10);
		}

		if (newProvider == NULL)
		{
			FlagStandService* flagStandService = oldProvider ? oldProvider->create<FlagStandService>() : NULL;
			flagStandService->UnregisterFlagStand(this);

			standTouched.disconnect();
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Vector_const_iterator<RBX::Primitive const *,std::allocator<RBX::Primitive const *> >;
template class std::_Vector_iterator<RBX::Primitive const *,std::allocator<RBX::Primitive const *> >;
