// 2008-06 native RBX::SpawnLocation and RBX::SpawnerService (inactive): one original unit (005d1ba0..005d39f0,
// initializers 007f5f20..007f5fb0, atexit 007feff0..007ff070). Evidence in native-headers/v8datamodel/
// SpawnLocation.h and SpawnerService.h. Verified by tests/record_native_spawn.py.
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/SpawnerService.h"

namespace RBX
{
	char sSpawnLocation[] = "SpawnLocation";         // 009525cc (doDeclare 00489e60)
	const char sSpawnerService[] = "SpawnerService"; // 0083ba38 (doDeclare 00489ed0)

	// Template members the shared headers only declare (same definitions as Team.cpp / DecalBases.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	// Dynamic initializers 007f5f20, 007f5f50, 007f5f80, 007f5fb0 (in this order).
	Reflection::BoundProp<int, 1> SpawnLocation::prop_Duration("Duration", "Forcefield", &SpawnLocation::duration, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<bool, 1> SpawnLocation::prop_Neutral("Neutral", "Teams", &SpawnLocation::neutral, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<bool, 1> SpawnLocation::prop_AllowTeamChangeOnTouch("AllowTeamChangeOnTouch", "Teams", &SpawnLocation::allowTeamChangeOnTouch, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<SpawnLocation, BrickColor> prop_TeamColor("TeamColor", "Teams", &SpawnLocation::getTeamColor, &SpawnLocation::setTeamColor, Reflection::PropertyDescriptor::STANDARD);

	BrickColor SpawnLocation::getTeamColor() const
	{
		return teamColor;
	}

	SpawnerService::~SpawnerService()
	{
	}

#ifdef NATIVE_SPAWN_PENDING
	// Needs Instance::propArchivable (BoundProp<bool,1> 00973e74, initializer 007f28e0) in v8tree/Instance.h and the
	// 2008 TypedPropertyDescriptor::GetSet second bool virtual (setValue is slot 3, +0xc). Verified against generated
	// header copies by the recorder.
	SpawnerService::SpawnerService()
	{
		setName("SpawnerService");
		Instance::propArchivable.setValue(this, false);
	}
#else
	// The SpawnerService constructor is pending; instantiate its base constructor so the template bodies the original
	// emits in this unit (005d2fc0, 005d1d10) are also compiled from the current headers.
	template DescribedCreatable<SpawnerService, Instance, sSpawnerService>::DescribedCreatable();
#endif

	SpawnLocation::SpawnLocation()
		: neutral(true),
		  allowTeamChangeOnTouch(false),
		  duration(10)
	{
		setName("SpawnLocation");
	}

	void SpawnLocation::setTeamColor(BrickColor color)
	{
		teamColor = color;
		raisePropertyChanged(prop_TeamColor);
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::SpawnLocation *> >;
template class std::_List_nod<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >;
template class std::_List_ptr<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >;
template class std::_List_val<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >;
template class std::allocator<std::_List_nod<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >::_Node *>;
template class std::allocator<std::_List_nod<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >::_Node>;
template class std::list<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >;
