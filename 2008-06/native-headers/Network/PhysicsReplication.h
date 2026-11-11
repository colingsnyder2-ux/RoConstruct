#pragma once
// >>> native-status (generated) -- do not edit >>>
// PhysicsReplication | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src c8318741 | roc native-status --write
// 2008-06 native RBX::Network physics replication interfaces and their two simple implementations (inactive).
// The donor tree has none of these classes (its Replicator.cpp sends physics itself); names follow the 2008 RTTI.
// This header has its own name, so no donor header is shadowed. Every base, field, slot and size below is read from
// the 2008-06 binary.
//
// Owner: Replicator (not recovered natively) constructor 004b9bd0 creates one sender and one receiver and keeps them in
// scoped_ptr-like slots at Replicator +0x2b80 (sender) / +0x2b84 (receiver); replacing one deletes the old object
// through vtable slot 0 with flag 1 (004ba0cc / 004ba142).
//   sender:   settings +0x134 == 0 -> new(0x74) PhysicsSender(this) 004ccb10; == 1 -> new(0x18)
//             RoundRobinPhysicsSender(this) 004c99c0.
//   receiver: settings +0x138 == 0 -> new(8) DirectPhysicsReceiver (constructor inlined at 004ba117: vtable 008247d0,
//             +4 = the Replicator); == 1 -> new(0x3c) InterpolatingPhysicsReceiver(this) 004b5e80.
//
// Interfaces (no vtable of their own exists in the binary: no complete-object locator names IPhysicsSender or
// IPhysicsReceiver, and no constructor or destructor stores one, hence __declspec(novtable)).
//   RTTI     every implementation's hierarchy is [Impl (2 contained), I* (1 contained), boost::noncopyable_::noncopyable
//            (mdisp 4, attributes 0x4d = private, non-polymorphic)], so the interface derives privately from
//            noncopyable and the implementation derives from the interface only.
//   IPhysicsSender slots (vtables 00826928 PhysicsSender, 00826760 RoundRobinPhysicsSender):
//            0 scalar deleting destructor; 1 no arguments, `ret` (RoundRobin 0047d410 is empty; PhysicsSender
//            004cd920); 2 one int argument, returns int: Replicator 004aba07 passes an int and keeps eax
//            (RoundRobin 004cd420 `ret 4`, PhysicsSender 004cce00 `ret 4`, compares the argument with jge).
//   IPhysicsReceiver slots (vtables 008247d0 DirectPhysicsReceiver, 00824ee4 InterpolatingPhysicsReceiver):
//            0 scalar deleting destructor; 1 one unsigned 4-byte argument (Interpolating 004c8fa0 forwards it to
//            004c6f70, which converts it with fild + 2^32 correction: unsigned; Direct 0070bdf0 is `ret 4`);
//            2 (RakNet::BitStream&, unsigned): Replicator 004abc00 calls it with the packet BitStream and the
//            timestamp it read (004a62d0) after packet id 0x50; Direct 004c83b0 / Interpolating 004c9120 `ret 8`.
//   Slot names are analog names (no symbol evidence).
//
// DirectPhysicsReceiver
//   size     8: Replicator 004ba117 allocates 8 and stores vtable 008247d0 and +4 = Replicator*.
//   slots    0 ??_G 004ab5b0 is the identical-code-folded trivial scalar deleting destructor (no members to destroy);
//            1 0070bdf0 `ret 4`; 2 004c83b0 (1890 bytes: needs the native Replicator / IdSerializer API; open).
//
// RoundRobinPhysicsSender
//   size     0x18: Replicator 004ba073 allocates 0x18 before the constructor 004c99c0.
//   ctor     004c99c0: +4 = replicator argument, vtable 00826760, +8 = 0 (EH state 0 from here: the tracker is the only
//            member with a destructor), then +0x10 = G3D::System::time() (inline; calls getLocalTime 00508410, fstp
//            qword: a double, so +0xc is the alignment gap before it).
//   dtor     ??_G 004ca010: `lea ecx, [esi+8]; call 005e5320` and delete. 005e5320 is the tracker cleanup: when its
//            single pointer is set it removes `this` from the 4-byte-pointer vector at pointer+4 (005e5200) and clears
//            the pointer: the donor v8world/Mechanism.h MechanismTracker shape (Mechanism* mechanism; inline
//            ~MechanismTracker() { stopTracking(); }). 004c99b0 `jmp 005e5320` is that inline destructor's
//            out-of-line copy (the constructor's unwind target).
//   slots    0 ??_G 004ca010; 1 0047d410 empty; 2 004cd420 (225 bytes: World::getSimJobStage 005e93b0 and an
//            unidentified 0x13c-byte local type 004cbd40/004c9a70; open).
//
// Not declared here (layouts known, member types not yet derived):
//   PhysicsSender 0x74 (ctor 004ccb10, dtor 004ccb90, ??_G 004ccde0): +4 a boost::multi_index_container (0x34 bytes;
//     constructor 004cc400 news a 0x78-byte header node, hashed index bucket array at +0xc, node_count +0x30,
//     destructor 004ccab0) whose 0x50-byte value starts with shared_ptr<PartInstance>, double, CoordinateFrame
//     (copy 004c9d90); +0x38 an uninitialized index iterator; +0x3c Replicator*; +0x40 int = 0; +0x44 shared_ptr
//     (set from shared_from 00618a40 in 004cd920); +0x4c and +0x60 boost::signals::scoped_connection (0x14 each,
//     destructor 005954b0).
//   InterpolatingPhysicsReceiver 0x3c (ctor 004b5e80, ??_G 004b6290): +4 Replicator*; +8 a multi_index_container
//     (0x34 bytes; constructor 004b0ae0 news a 0x298-byte header node, destructor 004b58f0).
#include <boost/noncopyable.hpp>
#include <G3D/System.h>
#include "v8world/Mechanism.h"

