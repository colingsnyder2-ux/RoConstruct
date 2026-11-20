// 2008-06 native RBX::Network::InterpolatingPhysicsReceiver recovery unit.
// The class and its declared members come from the authentic native header
// Network/PhysicsSenders2008.h (RTTI / vftable 00824ee4 / link order recovered by the owner).
//
// 004b6290 (33 bytes) is the implicitly generated scalar deleting destructor: ~PartItems at +8
// (004b58f0) followed by operator delete (006a067a) when the flags byte has bit 0.
// It is emitted here by deleting an instance of the real class; no stand-in type is defined.
//
<<<<<<< HEAD
// 004c8150 (602 bytes, PartItem::receive) is written below behind NATIVE_PHYSICS_RECEIVER_ITEM_PENDING. With the two
// header declarations named at the guard it compiles byte-identical to 004c8150 (relocations masked; batch 24 trial
// with shadow copies of the headers). Remaining blocker: the declarations live in leased headers.
=======
// 004c8150 (602 bytes, PartItem::receive) is written below (batch 24 proved it byte-identical with these declarations).
>>>>>>> mew/claude/optimistic-shannon-0xccuy
//
// 004c9120 (1641 bytes, receivePacket) is NOT yet recovered. Blocker recorded in the lane receipt:
// the analog's statement order calls Replicator::deserializeInstanceRef, Player::character (+0x170),
// Settings (+0x130), StandardOut::print, Guid::Data::readableString, PartInstance::primitive/getAssembly
// and PartItem::receive (004c8150). PartItem::receive is undeclared in the leased header; the remaining
// APIs live in headers owned by other leases (Replicator.h, Network/Player.h, util/Settings*, util/StandardOut),
// so they cannot be declared here without cross-lease header edits. Parked pending owner header proposals.
//
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
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

<<<<<<< HEAD
#ifdef NATIVE_PHYSICS_RECEIVER_ITEM_PENDING
// Blocked on two header declarations (owner of Network/PhysicsSenders2008.h and Network/PhysicsReplication.h):
//   PhysicsSenders2008.h, struct InterpolatingPhysicsReceiver::PartItem:
//     void receive(RakNet::BitStream& bitStream, unsigned int timestamp, ModelInstance* character); // 004c8150
//   PhysicsReplication.h, class IPhysicsSender (plus #include <G3D/Vector3.h>):
//     static void readPosition(RakNet::BitStream& bitStream, G3D::Vector3& position);             // 004ca5c0
//     (004ca5c0's own error string 008268e8 reads "IPhysicsSender::readPosition failed read").
// Enabling it also needs "/I{headers}/part-embedded /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source"
// appended to the native-flags line.
=======
// PartItem::receive 004c8150 uses the declarations in Network/PhysicsSenders2008.h (PartItem::receive) and
// Network/PhysicsReplication.h (IPhysicsSender::readPosition 004ca5c0, error string 008268e8).
>>>>>>> mew/claude/optimistic-shannon-0xccuy
#include "Network/NetworkSettings.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "util/standardout.h"
#include "util/Math.h"
#include "util/Quaternion.h"
#include <BitStream.h>
#include <stdexcept>

namespace RBX
{
	namespace Network
	{
		// 004c8150 (602 bytes, thiscall ret 0xc; only caller receivePacket 004c9120): pushes one received sample
		// into the 8-entry history ring and updates the smoothed interval. Strings 0082661c / 00826600, constants
		// 008265f0 (0.8) / 008265f8 (0.2).
		void InterpolatingPhysicsReceiver::PartItem::receive(RakNet::BitStream& bitStream, unsigned int timestamp, ModelInstance* character)
		{
			head = (head + 9) % 8;
			if (count < 8)
				count++;

			History& item = history[head];
			item.timestamp = timestamp;

			IPhysicsSender::readPosition(bitStream, item.frame.translation);

			Quaternion q;
			if (!bitStream.ReadNormQuat(q.w, q.x, q.y, q.z))
				throw std::runtime_error("Failed to read Quaternion");
			q.toRotationMatrix(item.frame.rotation);

			unsigned char numMotors;
			bitStream >> numMotors;
			if (numMotors > 50 && NetworkSettings::singleton().printPhysicsErrors)
				StandardOut::singleton()->print(MESSAGE_WARNING, "Physics-in has %d motors", numMotors);

			int n = numMotors;
			item.motorAngles.resize(n, 0.0f);
			for (int i = 0; i < n; i++)
			{
				unsigned char value;
				bitStream >> value;
				float angle = Math::rotationFromByte(value);
				item.motorAngles[i] = angle;
			}

			// The donor v8tree/Instance.h defines isDescendentOf inline (first parent compare, then the recursive call);
			// 004c8300..004c831b expands that one level before calling the out-of-line copy 00422ae0. The native
			// Instance.h declares it out of line only, so the first level is spelled out here.
			Instance* parent;
			if (character && part && (character == (parent = part->getParent()) || (parent && parent->isDescendentOf(character))))
			{
				interval = 0.0;
			}
			else if (count >= 2)
			{
				const History& previous = history[(head + 7) % 8];
				double delta = (unsigned int)(item.timestamp - previous.timestamp);
				if (delta > interval)
					interval = interval * 0.2 + delta * 0.8;
				else
					interval = interval * 0.8 + delta * 0.2;
			}
		}
	}
}
<<<<<<< HEAD
#endif
=======
>>>>>>> mew/claude/optimistic-shannon-0xccuy
