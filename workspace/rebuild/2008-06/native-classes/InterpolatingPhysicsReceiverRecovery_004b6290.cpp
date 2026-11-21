// 2008-06 native RBX::Network::InterpolatingPhysicsReceiver recovery unit.
// The class and its declared members come from the authentic native header
// Network/PhysicsSenders2008.h (RTTI / vftable 00824ee4 / link order recovered by the owner).
//
// 004b6290 (33 bytes) is the implicitly generated scalar deleting destructor: ~PartItems at +8
// (004b58f0) followed by operator delete (006a067a) when the flags byte has bit 0.
// It is emitted here by deleting an instance of the real class; no stand-in type is defined.
//
// 004c8150 (602 bytes, PartItem::receive) is written below (batch 24 proved it byte-identical with these declarations).
//
// 004c9120 (1641 bytes, receivePacket) is NOT yet recovered. Blocker recorded in the lane receipt:
// the analog's statement order calls Replicator::deserializeInstanceRef, Player::character (+0x170),
// Settings (+0x130), StandardOut::print, Guid::Data::readableString, PartInstance::primitive/getAssembly
// and PartItem::receive (004c8150). PartItem::receive is undeclared in the leased header; the remaining
// APIs live in headers owned by other leases (Replicator.h, Network/Player.h, util/Settings*, util/StandardOut),
// so they cannot be declared here without cross-lease header edits. Parked pending owner header proposals.
// Batch 29 note: deserializeInstanceRef 004a8b60 is now declared in Network/IdSerializer.h. Remaining shape read from
// the binary: character = findTargetPlayer() (slot 17) ? player+0x170 : NULL; loop deserializeInstanceRef; the part
// shared_ptr from instance+0xe4 (004c7530); "Physics-in" error prints through StandardOut 005693a0 with strings
// 008266e8 / 008266c0 / 00826694 / 00826708 (NetworkSettings 0049e890 printPhysicsErrors gates, Guid readable
// strings 004a98b0); PartInstance 005995f0, Primitive::getAssembly 005e7570, Clump::getAnchored 005e60e0, then the
// items multi_index hashed find 004c72b0 / insert 004c8da0 of PartItem(part) 004c7a10, PartItem::receive 004c8150 and
// the ordered-index modify 004c8ef0. Not attempted in batch 29 (1641 B; no analog).
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

// PartItem::receive 004c8150 uses the declarations in Network/PhysicsSenders2008.h (PartItem::receive) and
// Network/PhysicsReplication.h (IPhysicsSender::readPosition 004ca5c0, error string 008268e8).
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

// receivePacket 004c9120 additionally reaches the Replicator (findTargetPlayer slot 17, deserializeInstanceRef
// 004a8b60), Player::getCharacter (+0x170) and the multi_index modify through boost::bind.
#include "Network/Replicator2008.h"
#include "Network/Player.h"
#include "util/Object.h"
#include "v8world/Assembly.h" // Assembly::getAnchored (the 2008 Clump::getAnchored 005e60e0)
#include <boost/bind.hpp>

namespace RBX
{
	namespace Network
	{
		// 004c9120 (1641 bytes, vtable slot of IPhysicsReceiver::receivePacket, thiscall ret 8). Identity: the only
		// caller of PartItem(part) 004c7a10 and PartItem::receive 004c8150; strings "Physics-in of unidentified %s"
		// 008266e8 (MESSAGE_WARNING, `push 2`), "Physics-in of part not in workspace %s" 008266c0, "Physics-in of primitive with
		// no assembly %s" 00826694, "Physics-in of anchored assembly %s" 00826708 (MESSAGE_INFO, `push 1`), all gated by
		// NetworkSettings printPhysicsErrors (+0x130). Flow from the binary: character = findTargetPlayer() (slot 17)
		// ? +0x170 : NULL; then until a NULL instance: deserializeInstanceRef 004a8b60,
		// shared_from_polymorphic_downcast<PartInstance> 004c7530 (Instance enable_shared_from_this base +0xe4; a static cast through 005a1680, no __RTDynamicCast, unlike the dynamic-cast twin 005d42f0), the three
		// validity checks (PartInstance::nonNullInWorkspace 005995f0, Primitive::getAssembly 005e7570 on the part
		// +0x228, Clump::getAnchored 005e60e0) each clearing the part, then the hashed find 004c72b0: a known part is
		// updated through final_modify_ 004c8da0 with bind(&PartItem::receive, _1, ref(bitStream), timeStamp,
		// character) (16-byte bind_t), otherwise a fresh PartItem reads the sample and is inserted (final_insert_
		// 004c8ef0) only when the part is valid; ~PartItem 004af950.
		void InterpolatingPhysicsReceiver::receivePacket(RakNet::BitStream& bitStream, unsigned int timeStamp)
		{
			PartItems::nth_index<0>::type& index = items.get<0>();

			Player* player = replicator->findTargetPlayer();
			ModelInstance* character = player ? player->getCharacter() : NULL;

			while (true)
			{
				boost::shared_ptr<PartInstance> part;

				Instance* instance;
				Guid::Data id;
				if (replicator->deserializeInstanceRef(bitStream, instance, id))
				{
					if (!instance)
						return;
					part = shared_from_polymorphic_downcast<PartInstance>(instance);
				}
				else if (NetworkSettings::singleton().printPhysicsErrors)
				{
					StandardOut::singleton()->print(MESSAGE_WARNING, "Physics-in of unidentified %s", id.readableString(4).c_str());
				}

				if (part)
				{
					if (!PartInstance::nonNullInWorkspace(part))
					{
						if (NetworkSettings::singleton().printPhysicsErrors)
							StandardOut::singleton()->print(MESSAGE_INFO, "Physics-in of part not in workspace %s", id.readableString(4).c_str());
						part.reset();
					}
					else if (!part->getPrimitive()->getAssembly())
					{
						if (NetworkSettings::singleton().printPhysicsErrors)
							StandardOut::singleton()->print(MESSAGE_INFO, "Physics-in of primitive with no assembly %s", id.readableString(4).c_str());
						part.reset();
					}
					else if (part->getPrimitive()->getAssembly()->getAnchored())
					{
						if (NetworkSettings::singleton().printPhysicsErrors)
							StandardOut::singleton()->print(MESSAGE_INFO, "Physics-in of anchored assembly %s", id.readableString(4).c_str());
						part.reset();
					}
				}

				PartItems::nth_index<0>::type::iterator it = index.find(part);
				if (it != index.end())
				{
					index.modify(it, boost::bind(&PartItem::receive, _1, boost::ref(bitStream), timeStamp, character));
				}
				else
				{
					PartItem item(part);
					item.receive(bitStream, timeStamp, character);
					if (part)
						index.insert(item);
				}
			}
		}
	}
}
