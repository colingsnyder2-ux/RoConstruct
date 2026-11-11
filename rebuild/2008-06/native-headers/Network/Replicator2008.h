#pragma once
// >>> native-status (generated) -- do not edit >>>
// Replicator2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src a2d95b40 | roc native-status --write
// 2008-06 native RBX::Network::Replicator and Replicator::ReplicatorStatsItem (inactive). A new, non-colliding
// header: the donor-path native-headers/Replicator.h (provisional donor layout) is neither used nor shadowed. Shape
// after the donor tools/rbxgs Client/Network/Replicator.h; every base, field and size below is read from the 2008-06
// binary (verified by tests/record_native_network_replicator2008.py).
//
// Replicator: PARTIAL DECLARATION. The bases and the members up to +0x2b90 are complete; the members from +0x2b90 to
// the end (sizeof 0x2d68, ClientProxy places its first member at +0x2d68) are NOT declared yet, so sizeof(Replicator)
// here is smaller than the original. Only code that does not depend on the Replicator size or on members past
// +0x2b90 may be built from this header (shared_count<Replicator*>, dynamic_cast<const Replicator*>, the
// ReplicatorStatsItem rows below); the constructor 004b9bd0 and destructor 004b96b0 stay open.
//   RTTI       vtable 008254fc .?AVReplicator@Network@RBX@@ (23 bases): DescribedNonCreatable<Replicator,
//              IdSerializer, sReplicator> (name mangled $1?sReplicator@23@3QBDB, a const char array in .rdata at
//              008244e4 "NetworkReplicator", defined in native-classes/ReplicatorBases.cpp) and PluginInterface at
//              mdisp 0x2b74 (vtable 00825450), directly after IdSerializer (0x2b74 bytes).
//   size       0x2d68: create<Replicator> 0049f500 mallocs 0x2d68; create<ClientProxy> 004a21c0 mallocs 0x2d78 and
//              ClientProxy's first member is at +0x2d68
//              (ClientProxy constructor 004a1ed0). The class holds a double (+0x2b78), so it is 8-aligned.
//   ctor       004b9bd0 (SystemAddress remotePlayerId, RakPeerInterface* peer; ret 0xc): DescribedNonCreatable
//              004b9ad0, PluginInterface() 0049ed30, then in declaration order:
//              +0x2b78 G3D::RealTime lastSendTime = G3D::System::time() (00508410, fstp qword),
//              +0x2b80 scoped_ptr<IPhysicsSender> (reset from NetworkSettings +0x134: 0 -> new(0x74) PhysicsSender
//              004ccb10, 1 -> new(0x18) RoundRobinPhysicsSender 004c99c0; old object deleted through slot 0),
//              +0x2b84 scoped_ptr<IPhysicsReceiver> (NetworkSettings +0x138: 0 -> new(8) DirectPhysicsReceiver,
//              1 -> new(0x3c) InterpolatingPhysicsReceiver 004b5e80),
//              +0x2b88 shared_ptr<ReplicatorStatsItem> statsItem (zeroed; the destructor releases the count at
//              +0x2b8c; 004b82d0 assigns it create<ReplicatorStatsItem>(shared_from(this), peer->GetStatistics(
//              remotePlayerId)) 004b7e50 and parents it to the "Network" stats item).
//   pending    (not declared; layout read from ctor 004b9bd0 / dtor 004b96b0, element types not all proven):
//              +0x2b90 std::map (const pointer key -> shared_ptr: destructor 004b16a0 is ICF-shared with
//              map<const SignalDescriptor*, shared_ptr<SignalInstance> >), +0x2bb0 / +0x2bf4 two 0x44-byte name
//              dictionaries (constructors 004b1570 / 004b1620: map + int bits +0x20 (004a8470 / 004a8580), vector
//              +0x24 (aux, first +0x30), int bits +0x3c (004b728c), +0x40 unread), +0x2c38 std::map<const Instance*,
//              0x2c-byte value: shared_ptr, two boost::signals::connection (~connection 00595370), 4 bytes>
//              (constructor 004b0b90, destructor 004b14c0, value destructor 004ab8c0), +0x2c58 std::vector (pointer
//              elements), +0x2c70 Players*, +0x2c74 std::list<shared_ptr<Item> > pendingItems (004aefe0 / 004b0a80),
//              +0x2c90 / +0x2cb0 std::set of pointers (004b9d30 / 0064b230), +0x2cd0 bool, +0x2cd4 / +0x2cd8
//              pointers, +0x2cdc std::deque<shared_ptr<Marker> > (_Tidy 004af1b0), +0x2cfc std::map (pointer ->
//              shared_ptr, destructor 004b16a0), +0x2d1c..+0x2d38 eight scoped_ptr<Profiling::ThreadProfiler>
//              ("Replication" .. "Write": new(0xc048), 005c43a0; parents set +0xc040), +0x2d3c..+0x2d48 four
//              scoped_ptr<Profiling::CodeProfiler> ("Bits Received" .. "Split Messages Sent", 005c43d0), +0x2d4c bool
//              (canSendItems 004aafc0), +0x2d4d bool (004aaf6f), +0x2d50 RakPeerInterface* peer (AttachPlugin slot
//              58 in the ctor, DetachPlugin slot 59 in the dtor), +0x2d54 SystemAddress remotePlayerId, +0x2d5c /
//              +0x2d60 two 4-byte counters (zeroed, not destroyed; 004b73e5, 004b8a18, 004b7d03), 4 bytes alignment.
//   vtable     slots after Instance's: 16 00565ff0, 17 findTargetPlayer 004ab9a0, 18 wantReplicate 004aaf90, 19 pure,
//              20 004ab960, 21 canSendItems 004aafc0; slot 12 onServiceProvider 004b87f0, slot 14 write 00416690;
//              PluginInterface slot 4 Update 004b1240, slot 5 OnReceive 004b8c20. Not declared here (no vtable of
//              Replicator is emitted from this header).
//
// ReplicatorStatsItem: complete.
//   RTTI       vtable 00824fbc .?AVReplicatorStatsItem@Replicator@Network@RBX@@ (22 bases) -> Stats::Item (no other
//              base). Slot 16 update 004b6530 (declared only: it reads Replicator +0x2d50 / +0x2d54).
//   size       0x180: Creatable<Instance>::create<ReplicatorStatsItem, shared_ptr<Replicator>, RakNetStatistics*>
//              004b7e50 mallocs 0x180 (8-aligned: Stats::Item holds a double).
//   ctor       004b62c0 (const shared_ptr<Replicator>&, const RakNetStatistics*; ret 8; declared only: it reads the
//              Replicator profilers +0x2d1c..+0x2d48): Item() 0045ebe0, +0x168 replicator (copy), +0x174 / +0x178
//              = 0, +0x170 statistics, then the child items +0x160 "Ping", +0x15c "Packet Loss", +0x164 "Instance
//              size (In)", +0x158 "Waiting Refs" (createChildItem 005c9c70).
//   dtor       004b6690 (implicit: no vtable pointer stores): releases replicator (+0x16c count), then ~Item
//              0045ba10; deleting destructor 004b6710 (free through Creatable<Instance>::operator delete). Not
//              built: without the (open) constructor no unit emits the vtable, the deleting destructor or the
//              implicit destructor (a user-declared destructor stores all ten vtable pointers: 200 bytes, rejected).
//   update     004b6530: ping (+0x160) from peer slots 0x94/0x8c/0x90, waitingRefs (+0x158) =
//              IdSerializer::waitItems.size() (Replicator +0x2b70), packetLoss (+0x15c) from statistics +0x5c / +0x78,
//              instanceSize (+0x164) = formatMem(instanceBits / (instanceCount * 8)).
#include "PluginInterface.h"
#include "RakNetTypes.h"
#include "Network/IdSerializer.h"
#include "Network/PhysicsReplication.h"
#include "stats/Stats.h"
#include <G3D/System.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>

