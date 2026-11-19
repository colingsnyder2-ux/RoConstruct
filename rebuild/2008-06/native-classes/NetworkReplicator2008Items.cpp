// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#undef _RELEASEASSERT // 004b6d10 builds its ConstProperty without RBXASSERT(isMemberOf) (as NetworkReplicator2008StatsItem.cpp)
// 2008-06 native RBX::Network::Replicator item/sender rows (inactive): Replicator::ItemSender::~ItemSender 004aba60,
// Replicator::MarkerItem::write 004ae9a0, Replicator::remoteDeleteOnDisconnect 004ab960, ChangePropertyItem::write
// 004b6d10 (near miss), getPlayer 004ae860, closeConnection 004aafd0, requestCharacter 004b49e0 and the +0x2c38 map
// members (implicit ReplicationData destructor 004ab8c0). Shapes after the donor
// tools/rbxgs Client/Network/Replicator.cpp; declarations in native-headers/Network/Replicator2008.h.
#include "Network/Replicator2008.h"
#include "Network/NetworkSettings.h"
#include "Network/Players.h"
#include "util/standardout.h"
#include "RakPeerInterface.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "v8datamodel/ModelInstance.h"
#include "BitStream.h"
#include "Network/Player.h"
#include <stdexcept>

namespace RBX
{
	namespace Network
	{
		// 004aba60: a partly filled packet is terminated with ItemTypeEnd and sent (peer slot 0x34 Send, MEDIUM_PRIORITY,
		// RELIABLE_ORDERED, channel 0, remotePlayerId, no broadcast), then the stream is reset.
		Replicator::ItemSender::~ItemSender()
		{
			int bytesUsed = bitStream.GetNumberOfBytesUsed();
			if (bytesUsed > 0)
			{
				Item::writeItemType(bitStream, Item::ItemTypeEnd);
				peer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, replicator.remotePlayerId, false);
			}
			bitStream.Reset(); // outside the if in the target (jle lands on the Reset call)
		}

		// 004ab5d0 (donor Replicator::Item::writeItemType): Delete/New/ChangeProperty are 2-bit codes, every other type is
		// the 2-bit escape 0 followed by the full 32-bit value.
		void Replicator::Item::writeItemType(RakNet::BitStream& stream, ItemType value)
		{
			if (value >= ItemTypeDelete && value <= ItemTypeChangeProperty)
			{
				stream.WriteBits((unsigned char*)&value, 2, true);
			}
			else
			{
				unsigned char zero = 0;
				stream.WriteBits(&zero, 2, true);
				stream.Write(value);
			}
		}

		// 004ae9a0
		void Replicator::MarkerItem::write(RakNet::BitStream& bitStream)
		{
			writeItemType(bitStream, ItemTypeMarker);
			bitStream << (int)id;

			if (NetworkSettings::singleton().printInstances)
			{
				StandardOut::singleton()->print(MESSAGE_INFO, "Replication: Sending marker %d to %s", id, replicator.remotePlayerId.ToString(true));
			}

			replicator.onSentMarker(id);
		}

		// 004ab960 (virtual slot 20): exact with the donor if/else inline isDescendentOf shape (helper above), which lays
		// the `mov al,1; ret 4` block first. Rejected: raw member comparison with `if (...) return true` (59 B, block
		// order swapped), locals, single `return a || b` (63 B), direct `return instance == findLocalCharacter` (63 B).
		// INFERRED: the donor v8tree/Instance.h inline isDescendentOf body (if/else form); the native Instance.h declares
		// it out of line only (00422ae0), so the inlined first level is spelled here.
		static inline bool isDescendentOfInline(const Instance* self, const Instance* ancestor)
		{
			Instance* thisParent = self->getParent();
			if (ancestor == thisParent)
				return true;

			if (thisParent)
				return thisParent->isDescendentOf(ancestor);
			else
				return false;
		}

		bool Replicator::remoteDeleteOnDisconnect(const Instance* instance) const
		{
			// The target inlines the first level of Instance::isDescendentOf (004ab960 compares the +0x104 parent with
			// players, then calls 00422ae0 on the parent).
			if (isDescendentOfInline(instance, players))
				return true;

			if (instance == Players::findLocalCharacter(instance))
				return true;

			return false;
		}

