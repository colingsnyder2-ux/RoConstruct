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

template class std::_Container_base_aux_alloc_real<std::allocator<RBX::SpawnLocation *> >;
template class std::_List_nod<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >;
template class std::_List_ptr<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >;
template class std::_List_val<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >;
template class std::allocator<std::_List_nod<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >::_Node *>;
template class std::allocator<std::_List_nod<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >::_Node>;
template class std::list<RBX::SpawnLocation *,std::allocator<RBX::SpawnLocation *> >;