class RakPeerInterface;
struct RakNetStatistics;

struct NativeNetworkReplicator2008Layout;

namespace RBX
{
	namespace Network
	{
		extern const char sReplicator[];

		class Replicator : public DescribedNonCreatable<Replicator, IdSerializer, sReplicator>, public PluginInterface
		{
			friend struct ::NativeNetworkReplicator2008Layout; // layout probe of tests/record_native_network_replicator2008.py

		public:
			class ReplicatorStatsItem;

		private:
			G3D::RealTime lastSendTime;                                             // +0x2b78
			boost::scoped_ptr<IPhysicsSender> physicsSender;                        // +0x2b80
			boost::scoped_ptr<IPhysicsReceiver> physicsReceiver;                    // +0x2b84
			boost::shared_ptr<ReplicatorStatsItem> statsItem;                       // +0x2b88
			// +0x2b90 .. +0x2d68: pending (see the header comment); sizeof is partial.

		public:
			Replicator(SystemAddress remotePlayerId, RakPeerInterface* peer);      // 004b9bd0 (open)
			virtual ~Replicator();                                                  // 004b96b0 (open)
		};

		class Replicator::ReplicatorStatsItem : public Stats::Item
		{
			friend struct ::NativeNetworkReplicator2008Layout;
		private:
			Stats::Item* waitingRefs;                                               // +0x158 "Waiting Refs"
			Stats::Item* packetLoss;                                                // +0x15c "Packet Loss"
			Stats::Item* ping;                                                      // +0x160 "Ping"
			Stats::Item* instanceSize;                                              // +0x164 "Instance size (In)"
			const boost::shared_ptr<Replicator> replicator;                         // +0x168
			const RakNetStatistics* statistics;                                     // +0x170
		public:
			size_t instanceCount;                                                   // +0x174
			size_t instanceBits;                                                    // +0x178

		public:
			ReplicatorStatsItem(const boost::shared_ptr<Replicator>& replicator, const RakNetStatistics* statistics); // 004b62c0 (open)
			virtual void update();                                                  // 004b6530 (open)
		};
	}
}