		// 004b6d10 (donor Replicator::ChangePropertyItem::write; statement order after the server-verified mined analog
		// src/2008-06/004b6d10.cpp). The 2008 replication-scope test is a lookup of the instance in the +0x2c38 map
		// (find 004adfd0) instead of the donor isInReplicationScope; writeItemType 004ab5d0, serializeId 004a8ae0,
		// propNames.send 004aeba0, NetworkSettings printProperties (+0x132), registerGuid 0049bba0,
		// Guid::readableString 004aadd0, "Replication: %s:%s.%s >> %s" 0082501c, serializeValue 004b6890.
		// NEAR MISS (nw04 b23, parked after 3 hypotheses): 491 B vs 490 B. The target loads the instance pointer once into
		// edi before registerGuid and keeps it (lea ebp,[edi+0x10] for getClassName, lea ecx,[edi+8] for the guid); this
		// compile reloads [esi+0xc] after the call. Rejected: (1) separate registerGuid statement on instance.get()
		// (515 B, plus an RBXASSERT compare fixed by the #undef above); (2) a local Instance* for registerGuid /
		// getClassName / getGuid (482 B, lea ebp computed after the call); (3) this comma form inside the argument list.
		// Likely needs the 2008 GuidItem::getGuid() that registers itself (util/GuidItem.h proposal).
		void Replicator::ChangePropertyItem::write(RakNet::BitStream& bitStream)
		{
			if (replicator.containerConnections.find(instance.get()) != replicator.containerConnections.end())
			{
				writeItemType(bitStream, ItemTypeChangeProperty);

				replicator.serializeId(bitStream, instance.get());
				replicator.propNames.send(bitStream, desc);

				if (NetworkSettings::singleton().printProperties)
				{
					// INFERRED: the target registers the guid (0049bba0) inside the argument list, right before
					// Guid::readableString reads it inline (the 2008 getGuid() registers first; util/GuidItem.h proposal).
					StandardOut::singleton()->print(MESSAGE_INFO, "Replication: %s:%s.%s >> %s",
						instance->getClassName().c_str(),
						(const_cast<Instance*>(instance.get())->registerGuid(), instance->getGuid()).readableString(4).c_str(),
						desc.name.c_str(),
						replicator.remotePlayerId.ToString(true));
				}

				replicator.serializeValue(Reflection::ConstProperty(desc, instance.get()), true, bitStream);
			}
		}

		// 004ae860 (donor Replicator.h inline getPlayer; findTargetPlayer slot 17, shared_from<Player> 00618a40)
		boost::shared_ptr<Instance> Replicator::getPlayer()
		{
			return shared_from(findTargetPlayer());
		}

		// 004aafd0 (donor Replicator::closeConnection; the 2008 body tests peer first): CloseConnection slot 0x64.
		void Replicator::closeConnection()
		{
			if (peer)
				peer->CloseConnection(remotePlayerId, true);
			setParent(NULL);
		}

		// 004b49e0 (donor Replicator::requestCharacter; the 2008 body first throws without a connection):
		// "Attempting to send a Character request without a connection" 00824da8 / "... without a local Player"
		// 00824d68, operator<<(uchar) 004a6350 with 0x4c (2008 ID_REQUEST_CHARACTER), serializeId 004a8ae0,
		// printInstances (+0x131), registerGuid 0049bba0, Guid::Data::readableString 005a8440,
		// "Replicator: Requesting character for %s" 00824d40, Send(MEDIUM_PRIORITY, RELIABLE_ORDERED, 0).
		void Replicator::requestCharacter()
		{
			if (!peer)
				throw std::runtime_error("Attempting to send a Character request without a connection");

			Player* player = findTargetPlayer();
			if (!player)
				throw std::runtime_error("Attempting to send a Character request without a local Player");

			RakNet::BitStream bitStream;
			bitStream << (unsigned char)0x4c; // ID_REQUEST_CHARACTER

			serializeId(bitStream, player);

			if (NetworkSettings::singleton().printInstances)
			{
				// INFERRED: the target registers the guid (0049bba0) before copying it inline (+8 / +0xc).
				player->registerGuid();
				Guid::Data id;
				player->getGuid().extract(id);

				StandardOut::singleton()->print(MESSAGE_INFO, "Replicator: Requesting character for %s", id.readableString(4).c_str());
			}

			peer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, remotePlayerId, false);
		}

		// 004ab850 (static; template-instance caller: for_each over containerConnections +0x2c38)
		void Replicator::closeReplicationItem(const std::pair<const Instance* const, ReplicationData>& item)
		{
			item.second.connection0.disconnect();
			item.second.connection1.disconnect();
			if (item.second.removeOnClose)
				item.second.instance->setParent(NULL);
		}
	}
}

// Template members emitted by this unit: the containerConnections (+0x2c38) map, whose node destruction emits the
// implicit Replicator::ReplicationData destructor 004ab8c0 (two ~connection 00595370, then the shared_ptr release).
template class std::map<const RBX::Instance*, RBX::Network::Replicator::ReplicationData>;
