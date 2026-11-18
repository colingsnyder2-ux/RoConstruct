// 2008-06 native RBX::Network::InterpolatingPhysicsReceiver recovery unit.
// The class and its declared members come from the authentic native header
// Network/PhysicsSenders2008.h (RTTI / vftable 00824ee4 / link order recovered by the owner).
//
// 004b6290 (33 bytes) is the implicitly generated scalar deleting destructor: ~PartItems at +8
// (004b58f0) followed by operator delete (006a067a) when the flags byte has bit 0.
// It is emitted here by deleting an instance of the real class; no stand-in type is defined.
//
// 004c9120 (1641 bytes, receivePacket) is NOT yet recovered. Blocker recorded in the lane receipt:
// the analog's statement order calls Replicator::deserializeInstanceRef, Player::character (+0x170),
// Settings (+0x130), StandardOut::print, Guid::Data::readableString, PartInstance::primitive/getAssembly
// and PartItem::receive (004c8150). PartItem::receive is undeclared in the leased header; the remaining
// APIs live in headers owned by other leases (Replicator.h, Network/Player.h, util/Settings*, util/StandardOut),
// so they cannot be declared here without cross-lease header edits. Parked pending owner header proposals.
//
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "Network/PhysicsSenders2008.h"

namespace RBX
{
	namespace Network
	{
		// Defining the real constructor emits the class vftable (00824ee4); its slot 0 is the
		// implicit scalar deleting destructor at 004b6290.
		InterpolatingPhysicsReceiver::InterpolatingPhysicsReceiver(Replicator* replicator)
			: replicator(replicator)
		{
		}
	}
}
