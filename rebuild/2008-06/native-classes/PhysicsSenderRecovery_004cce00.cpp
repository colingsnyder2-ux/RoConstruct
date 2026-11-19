// 2008-06 native RBX::Network::PhysicsSender step/sendPackets recovery (inactive).
// Layout and virtual identities: native-headers/Network/PhysicsSenders2008.h.
// Statement order follows the byte-exact mined analogs; all object access uses the native classes.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#include "Network/PhysicsSenders2008.h"
#include "Network/Replicator2008.h"
#include "Network/NetworkSettings.h"
#include "Network/Player.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/PhysicsService.h"
#include "v8tree/Service.h"
#include "reflection/signal.h"
#include <RakPeerInterface.h>
#include <GetTime.h>
#include <boost/bind.hpp>
#include <algorithm>

namespace
{
	// Mutable .data float 0093cc40 in the client.
	float physicsResetValue = 2.0f;

	// 004c9cf0: the modifier bound by sendPackets at 004cd02d.
	void resetPhysicsItem(RBX::Network::PhysicsSender::PartItem& item)
	{
		item.lastFrame = item.part->getCoordinateFrame();
		item.accumulated = physicsResetValue;
		item.lastSendStep = 0;
	}
}

namespace RBX
{
	namespace Network
	{
		int PhysicsSender::sendPackets(int maxPackets)
		{
			PartItems::nth_index<1>::type& index = items.get<1>();
			PartItems::nth_index<1>::type::iterator& cursor = nextItem;
			unsigned int maxBytes = this->replicator->peer->GetMTUSize(this->replicator->remotePlayerId);
			maxBytes += NetworkSettings::singleton().physicsMtuAdjust;
			RakNet::BitStream packet(maxBytes);
			int packets = 0;
			bool open = false;

			while (cursor != index.end())
			{
				if (!open)
				{
					if (packets >= maxPackets)
						break;
					packet.Reset();
					++packets;
					open = true;
					packet << (unsigned char)24;
					packet << (int)RakNet::GetTime();
					packet << (unsigned char)80;
				}

				PartItem snapshot(*cursor);
				if (!writePhysicsSnapshot(packet, snapshot))
				{
					++cursor;
					continue;
				}

				if (snapshot.part->getPrimitive()->getAssembly())
				{
					snapshot.accumulated = physicsResetValue;
					snapshot.lastFrame = snapshot.part->getCoordinateFrame();
					index.modify(cursor, boost::bind(&resetPhysicsItem, _1));
					++cursor;
				}
				else
				{
					cursor = index.erase(cursor);
				}

				if ((unsigned int)packet.GetNumberOfBytesUsed() > maxBytes)
				{
					this->replicator->serializeId(packet, 0);
					this->replicator->peer->Send(&packet, MEDIUM_PRIORITY, RELIABLE_SEQUENCED, 0,
						this->replicator->remotePlayerId, false);
					open = false;
				}
			}

			if (open)
			{
				this->replicator->serializeId(packet, 0);
				this->replicator->peer->Send(&packet, MEDIUM_PRIORITY, RELIABLE_SEQUENCED, 0,
					this->replicator->remotePlayerId, false);
			}
			return packets;
		}

		void PhysicsSender::step()
		{
			if (!physicsService)
			{
				physicsService = shared_from(ServiceProvider::create<PhysicsService>(replicator));
				std::for_each(physicsService->parts.begin(), physicsService->parts.end(),
					boost::bind(&PhysicsSender::addPhysicsInstance, this,
						boost::bind(&shared_from<Instance>, _1)));
				partAddedConnection = PhysicsService::eventAdded.connect(physicsService.get(),
					boost::bind(&PhysicsSender::addPhysicsInstance, this, _1), 10);
			}

			++stepCount;
			ModelInstance* character = 0;
			G3D::CoordinateFrame playerFrame;
			Player* player = this->replicator->findTargetPlayer();
			if (player)
			{
				character = player->getCharacter();
				if (character)
				{
					PartInstance* primary = character->getPrimaryPart();
					if (primary)
						playerFrame = primary->getCoordinateFrame();
				}
			}

			int budget = NetworkSettings::singleton().physicsReplicationUpdateRate / 30;
			if (!budget)
				budget = 1;
			PartItems::nth_index<2>::type& index = items.get<2>();
			while (budget > 0)
			{
				PartItems::nth_index<2>::type::iterator next = index.begin();
				if (next == index.end())
					break;
				PartItem snapshot(*next);
				if (snapshot.lastSendStep > 0)
					--budget;
				if (snapshot.update(playerFrame, character, stepCount))
					index.replace(next, snapshot);
				else
					break;
			}
			nextItem = items.get<1>().begin();
		}
	}
}
