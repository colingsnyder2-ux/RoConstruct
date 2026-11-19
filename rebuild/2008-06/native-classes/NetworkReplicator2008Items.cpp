// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Replicator item/sender rows (inactive): Replicator::ItemSender::~ItemSender 004aba60,
// Replicator::MarkerItem::write 004ae9a0 and Replicator::remoteDeleteOnDisconnect 004ab960. Shapes after the donor
// tools/rbxgs Client/Network/Replicator.cpp; declarations in native-headers/Network/Replicator2008.h.
#include "Network/Replicator2008.h"
#include "Network/NetworkSettings.h"
#include "Network/Players.h"
#include "util/standardout.h"
#include "RakPeerInterface.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "v8datamodel/ModelInstance.h"
#include "BitStream.h"

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

		// 004ab960 (virtual slot 20). NEAR MISS: same 59 bytes and instructions as the target; the target lays the
		// `mov al,1; ret 4` block first (after the inlined ancestor test) where this compile puts it last (jne vs je).
		// Rejected: raw member comparison, locals, single `return a || b` (63 bytes).
		bool Replicator::remoteDeleteOnDisconnect(const Instance* instance) const
		{
			// INFERRED: the target inlines the first level of Instance::isDescendentOf (004ab960 compares the +0x104
			// parent with players, then calls 00422ae0 on the parent); the header declares it out of line only
			// (see header-fix-proposals.json).
			const Instance* ancestor = players;
			Instance* parent = instance->parent;
			if (ancestor == parent || (parent && parent->isDescendentOf(ancestor)))
				return true;

			if (instance == Players::findLocalCharacter(instance))
				return true;

			return false;
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