struct NativeNetworkPhysicsLayout;

namespace RakNet
{
	class BitStream;
}

namespace RBX
{
	namespace Network
	{
		class Replicator;

		class __declspec(novtable) IPhysicsSender : boost::noncopyable
		{
		public:
			virtual ~IPhysicsSender() {}
			virtual void step() = 0;                                              // slot 1
			virtual int sendPackets(int maxPackets) = 0;                          // slot 2
		};

		class __declspec(novtable) IPhysicsReceiver : boost::noncopyable
		{
		public:
			virtual ~IPhysicsReceiver() {}
			virtual void step(unsigned int time) = 0;                             // slot 1
			virtual void receivePacket(RakNet::BitStream& bitStream, unsigned int timeStamp) = 0; // slot 2
		};

		class DirectPhysicsReceiver : public IPhysicsReceiver
		{
			friend struct ::NativeNetworkPhysicsLayout; // tests/NativeNetworkPhysicsLayout.cpp offset asserts
		private:
			Replicator* replicator;                                               // +0x4

		public:
			DirectPhysicsReceiver(Replicator* replicator)                         // inlined in Replicator 004ba117
				: replicator(replicator)
			{
			}
			/*override*/ virtual void step(unsigned int time);                    // 0070bdf0 (empty)
			/*override*/ virtual void receivePacket(RakNet::BitStream& bitStream, unsigned int timeStamp); // 004c83b0
		};

		class RoundRobinPhysicsSender : public IPhysicsSender
		{
			friend struct ::NativeNetworkPhysicsLayout; // tests/NativeNetworkPhysicsLayout.cpp offset asserts
		private:
			Replicator* replicator;                                               // +0x4
			MechanismTracker tracker;                                             // +0x8
			G3D::RealTime lastSendTime;                                           // +0x10

		public:
			RoundRobinPhysicsSender(Replicator* replicator);                      // 004c99c0
			/*override*/ virtual void step();                                     // 0047d410 (empty)
			/*override*/ virtual int sendPackets(int maxPackets);                 // 004cd420
		};
	}
}
