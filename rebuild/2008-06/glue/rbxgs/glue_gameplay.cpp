// Rebuild glue: touch handlers and service hookups rbxgs declares but never defines (replacing empty
// stubs). Seat seats a touching character (after a short re-seat delay) and unseats it on jump;
// a team spawn recolours the touching player; flags go to enemy players and are returned home on a
// friendly touch; a peer pumps RakNet on each heartbeat, as Explosion connects to Stepped.
// Behavioural reconstructions, not byte-verified.
#include <RakPeer.h>  // first, as rbxgs Players.cpp: RakNet needs winsock2 before windows.h
#include "Replicator.h"
#include "Network/Players.h"
#include "Network/Player.h"
#include "v8datamodel/Seat.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
#include <G3D/System.h>
#include <boost/bind.hpp>

namespace RBX
{
	namespace
	{
		Humanoid* characterOf(const boost::shared_ptr<Instance>& touched)
		{
			PartInstance* part = dynamic_cast<PartInstance*>(touched.get());
			return part && part->getParent() ? Humanoid::modelIsCharacter(part->getParent()) : NULL;
		}

		void returnHome(Flag* flag, const ServiceProvider* provider)
		{
			if (FlagStandService* stands = ServiceProvider::find<FlagStandService>(provider))
				if (FlagStand* home = stands->FindClosestEmptyStandForFlag(flag))
					home->AffixFlag(flag);
		}
	}

	void Seat::onEvent_seatTouched(boost::shared_ptr<Instance> other)
	{
		if (weld || G3D::System::getLocalTime() - sleepTime < 3.0)
			return;
		Humanoid* humanoid = characterOf(other);
		if (!humanoid || !humanoid->getTorso())
			return;
		seatCharacter(humanoid);
		humanoidJumped = Humanoid::event_Jumping.connect(humanoid, boost::bind(&Seat::onEvent_humanoidJumped, this, _1));
	}

	void SpawnLocation::onEvent_spawnerTouched(boost::shared_ptr<Instance> other)
	{
		if (neutral || !allowTeamChangeOnTouch)
			return;
		Humanoid* humanoid = characterOf(other);
		if (!humanoid)
			return;
		if (Network::Player* player = Network::Players::getPlayerFromCharacter(humanoid->getParent()))
		{
			player->setNeutral(false);
			player->setTeamColor(teamColor);
		}
	}

	bool Flag::canBePickedUpByPlayer(Network::Player* player)
	{
		return player && !player->getNeutral() && player->getTeamColor() != teamColor;
	}

	void Flag::onEvent_flagTouched(boost::shared_ptr<Instance> other)
	{
		Humanoid* humanoid = characterOf(other);
		if (!humanoid || getParent() == humanoid->getParent())
			return;
		Network::Player* player = Network::Players::getPlayerFromCharacter(humanoid->getParent());
		if (player && !player->getNeutral() && player->getTeamColor() == teamColor)
			returnHome(this, ServiceProvider::findServiceProvider(this));
	}

	void Flag::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		Tool::onServiceProvider(oldProvider, newProvider);
		flagTouched.disconnect();
		if (newProvider)
			if (PartInstance* handle = getHandle())
				flagTouched = PartInstance::event_Touched.connect(handle, boost::bind(&Flag::onEvent_flagTouched, this, _1));
	}

	// an enemy flag carried onto a team's stand is captured and sent back to its own stand
	void FlagStand::onEvent_standTouched(boost::shared_ptr<Instance> other)
	{
		Humanoid* humanoid = characterOf(other);
		if (!humanoid)
			return;
		Flag* carried = humanoid->getParent()->findFirstChildOfType<Flag>();
		if (carried && carried->getTeamColor() != teamColor)
			returnHome(carried, ServiceProvider::findServiceProvider(this));
	}

	namespace Network
	{
		void Peer::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			Notifier<RunService, Heartbeat>::disconnect(ServiceProvider::find<RunService>(oldProvider), this);
			Instance::onServiceProvider(oldProvider, newProvider);
			Notifier<RunService, Heartbeat>::connect(ServiceProvider::find<RunService>(newProvider), this);
		}
	}
}
