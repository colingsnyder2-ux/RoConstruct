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
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source /I{headers}/../../../../../../tmp/claude-0/-home-user/28a5ad2c-f9ca-5f88-a52d-b9a089ed390b/scratchpad/nc/b43-nr03/hdr/ps
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

// InterpolatingPhysicsReceiver::step 004c8fa0 and the PartItem helpers it reaches (004c6dc0 / 004c6ed0 / 004c6f70, all
// registry placeholders between the Association rows 004c6d30.. and PartItem::PartItem 004c7a10 of this unit).
// BLOCKED (guard below): Network/PhysicsSenders2008.h (not this batch's file) does not declare the three PartItem
// members; the proposal adds `bool step(unsigned int time); void setPosition(const History& history); void
// interpolate(const History& from, const History& to, float alpha);` to InterpolatingPhysicsReceiver::PartItem and
// defines INTERPOLATING_RECEIVER_HEADER_DECLARES_STEP_HELPERS (measured against a scratch copy, batch 43 nr03).
#ifdef INTERPOLATING_RECEIVER_HEADER_DECLARES_STEP_HELPERS
#include "v8world/MotorJoint.h" // MotorJoint::setCurrentAngle 005e5da0
#include <G3D/g3dmath.h>

namespace RBX
{
	namespace Network
	{
		// 004c6dc0 (ret 0xc): setPhysics 005997f0 of from.frame.lerp(to.frame, alpha) 00518a50; when both samples
		// carry as many motor angles as the assembly (getAssembly 005e7570, numMotors 005e62d0), each motor
		// (getMotor 005e6400) gets setCurrentAngle 005e5da0 of the lerped angle (to[i] bounds-checked first).
		void InterpolatingPhysicsReceiver::PartItem::interpolate(const History& from, const History& to, float alpha)
		{
			part->setPhysics(from.frame.lerp(to.frame, alpha));
			if (to.motorAngles.size() == from.motorAngles.size())
			{
				Assembly* assembly = part->getPrimitive()->getAssembly();
				if (assembly && assembly->numMotors() == from.motorAngles.size())
				{
					for (unsigned int i = 0; i < from.motorAngles.size(); i++)
						assembly->getMotor(i)->setCurrentAngle(G3D::lerp(from.motorAngles[i], to.motorAngles[i], alpha));
				}
			}
		}

		// 004c6ed0 (ret 4): setPhysics 005997f0 of the sample frame, then its motor angles as in interpolate.
		void InterpolatingPhysicsReceiver::PartItem::setPosition(const History& history)
		{
			part->setPhysics(history.frame);
			Assembly* assembly = part->getPrimitive()->getAssembly();
			if (assembly && assembly->numMotors() == history.motorAngles.size())
			{
				for (unsigned int i = 0; i < history.motorAngles.size(); i++)
					assembly->getMotor(i)->setCurrentAngle(history.motorAngles[i]);
			}
		}

		// 004c6f70 (ret 4): false (the receiver drops the item) for a dragged part (getDragging 00598d10) or one
		// without an assembly; otherwise plays the newest sample not later than time - interval (unsigned to double
		// through the 2^32 corrections 00811240 / 00819778), lerping toward the next newer one.
		bool InterpolatingPhysicsReceiver::PartItem::step(unsigned int time)
		{
			if (part->getDragging())
				return false;
			if (!part->getPrimitive()->getAssembly())
				return false;
			if (count == 0)
				return true;
			if (count == 1)
			{
				setPosition(history[head]);
				return true;
			}

			double t = time - interval;
			const History* newer = NULL;
			for (int i = 0; i < count; i++)
			{
				const History& item = history[(head + 8 - i) % 8];
				if (!(item.timestamp > t))
				{
					if (newer)
					{
						interpolate(item, *newer, (float)(t - item.timestamp) / (unsigned int)(newer->timestamp - item.timestamp));
						return true;
					}
					newer = &item;
					break;
				}
				newer = &item;
			}
			setPosition(*newer);
			return true;
		}

		// 004c8fa0 (vtable slot 1, ret 4): walks the hashed index, erasing (inline hashed unlink, ordered
		// rebalance_for_erase 004c69e0, ~PartItem 004af950) every item whose step returns false.
		void InterpolatingPhysicsReceiver::step(unsigned int time)
		{
			PartItems::nth_index<0>::type& index = items.get<0>();
			PartItems::nth_index<0>::type::iterator it = index.begin();
			PartItems::nth_index<0>::type::iterator end = index.end();
			while (it != end)
			{
				if (const_cast<PartItem&>(*it).step(time))
					++it;
				else
					it = index.erase(it);
			}
		}
	}
}
#endif
