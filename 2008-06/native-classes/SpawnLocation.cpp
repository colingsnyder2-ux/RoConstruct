// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /fp:fast /DNDEBUG /D_MBCS /I{headers}/part-embedded
// Flags (lf10): /I{headers}/part-embedded gives PartInstance its 2008 non-virtual size 0x3e8, so teamColor sits at
// +0x3e8 as getTeamColor 005d1ba0 / setTeamColor 005d37b0 read it (default include path compiled +0x2d0).
// 2008-06 native RBX::SpawnLocation and RBX::SpawnerService (inactive): one original unit (005d1ba0..005d39f0,
// initializers 007f5f20..007f5fb0, atexit 007feff0..007ff070). Evidence in native-headers/v8datamodel/
// SpawnLocation.h and SpawnerService.h. Verified by tests/record_native_spawn.py.
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/SpawnerService.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/ForceField.h"
#include "v8datamodel/DebrisService.h"
#include "Network/Player.h"
#include <stdexcept>
#include <vector>
#include <stdlib.h>

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

	// 005d2b80 (1084 bytes, ret 0xc; moved from SpawnerServiceSpawnPlayer.cpp in batch 27: getTeamColor 005d1ba0 is
	// defined above in this original unit, so it is inlined as in the target; /fp:fast keeps y + 7 in a register).
	// Identity: string 0083bda0 "SpawnPlayer couldn't get the workspace"; donor
	// tools/openrbx Client/App/v8datamodel/SpawnLocation.cpp SpawnerService::SpawnPlayer; caller
	// Player::loadCharacter 004957a0. Callees: find<Workspace> 00491e50, RootInstance::moveToPoint 005909e0
	// (Vector3(0, 100 [008163a4], 0)), PartInstance::getCoordinateFrame 00598cb0 (+7 [00831db4] on y),
	// create<ForceField> 005c1520, Instance::setParent 0055a8f0, ServiceProvider::create<DebrisService>(const
	// Instance*) 005d2b30, DebrisService::addItem 0063bbc0 (fild of duration +0x404 to double).
	void SpawnerService::SpawnPlayer(boost::shared_ptr<ModelInstance> model, Network::Player* p)
	{
		Workspace* workspace = ServiceProvider::find<Workspace>(this);
		if (!workspace)
			throw std::runtime_error("SpawnPlayer couldn't get the workspace");

		if (spawners.size() == 0)
		{
			workspace->moveToPoint(model.get(), G3D::Vector3(0.0f, 100.0f, 0.0f));
			return;
		}

		std::vector<SpawnLocation*> possibleLocations;

		std::list<SpawnLocation*>::iterator it;
		for (it = spawners.begin(); it != spawners.end(); ++it)
		{
			if ((*it)->neutral)
				possibleLocations.push_back(*it);
			else if (!p->getNeutral() && p->getTeamColor() == (*it)->getTeamColor())
				possibleLocations.push_back(*it);
		}

		if (possibleLocations.size() == 0)
		{
			workspace->moveToPoint(model.get(), G3D::Vector3(0.0f, 100.0f, 0.0f));
			return;
		}

		SpawnLocation* location = possibleLocations[rand() % possibleLocations.size()];

		G3D::Vector3 dropPoint = location->getCoordinateFrame().translation;
		dropPoint.y += 7.0f;

		int duration = location->duration;
		if (duration > 0)
		{
			boost::shared_ptr<ForceField> f = Creatable<Instance>::create<ForceField>();
			f->setParent(model.get());
			DebrisService* debris = ServiceProvider::create<DebrisService>(this);
			debris->addItem(f, location->duration);
		}

		workspace->moveToPoint(model.get(), dropPoint);
	}

	// 005d30c0: Instance::propArchivable (BoundProp<bool,1> 00973e74, initializer 007f28e0) set through the 2008
	// TypedPropertyDescriptor::GetSet setValue (slot 3, +0xc). The ctor instantiates DescribedCreatable<SpawnerService,
	// Instance, sSpawnerService>() (005d2fc0, 005d1d10) implicitly.
	SpawnerService::SpawnerService()
	{
		setName("SpawnerService");
		Instance::propArchivable.setValue(this, false);
	}

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
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
