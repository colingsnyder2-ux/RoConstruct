// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/SpawnLocation.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/SpawnLocation.h"

#include "humanoid/Humanoid.h"
#include "network/Player.h"
#include "network/Players.h"
#include "reflection/property.h"
#include "v8datamodel/DebrisService.h"
#include "v8datamodel/ForceField.h"
#include "v8datamodel/Workspace.h"

#include <boost/bind.hpp>
#include <stdexcept>
#include <stdlib.h>
#include <vector>

namespace RBX {

const char sSpawnerService[] = "SpawnerService";

char sSpawnLocation[] = "SpawnLocation";

static Reflection::PropDescriptor<SpawnLocation, BrickColor> prop_TeamColor(
	"TeamColor", "Teams", &SpawnLocation::getTeamColor, &SpawnLocation::setTeamColor
);

Reflection::BoundProp<int, 1> SpawnLocation::prop_SpawnForcefieldDuration(
	"Duration", "Forcefield", &SpawnLocation::forcefieldDuration
);

Reflection::BoundProp<bool, 1> SpawnLocation::prop_Neutral("Neutral", "Teams", &SpawnLocation::neutral);
Reflection::BoundProp<bool, 1> SpawnLocation::prop_AllowTeamChangeOnTouch(
	"AllowTeamChangeOnTouch", "Teams", &SpawnLocation::allowTeamChangeOnTouch
);

// FUNCTION: WEBSERVICE 0x100fd500
// FUNCTION: ROBLOX 0x005e4230
BrickColor SpawnLocation::getTeamColor() const
{
	return teamColor;
}

// FUNCTION: WEBSERVICE 0x100fdc00
// FUNCTION: ROBLOX 0x005e4830
void SpawnLocation::onEvent_spawnerTouched(boost::shared_ptr<Instance> other)
{
	if (!allowTeamChangeOnTouch) {
		return;
	}

	Instance* character = other->getParent();
	if (character) {
		Humanoid* humanoid = character->findFirstChildOfType<Humanoid>();
		if (humanoid) {
			Network::Player* player = Network::Players::getPlayerFromCharacter(character);
			if (player) {
				player->setTeamColor(getTeamColor());
				player->setNeutral(neutral);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100fdd80
// FUNCTION: ROBLOX 0x005e4950
SpawnerService::~SpawnerService()
{
}

// FUNCTION: WEBSERVICE 0x100fe770
// FUNCTION: ROBLOX 0x005e5190
void SpawnerService::SpawnPlayer(boost::shared_ptr<ModelInstance> model, Network::Player* p)
{
	Workspace* workspace = ServiceProvider::find<Workspace>(this);
	if (!workspace) {
		throw std::runtime_error("SpawnPlayer couldn't get the workspace");
	}

	if (spawners.size() == 0) {
		workspace->moveToPoint(model.get(), G3D::Vector3(0.0f, 100.0f, 0.0f));
		return;
	}

	std::vector<SpawnLocation*> possibleLocations;

	std::list<SpawnLocation*>::iterator it;
	for (it = spawners.begin(); it != spawners.end(); ++it) {
		if ((*it)->neutral || (!p->getNeutral() && p->getTeamColor() == (*it)->getTeamColor())) {
			possibleLocations.push_back(*it);
		}
	}

	if (possibleLocations.size() == 0) {
		workspace->moveToPoint(model.get(), G3D::Vector3(0.0f, 100.0f, 0.0f));
		return;
	}

	SpawnLocation* location = possibleLocations[rand() % possibleLocations.size()];

	G3D::Vector3 dropPoint = location->getCoordinateFrame().translation;
	dropPoint.y += 7.0f;

	int duration = location->forcefieldDuration;
	if (duration > 0) {
		boost::shared_ptr<ForceField> f = Creatable<Instance>::create<ForceField>();
		f->setParent(model.get());
		DebrisService* debris = ServiceProvider::create<DebrisService>(this);

		debris->addItem(f, location->forcefieldDuration);
	}

	workspace->moveToPoint(model.get(), dropPoint);
}

// FUNCTION: WEBSERVICE 0x100febd0
// FUNCTION: ROBLOX 0x005e55f0
SpawnerService::SpawnerService()
{
	setName(sSpawnerService);
	propArchivable.setValue(this, false);
}

// FUNCTION: WEBSERVICE 0x100fef90
// FUNCTION: ROBLOX 0x005e59e0
SpawnLocation::SpawnLocation() : neutral(true), allowTeamChangeOnTouch(false), forcefieldDuration(10)
{
	setName(sSpawnLocation);
}

// FUNCTION: WEBSERVICE 0x100ff2b0
void SpawnLocation::setTeamColor(BrickColor color)
{
	teamColor = color;
	raisePropertyChanged(prop_TeamColor);
}

// FUNCTION: WEBSERVICE 0x100ff2d0
// FUNCTION: ROBLOX 0x005e5d20
void SpawnLocation::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	Instance::onServiceProvider(oldProvider, newProvider);

	if (oldProvider == NULL) {
		spawnerTouched = PartInstance::event_Touched.connect(
			this, boost::bind(&SpawnLocation::onEvent_spawnerTouched, this, _1), 10
		);

		SpawnerService* spawnerService = newProvider ? newProvider->create<SpawnerService>() : NULL;
		spawnerService->RegisterSpawner(this);
	}

	if (newProvider == NULL) {
		spawnerTouched.disconnect();

		SpawnerService* spawnerService = oldProvider ? oldProvider->find<SpawnerService>() : NULL;
		spawnerService->UnregisterSpawner(this);
	}
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService>;
template class RBX::Reflection::Described<
	RBX::SpawnerService,
	RBX::sSpawnerService,
	RBX::FactoryProduct<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService> >;
template class RBX::DescribedCreatable<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService>;

template class RBX::FactoryProduct<RBX::SpawnLocation, RBX::PartInstance, RBX::sSpawnLocation>;
template class RBX::Reflection::Described<
	RBX::SpawnLocation,
	RBX::sSpawnLocation,
	RBX::FactoryProduct<RBX::SpawnLocation, RBX::PartInstance, RBX::sSpawnLocation> >;
template class RBX::DescribedCreatable<RBX::SpawnLocation, RBX::PartInstance, RBX::sSpawnLocation>;
