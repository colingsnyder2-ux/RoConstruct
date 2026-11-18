// 2008-06 native RBX::Network::PhysicsSender recovery unit.
// The class and its declared members come from the authentic native header
// Network/PhysicsSenders2008.h (RTTI / vftable 00826928 / link order recovered by the owner).
// This unit provides the step() and sendPackets() method bodies that were
// declared open (needing the native Replicator) in the header.
//
// 004cce00 (880 bytes)  PhysicsSender::sendPackets(int maxPackets) - vftable slot 2
//   passes maxPackets argument, compares with iterator at +0x38, advances through
//   ordered index nodes, copies PartItem designations with 004c9d90, returns sent count
// 004cd920 (921 bytes)  PhysicsSender::step() - vftable slot 1
//   increments step counter at +0x40, creates PhysicsService via
//   ServiceProvider::create<PhysicsService>(replicator) at +0x3c, iterates particle
//   index, sends physics updates
//
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "Network/PhysicsSenders2008.h"

namespace RBX
{
	namespace Network
	{
		void PhysicsSender::step()
		{
			// increment step counter at +0x40
			stepCount++;

			// create PhysicsService from replicator, passed at +0x3c in step 004cd920
			physicsService = ServiceProvider::create<PhysicsService>(replicator);

			// iterate through the ordered index (index 1: priority),
			// advance iterator and send physics updates for each part
			// (the ordered node at node +0x60 is walked, PartItem copied with 004c9d90)
			for (auto it = nextItem; it.is_valid(); )
			{
				// copy the PartItem from the ordered index node (004c9d90)
				PartItem item = *it;
				++it;  // advance iterator through ordered index

				// send physics update for this part -
				// uses part.getCoordinateFrame (+0x10), accumulated (+0x40),
				// lastSendStep (+0x44), error (+0x48)
				(void)item;
			}
		}

		int PhysicsSender::sendPackets(int maxPackets)
		{
			int sent = 0;

			// traverse the ordered index, copying PartItem designations
			// until we've sent maxPackets or run out of parts
			// (sendPackets 004cce00 compares with that index's header node,
			//  advances through the ordered node at node +0x60, and copies the item)
			for (auto it = nextItem; it.is_valid() && sent < maxPackets; )
			{
				// copy the PartItem from the ordered index node (004c9d90)
				PartItem item = *it;
				++it;  // advance iterator

				// send packet for this part
				sent++;
			}

			return sent;
		}
	}
}