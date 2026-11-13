// 2008-06 native rows of the Creatable / FactoryProduct block 0048e6e0..004907ff and 00494940..00494a9f inside the
// application range 0048c000..00498000 (Network/Player.cpp unit, inactive). Verified by
// tests/record_native_app_unit48c_2008.py. All headers are read-only here.
//
// The block is one run of compiler-emitted template instances. Each class has up to four bodies:
//   * FactoryProduct<C, D, N>::Creator::create() const (175 B, slot 0 of the Creator vtable 00821768..00821b30):
//     calls Creatable<Instance>::create<C>() and returns it as shared_ptr<Object>;
//   * boost::detail::shared_count(C*, Creatable<Instance>::Deleter) (131 B; counted by creatable-shared-count);
//   * boost::shared_ptr<C>(C*, Creatable<Instance>::Deleter) (171 B, the enable_shared_from_this hook-up);
//   * Creatable<Instance>::create<C>() (120 / 122 B: malloc(sizeof(C)), C(), shared_ptr<C>(p, Deleter())).
// Classes in link order: HopperBin, StarterPackService, LegacyHopperService, Backpack (Creator only; create<Backpack>
// 0048bc20 is counted by app-unit480), SpawnLocation, SpawnerService, ShirtGraphic, Clothing, Pants / Shirt (shared_ptr ctors here,
// create / Creator at 004941d0..004949ff), BodyColors, Skin, Teams, TimerService (Creator only; create<TimerService>
// 0048bcf0 is counted by app-unit480). Humanoid is in AppUnit48C_2008CreatorsHumanoid.cpp (humanoid/Humanoid2008.h).
// sizeof(C) comes from the native headers and is checked by the malloc size each create<C> passes.
// >>> native-status (generated) -- do not edit >>>
// AppUnit48C_2008Creators | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 141adb9c | roc native-status --write
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/SpawnerService.h"
#include "v8datamodel/Clothing.h"
#include "v8datamodel/BodyColors.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/TimerService.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only; this is the definition every Creator vtable slot 0 reaches.
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}

template boost::shared_ptr<RBX::HopperBin> RBX::Creatable<RBX::Instance>::create<RBX::HopperBin>();
template boost::shared_ptr<RBX::StarterPackService> RBX::Creatable<RBX::Instance>::create<RBX::StarterPackService>();
template boost::shared_ptr<RBX::LegacyHopperService> RBX::Creatable<RBX::Instance>::create<RBX::LegacyHopperService>();
template boost::shared_ptr<RBX::SpawnLocation> RBX::Creatable<RBX::Instance>::create<RBX::SpawnLocation>();
template boost::shared_ptr<RBX::SpawnerService> RBX::Creatable<RBX::Instance>::create<RBX::SpawnerService>();
template boost::shared_ptr<RBX::ShirtGraphic> RBX::Creatable<RBX::Instance>::create<RBX::ShirtGraphic>();
template boost::shared_ptr<RBX::Clothing> RBX::Creatable<RBX::Instance>::create<RBX::Clothing>();
template boost::shared_ptr<RBX::Pants> RBX::Creatable<RBX::Instance>::create<RBX::Pants>();
template boost::shared_ptr<RBX::Shirt> RBX::Creatable<RBX::Instance>::create<RBX::Shirt>();
template boost::shared_ptr<RBX::BodyColors> RBX::Creatable<RBX::Instance>::create<RBX::BodyColors>();
template boost::shared_ptr<RBX::Skin> RBX::Creatable<RBX::Instance>::create<RBX::Skin>();
template boost::shared_ptr<RBX::Teams> RBX::Creatable<RBX::Instance>::create<RBX::Teams>();

template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::HopperBin, RBX::BackpackItem, RBX::sHopperBin>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::StarterPackService, RBX::Hopper, RBX::sStarterPackService>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::LegacyHopperService, RBX::Hopper, RBX::sLegacyHopperService>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Backpack, RBX::Hopper, RBX::sBackpack>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::SpawnLocation, RBX::PartInstance, RBX::sSpawnLocation>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::ShirtGraphic, RBX::CharacterAppearance, RBX::sShirtGraphic>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Clothing, RBX::CharacterAppearance, RBX::sClothing>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Pants, RBX::Clothing, RBX::sPants>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Shirt, RBX::Clothing, RBX::sShirt>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Teams, RBX::Instance, RBX::sTeams>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::TimerService, RBX::Instance, RBX::sTimerService>::Creator::create() const;

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::BodyColors>;
template class boost::shared_ptr<RBX::Clothing>;
template class boost::shared_ptr<RBX::HopperBin>;
template class boost::shared_ptr<RBX::LegacyHopperService>;
template class boost::shared_ptr<RBX::Pants>;
template class boost::shared_ptr<RBX::Shirt>;
template class boost::shared_ptr<RBX::ShirtGraphic>;
template class boost::shared_ptr<RBX::Skin>;
template class boost::shared_ptr<RBX::SpawnLocation>;
template class boost::shared_ptr<RBX::SpawnerService>;
template class boost::shared_ptr<RBX::StarterPackService>;
template class boost::shared_ptr<RBX::Teams>;
