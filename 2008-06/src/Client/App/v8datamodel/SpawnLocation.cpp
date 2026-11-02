#include "v8datamodel/SpawnLocation.h"
#include "Network/Players.h"

namespace RBX
{
	static Reflection::PropDescriptor<SpawnLocation, BrickColor> prop_TeamColor("TeamColor", "Teams", &SpawnLocation::getTeamColor, &SpawnLocation::setTeamColor, Reflection::PropertyDescriptor::STANDARD);

	SpawnLocation::SpawnLocation()
		:
		  forcefieldDuration(10), neutral(true),
		  allowTeamChangeOnTouch(false)
	{
		setName("SpawnLocation");
	}

	BrickColor SpawnLocation::getTeamColor() const
	{
		return teamColor;
	}

	void SpawnLocation::setTeamColor(BrickColor color)
	{
		teamColor = color;
		raisePropertyChanged(prop_TeamColor);
	}

	void SpawnLocation::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (!oldProvider)
		{
			spawnerTouched = PartInstance::event_Touched.connect(this, boost::bind(&SpawnLocation::onEvent_spawnerTouched, this, _1), 10);

			SpawnerService* spawnerService = ServiceProvider::create<SpawnerService>(newProvider);

			spawnerService->RegisterSpawner(this);
		}

		if (!newProvider)
		{
			spawnerTouched.disconnect();

			SpawnerService* spawnerService = ServiceProvider::find<SpawnerService>(oldProvider);

			spawnerService->UnregisterSpawner(this);
		}
	}

	SpawnerService::SpawnerService()
	{
		setName("SpawnerService");
		Instance::propArchivable.setValue(this, false);
	}

	SpawnerService::~SpawnerService() {}

	G3D::Vector3 SpawnerService::FindSpawnPositionForPlayer(Network::Player* p)
	{
		if (spawners.empty())
			return G3D::Vector3(0.0f, 100.0f, 0.0f);

		std::vector<SpawnLocation*> possibleLocations;

		for (std::list<SpawnLocation*>::const_iterator iter = spawners.begin(); iter != spawners.end(); iter++)
		{
			if ((*iter)->neutral || (!p->getNeutral() && p->getTeamColor() == (*iter)->getTeamColor()))
			{
				possibleLocations.push_back(*iter);
			}
		}

		if (possibleLocations.empty())
		{
			return G3D::Vector3(0.0f, 100.0f, 0.0f);
		}
		else
		{
			G3D::Vector3 spawnPos = possibleLocations[rand() % possibleLocations.size()]->getCoordinateFrame().translation;
			spawnPos.y += 7.0f;

			return spawnPos;
		}
	}
}
