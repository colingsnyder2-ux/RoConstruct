// Rebuild glue: touch handlers and service hookups rbxgs declares but never defines (replacing empty
// stubs). Seat seats a touching character (after a short re-seat delay) and unseats it on jump;
// a team spawn recolours the touching player; flags go to enemy players and are returned home on a
// friendly touch; a peer pumps RakNet on each heartbeat, as Explosion connects to Stepped.
// Behavioural reconstructions, not byte-verified.
#include <RakPeer.h>  // first, as rbxgs Players.cpp: RakNet needs winsock2 before windows.h
#include "Replicator.h"
#include "Server.h"
#include "PacketIds.h"
#include "Streaming.h"
#include <BitStream.h>
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



	// Flag::canBePickedUpByPlayer: native (Flag.cpp)

	// Flag::onEvent_flagTouched: native (Flag.cpp)

	// Flag::onServiceProvider: native (Flag.cpp)

	// an enemy flag carried onto a team's stand is captured and sent back to its own stand


	// the nearest stand of the flag's team that holds no flag, measured from the flag's Handle
	FlagStand* FlagStandService::FindClosestEmptyStandForFlag(Flag* flag)
	{
		PartInstance* handle = dynamic_cast<PartInstance*>(flag->findFirstChildByName("Handle"));
		G3D::Vector3 from = handle ? handle->getCoordinateFrame().translation : G3D::Vector3::zero();

		FlagStand* best = NULL;
		float bestDistance = 0.0f;
		for (std::list<FlagStand*>::const_iterator iter = flagStands.begin(); iter != flagStands.end(); iter++)
		{
			FlagStand* stand = *iter;
			if (stand->HasFlag() || stand->getTeamColor() != flag->getTeamColor())
				continue;
			float distance = (stand->getCoordinateFrame().translation - from).squaredLength();
			if (!best || distance < bestDistance)
			{
				best = stand;
				bestDistance = distance;
			}
		}
		return best;
	}

	namespace Network
	{
		// ID_CHAT_ALL as Players::chat writes it: speaker guid (scope name, index), then the message.
		// A server relays it to every other connection.

	}
}
