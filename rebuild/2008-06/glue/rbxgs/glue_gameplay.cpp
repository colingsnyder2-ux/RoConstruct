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

	bool FlagStand::HasFlag()
	{
		return GetFlag() != NULL;
	}

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
		bool Players::OnReceive(RakPeerInterface* peer, Packet* packet)
		{
			if (packet->data[0] != ID_CHAT_ALL)
				return false;

			RakNet::BitStream bitStream(packet->data, packet->length, false);
			unsigned char id;
			std::string scope, message;
			int index;
			bitStream >> id;
			bitStream >> scope;
			bitStream >> index;
			bitStream >> message;

			boost::shared_ptr<Player> source;
			boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > list = getPlayers();
			if (list)
				for (size_t i = 0; i < list->size() && !source; ++i)
				{
					Guid::Data data;
					(*list)[i]->getGuid().extract(data);
					if (data.index == index && data.scope->toString() == scope)
						source = boost::shared_static_cast<Player>((*list)[i]);
				}

			ChatMessage event = {message, source, boost::shared_ptr<Player>()};
			addChatMessage(event);
			Notifier<Players, ChatMessage>::raise(event);

			if (Server::serverIsPresent(this, false))
			{
				RakNet::BitStream relay(packet->data, packet->length, false);
				peer->Send(&relay, MEDIUM_PRIORITY, RELIABLE, 2, packet->systemAddress, true);
			}
			return true;
		}

		void Peer::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			Notifier<RunService, Heartbeat>::disconnect(ServiceProvider::find<RunService>(oldProvider), this);
			Instance::onServiceProvider(oldProvider, newProvider);
			Notifier<RunService, Heartbeat>::connect(ServiceProvider::find<RunService>(newProvider), this);
		}
	}
}
