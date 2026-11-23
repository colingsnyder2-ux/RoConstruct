#pragma once
// 2008-06 native RBX::Network::Replicator and Replicator::ReplicatorStatsItem (inactive). A new, non-colliding
// header: the donor-path native-headers/Replicator.h (provisional donor layout) is neither used nor shadowed. Shape
// after the donor tools/rbxgs Client/Network/Replicator.h; every base, field and size below is read from the 2008-06
// binary (verified by tests/record_native_network_replicator2008.py).
//
// Replicator: members declared through sizeof 0x2d68 (the +0x2b90..+0x2d68 block below follows the donor member order;
// element types and names that the binary does not prove are marked INFERRED). Virtual slots 16-21 are declared (slot
// 16 with an INFERRED name). The constructor 004b9bd0 and destructor 004b96b0 (ReplicatorRecovery_004b96b0.cpp) compile
// byte-identical; both stay non-exact only because MSVC gives the undecorated ??_7Replicator@Network@RBX@@6B@ to the
// PluginInterface vtable 00825450 while the registry's rtti-primary-vtable row binds it to 008254fc (the same blocker
// as the Server::ClientProxy constructor / destructor).
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
//   members    (layout read from ctor 004b9bd0 / dtor 004b96b0, element types not all proven):
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
//   vtable     008254fc, 22 slots; after Instance's 16: 16 00565ff0 (bool (const Instance*): ICF-shared `mov al,1;
//              ret 4`; name not derived, no donor counterpart; ClientProxy overrides it with 004a3290, the Server
//              script-name set lookup), 17 findTargetPlayer 004ab9a0, 18 wantReplicate 004aaf90, 19 onSentMarker(long)
//              0070bdf0 (an empty `ret 4` ICF-shared with Instance's empty virtuals, not a pure call: donor order
//              findTargetPlayer, wantReplicate, onSentMarker, remoteDeleteOnDisconnect, canSendItems), 20 004ab960
//              (donor remoteDeleteOnDisconnect position; reads +0x2c70 Players*), 21 canSendItems 004aafc0 (reads
//              +0x2d4c); ClientProxy vtable 00823474 keeps 18 and 20 and overrides 16, 17, 19, 21. Slot 12
//              onServiceProvider 004b87f0, slot 14 write 00416690; PluginInterface (vtable 00825450) slot 4 Update
//              004b1240, slot 5 OnReceive 004b8c20. Not declared here: slot 16 has no name evidence (declaring 17-21
//              without it would shift every slot) and no unit emits the Replicator vtable before the constructor
//              004b9bd0 / destructor 004b96b0 exist, so an inline wantReplicate would land in no object.
//
// ReplicatorStatsItem: complete.
//   RTTI       vtable 00824fbc .?AVReplicatorStatsItem@Replicator@Network@RBX@@ (22 bases) -> Stats::Item (no other
//              base). Slot 16 update 004b6530 (body in NetworkReplicator2008StatsItem.cpp).
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
#include "BitStream.h"
#include "RakNetTypes.h"
#include "Network/IdSerializer.h"
#include "Network/PhysicsReplication.h"
// NATIVE_REPLICATOR_NO_STATS_ITEM (opt-in, defined by a unit before including this header): leaves out stats/Stats.h
// and the ReplicatorStatsItem definition (the Replicator itself only holds a shared_ptr to the nested class), for
// units that also need v8datamodel/Workspace.h, whose v8datamodel/Stats.h redefines RBX::Stats::Item
// (NetworkPhysics.cpp: RoundRobinPhysicsSender::sendPackets 004cd420 reads Workspace::getWorld).
#ifndef NATIVE_REPLICATOR_NO_STATS_ITEM
#include "stats/Stats.h"
#endif
#include <G3D/System.h>
#include <boost/scoped_ptr.hpp>
#include <boost/signals/connection.hpp>
#include <boost/shared_ptr.hpp>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

class RakPeerInterface;
struct RakNetStatistics;
class XmlElement;

struct NativeNetworkReplicator2008Layout;

namespace RBX
{
	class Name;
	namespace Reflection
	{
		class ClassDescriptor;
		class PropertyDescriptor;
		class Property;
		class ConstProperty;
	}
	namespace Profiling
	{
		class CodeProfiler;
		class CountProfiler;
	}
	namespace Network
	{
		class Players;
		class Player;
		class Marker;

		// INFERRED: 0x44-byte descriptor-name dictionaries at Replicator +0x2bb0 (classes, constructor 004b1570) and
		// +0x2bf4 (properties, constructor 004b1620). Each constructor first calls 004a8470 / 004a8580, which fill a
		// map at +0x0 with descriptor -> index (map size) for every registered descriptor (map operator[] 005644a0)
		// and store the index bit count at +0x20, then constructs a vector at +0x24 (aux, _Myfirst +0x30). The
		// Replicator destructor frees the vector, then the map (00553d80); +0x3c is a bit count (004b728c) and +0x40
		// is never read in the cited bodies. Class name not derived.
		template<class Descriptor>
		class DescriptorDictionary
		{
			std::map<const Descriptor*, int> dictionary;                            // +0x00
			int bits;                                                               // +0x20
			std::vector<const Descriptor*> descriptors;                             // +0x24
			int receiveBits;                                                        // +0x3c INFERRED name
			int reserved;                                                           // +0x40 INFERRED: required by the 0x44 stride
		public:
			// 004b1570 (classNames) / 004b1620 (propNames): fill the dictionary from every registered descriptor (body not
			// recovered; the Replicator constructor 004b9bd0 calls them).
			DescriptorDictionary();
			// 004aeba0 (thiscall (BitStream&, const Descriptor&), ret 8; ChangePropertyItem::write 004b6d10 calls it on
			// propNames +0x2bf4 with the property descriptor). INFERRED name after the donor SharedStringDictionary::send.
			void send(RakNet::BitStream& bitStream, const Descriptor& descriptor);
			// INFERRED: inline receive (no standalone body in the client; readChangedProperty 004b7a30 expands it:
			// ReadBits 004a5210 of receiveBits (+0x3c) into a zeroed index, then the checked descriptors[index]).
			void receive(RakNet::BitStream& bitStream, const Descriptor*& descriptor)
			{
				unsigned int index = 0;
				bitStream.ReadBits((unsigned char*)&index, receiveBits, true);
				descriptor = descriptors[index];
			}
		};
	}
}

namespace RBX
{
	namespace Network
	{
		extern const char sReplicator[];

		class Replicator : public DescribedNonCreatable<Replicator, IdSerializer, sReplicator>, public PluginInterface
		{
			friend struct ::NativeNetworkReplicator2008Layout; // layout probe of tests/record_native_network_replicator2008.py
			// INFERRED: PhysicsSender::step 004cd920 calls the protected findTargetPlayer 004ab9a0.
			friend class PhysicsSender;
			// INFERRED: InterpolatingPhysicsReceiver::receivePacket 004c9120 calls the protected findTargetPlayer (slot 17,
			// `call [eax+0x44]` on its replicator +0x4).
			friend class InterpolatingPhysicsReceiver;
			// INFERRED: RoundRobinPhysicsSender::sendPhysicsData 004caaf0 calls the protected findTargetPlayer (slot 17,
			// `call [edx+0x44]` on its replicator +0x4); measured byte-identical with this friendship (batch 37 nw01).
			friend class RoundRobinPhysicsSender;

		public:
			class ReplicatorStatsItem;
		protected:
			// Donor Replicator::Item (pendingItems element). Layout +0 vtable (novtable base: slot 0 destructor, slot 1
			// write), +4 replicator reference (read by MarkerItem::write 004ae9a0, ItemSender dtor 004aba60).
			class __declspec(novtable) Item
			{
			public:
				enum ItemType
				{
					ItemTypeEnd,
					ItemTypeDelete,
					ItemTypeNew,
					ItemTypeChangeProperty,
					ItemTypeMarker
				};

			protected:
				Replicator& replicator;                                             // +0x04

			protected:
				Item(Replicator& replicator)
					: replicator(replicator)
				{
				}
			public:
				virtual ~Item()
				{
				}
				virtual void write(RakNet::BitStream& bitStream) = 0;

			public:
				static void writeItemType(RakNet::BitStream& stream, ItemType value); // 004ab5d0

			private:
				Item(const Item&);
				Item& operator=(const Item&);
			};

			// Donor Replicator::ItemSender: replicator +0, peer +4, bitStream +8 (the destructor 004aba60 resets and
			// destroys the BitStream at this+8). Remaining members are not read by the destructor.
			class ItemSender
			{
			private:
				Replicator& replicator;                                             // +0x00
				RakPeerInterface* peer;                                             // +0x04
				RakNet::BitStream bitStream;                                        // +0x08
			public:
				~ItemSender();                                                      // 004aba60
			};

			// Donor Replicator::ChangePropertyItem. Layout from write 004b6d10: +0x08 descriptor reference (pushed to
			// propNames.send and ConstProperty), +0x0c shared_ptr<const Instance> (count +0x10).
			class ChangePropertyItem : public Item
			{
			private:
				const Reflection::PropertyDescriptor& desc;                         // +0x08
				const boost::shared_ptr<const Instance> instance;                   // +0x0c

			public:
				// Inline (donor Replicator.cpp body): onParentChanged 004b01e0 expands it after new(0x14) (vtable
				// 00824828, +0x08 desc, +0x0c instance).
				ChangePropertyItem(Replicator& replicator, const boost::shared_ptr<const Instance>& instance, const Reflection::PropertyDescriptor& desc)
					: Item(replicator),
					  instance(instance),
					  desc(desc)
				{
				}
				virtual void write(RakNet::BitStream& bitStream);                   // 004b6d10
			};

			// Donor Replicator::NewInstanceItem. vtable 00824b20: slot 0 deleting destructor 004aff20 (identical-code
			// folded with DeleteInstanceItem's), slot 1 write 004b8620. Layout from the constructor 004afc70: +0x08
			// shared_ptr<Instance> (count +0x0c); new(0x10) in the descendant-added handler 004aff70.
			class NewInstanceItem : public Item
			{
			private:
				boost::shared_ptr<Instance> instance;                               // +0x08

			public:
				NewInstanceItem(Replicator& replicator, const boost::shared_ptr<Instance>& instance); // 004afc70
				virtual void write(RakNet::BitStream& bitStream);                   // 004b8620
			};

			// Donor Replicator::DeleteInstanceItem. vtable 00824b2c: slot 0 004aff20 (folded), slot 1 write 004b47b0.
			// Layout from the constructor 004afe90: +0x08 shared_ptr<const Instance> (count +0x0c).
			class DeleteInstanceItem : public Item
			{
			private:
				boost::shared_ptr<const Instance> instance;                         // +0x08

			public:
				DeleteInstanceItem(Replicator& replicator, const boost::shared_ptr<const Instance>& instance); // 004afe90
				virtual void write(RakNet::BitStream& bitStream);                   // 004b47b0
			};

			class MarkerItem : public Item
			{
			private:
				int id;                                                             // +0x08

			public:
				MarkerItem(Replicator& replicator, int id)
					: Item(replicator),
					  id(id)
				{
				}
				virtual void write(RakNet::BitStream& bitStream);                   // 004ae9a0
			};

		private:
			G3D::RealTime lastSendTime;                                             // +0x2b78
			boost::scoped_ptr<IPhysicsSender> physicsSender;                        // +0x2b80
			boost::scoped_ptr<IPhysicsReceiver> physicsReceiver;                    // +0x2b84
			boost::shared_ptr<ReplicatorStatsItem> statsItem;                       // +0x2b88
			// INFERRED: key/value types after the donor `strings` member; the destructor 004b16a0 is ICF-shared with
			// map<const SignalDescriptor*, shared_ptr<SignalInstance> > (pointer key, shared_ptr value).
			std::map<const Reflection::PropertyDescriptor*, boost::shared_ptr<SharedStringDictionary> > strings; // +0x2b90
			DescriptorDictionary<Reflection::ClassDescriptor> classNames;            // +0x2bb0 (constructor 004b1570)
			DescriptorDictionary<Reflection::PropertyDescriptor> propNames;          // +0x2bf4 (constructor 004b1620)
		public:
			// Per-instance record of the +0x2c38 map (std::pair<const Instance* const, ReplicationData>, 0x30 bytes with the
			// key). A struct in the binary (mangled U: closeReplicationItem 004ab850 takes a pair of it). Layout from the
			// value destructor 004ab8c0 (releases the two connections, then the shared_ptr) and closeReplicationItem:
			// shared_ptr +0x00, boost::signals::connection +0x08 and +0x18, bool +0x28. Member names INFERRED: the
			// destructor/close rows only disconnect both connections and, for the flag, call Instance::setParent(NULL)
			// (055a8f0 with a null argument) on the instance.
			struct ReplicationData
			{
				boost::shared_ptr<Instance> instance;                               // +0x00 INFERRED name
				boost::signals::connection connection0;                             // +0x08 INFERRED name (disconnected first)
				boost::signals::connection connection1;                             // +0x18 INFERRED name
				bool removeOnClose;                                                 // +0x28 INFERRED name (closeReplicationItem tests it)
			};

		private:
			std::map<const Instance*, ReplicationData> containerConnections;        // +0x2c38 (constructor 004b0b90, destructor 004b14c0)

		protected:
			std::vector<Instance*> replicationContainers;                           // +0x2c58 (Server::ClientProxy::sendTop 004a2ac0)
			Players* players;                                                       // +0x2c70 (findTargetPlayer 004ab9a0, slot 20 004ab960)
			std::list<boost::shared_ptr<Item> > pendingItems;                       // +0x2c74 (004aefe0 / 004b0a80)
			std::set<const Instance*> pendingNewInstances;                          // +0x2c90 (004b9d30 / 0064b230)
			std::set<const Instance*> pendingDeleteInstances;                       // +0x2cb0
			bool sendPhysicsEnabled;                                                // +0x2cd0 (constructor stores 0)
			const Reflection::Property* deserializeProperty;                        // +0x2cd4 INFERRED: donor order, pointer zeroed by the constructor
			Instance* removingInstance;                                             // +0x2cd8 INFERRED: donor order, pointer zeroed by the constructor
			std::queue<boost::shared_ptr<Marker> > incomingMarkers;                 // +0x2cdc (deque _Tidy 004af1b0)
			// INFERRED: key/value types after the donor `defaultObjects`; destructor 004b16a0 (pointer key, shared_ptr value).
			std::map<const Name*, boost::shared_ptr<Instance> > defaultObjects;     // +0x2cfc
			boost::scoped_ptr<Profiling::CodeProfiler> profileReplication;          // +0x2d1c "Replication" (CodeProfiler 005c43a0)
			boost::scoped_ptr<Profiling::CodeProfiler> profileDataListening;        // +0x2d20 "Data Listening"
			boost::scoped_ptr<Profiling::CodeProfiler> profileDataIn;               // +0x2d24 "Data In"
			boost::scoped_ptr<Profiling::CodeProfiler> profileDataOut;              // +0x2d28 "Data Out"
			boost::scoped_ptr<Profiling::CodeProfiler> profilePhysicsIn;            // +0x2d2c "Physics In"
			boost::scoped_ptr<Profiling::CodeProfiler> profilePhysicsOut;           // +0x2d30 "Physics Out"
			boost::scoped_ptr<Profiling::CodeProfiler> profileStep;                 // +0x2d34 "Step" (INFERRED name from the string)
			boost::scoped_ptr<Profiling::CodeProfiler> profileWrite;                // +0x2d38 "Write" (INFERRED name from the string)
			// INFERRED names from the strings; 005c43d0 stores the CountProfiler vtable 00838c64 and zeroes +0xc040.
			boost::scoped_ptr<Profiling::CountProfiler> profileBitsReceived;        // +0x2d3c "Bits Received"
			boost::scoped_ptr<Profiling::CountProfiler> profileBitsSent;            // +0x2d40 "Bits Sent"
			boost::scoped_ptr<Profiling::CountProfiler> profileUnsplitMessagesSent; // +0x2d44 "Unsplit Messages Sent"
			boost::scoped_ptr<Profiling::CountProfiler> profileSplitMessagesSent;   // +0x2d48 "Split Messages Sent"

		private:
			bool receivedGlobals;                                                   // +0x2d4c INFERRED: donor order (canSendItems 004aafc0 reads it)
		public:
			bool disconnected;                                                      // +0x2d4d (Peer heartbeat 004aaf6f removes disconnected replicators)
			RakPeerInterface* peer;                                                 // +0x2d50 (AttachPlugin slot 58 in the constructor)
			const SystemAddress remotePlayerId;                                     // +0x2d54
		private:
			// INFERRED: two 4-byte fields zeroed by the constructor and not destroyed (004b73e5, 004b8a18, 004b7d03).
			// +0x2d60 holds the Name* of the last received descriptor (readChangedProperty 004b7a30 stores
			// &descriptor->name after deserializeValue; readInstanceNew 004b78cb stores a descriptor name too); names
			// not derived. sizeof 0x2d68 (8-aligned: lastSendTime is a double).
			int counter0;                                                           // +0x2d5c
			const Name* lastReceivedName;                                           // +0x2d60 INFERRED name

		public:
			Replicator(SystemAddress remotePlayerId, RakPeerInterface* peer);      // 004b9bd0 (open)
			virtual ~Replicator();                                                  // 004b96b0 (open)

			// Reflected functions (static initializers 007f21d0 "RequestCharacter", 007f2200 "CloseConnection" and 007f2230
			// "GetPlayer" pass these addresses to BoundFuncDesc constructors 004b40a0 / 004b4170; donor Replicator.h).
			boost::shared_ptr<Instance> getPlayer();                                // 004ae860 (donor: inline in the class)
			void requestCharacter();                                                // 004b49e0
			void closeConnection();                                                 // 004aafd0
			// 004b9210 (donor Replicator::sendMarker; reflected "SendMarker", static initializer 007f21a0 passes 004b9210 to
			// the BoundFuncDesc constructor 004b3f30; thiscall, ret 4: hidden shared_ptr<DescribedBase> result). Body in
			// ReplicatorSendMarker.cpp.
			boost::shared_ptr<Reflection::DescribedBase> sendMarker();
			// 004aeac0 (donor Replicator::isSerializePending, public: RoundRobinPhysicsSender::sendPhysicsData 004caaf0
			// and PhysicsSender rows 004ca980 call it; thiscall, ret 4, reads pendingNewInstances +0x2c90 / head +0x2ca8
			// through the set find 004ae060). Body in ReplicatorIsSerializePending_004aeac0.cpp.
			bool isSerializePending(const Instance* instance) const;

		protected:
			// Instance slot 12 override (vtable 008254fc; ClientProxy 00823474 inherits it). Body not recovered.
			virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 004b87f0 (open)
		public:
			// Instance slot 14 override: identical-code-folded `return NULL` (as Client / Server write).
			virtual XmlElement* write();                                            // 00416690 (ICF)

		protected:
			// Virtual slots 16..21 (see the vtable notes above). Slot 16 has no donor counterpart: INFERRED name from its
			// signature (bool (const Instance*), ICF-shared `mov al,1; ret 4`; ClientProxy overrides it with 004a3290).
			virtual bool replicates(const Instance* instance) const;                // slot 16 00565ff0 INFERRED name
			virtual Player* findTargetPlayer();                                     // slot 17 004ab9a0
			virtual bool wantReplicate(const Instance* source) const;               // slot 18 004aaf90
			virtual void onSentMarker(long id);                                     // slot 19 0070bdf0 (empty)
		private:
			// Access follows the name table (?remoteDeleteOnDisconnect...EBE_N = private virtual; donor: canSendItems private).
			virtual bool remoteDeleteOnDisconnect(const Instance* instance) const;  // slot 20 004ab960
			virtual bool canSendItems();                                            // slot 21 004aafc0

		protected:

			// 004ab850: for_each callback over containerConnections (disconnects both connections of one record).
			static void closeReplicationItem(const std::pair<const Instance* const, ReplicationData>& item);

			// 004afd00 (donor Replicator::disconnectReplicationData; thiscall, shared_ptr by value, returns bool: callers
			// onParentChanged 004b01e0 and the delete reader 004b0800). Body not recovered (visits the children through
			// an Instance::visitChildren instance 004ae570 that the native v8tree/Instance.h does not declare).
			bool disconnectReplicationData(boost::shared_ptr<Instance> instance);
			// INFERRED: donor inline helper (pendingNewInstances.erase, set erase 005e9f60); defined in
			// NetworkReplicator2008Items.cpp, expanded into onParentChanged 004b01e0.
			inline bool removeFromPendingNewInstances(const Instance* instance);
			// 004b01e0 (donor Replicator::onParentChanged; Instance::propParent 00973d34 change item or delete item).
			void onParentChanged(boost::shared_ptr<Instance> instance);

		protected:
			// 004b4bb0 (donor Replicator::getDefault; thiscall, ret 4: looks the class name up in defaultObjects +0x2cfc).
			// Body in NetworkReplicator2008StatsItem.cpp.
			const Instance* getDefault(const Name& className);
			// 004b7f20 (thiscall (const Instance*, RakNet::BitStream&), ret 8; callers Server::ClientProxy::sendTop 004a2bc4
			// and 004b87ae). INFERRED name: the donor Replicator has no counterpart; the body writes every canStreamWrite
			// property except Instance::propParent ("   write %s %s, ..." strings 008251b0 / 00825190 / 00825178), so the
			// name follows Instance::writeProperties. Body in NetworkReplicator2008StatsItem.cpp.
			void writeProperties(const Instance* instance, RakNet::BitStream& stream);

		private:
			// 004b6730 (donor Replicator::getSharedDictionary; thiscall, ret 4: looks the descriptor up in strings +0x2b90,
			// else new(0x2a24) SharedStringDictionary 004b3d10; only caller serializeValue 004b6890). Body in
			// NetworkReplicator2008StatsItem.cpp.
			SharedStringDictionary& getSharedDictionary(const Reflection::PropertyDescriptor& descriptor);
			// 004b6890 (donor Replicator::serializeValue; thiscall, ret 0xc). Body in NetworkReplicator2008StatsItem.cpp.
			void serializeValue(const Reflection::ConstProperty& property, bool, RakNet::BitStream& stream);
			// 004b6ab0 (donor Replicator::deserializeValue, the mirror of serializeValue 004b6890: same type-singleton
			// order; ScopedAssign of deserializeProperty +0x2cd4 around the body). Body in NetworkReplicator2008Items.cpp.
			void deserializeValue(RakNet::BitStream& stream, Reflection::Property& property);
			// 004b6f00 (donor Replicator::readProperties; thiscall (BitStream&, Instance*), ret 8: the mirror of
			// writeProperties 004b7f20 with the "   read %s %s, ..." prints 00825070 / 00825050 / 00825038).
			void readProperties(RakNet::BitStream& stream, Instance* instance);
			// 004b7a30 (donor Replicator::readChangedProperty; thiscall (BitStream&), ret 4). Body in
			// NetworkReplicator2008Items.cpp (deserializeInstanceRef 004a8b60 is declared in Network/IdSerializer.h).
			void readChangedProperty(RakNet::BitStream& stream);
			// 004b0800 (donor Replicator::readInstanceDelete; thiscall (BitStream&), ret 4). Body in
			// NetworkReplicator2008Items.cpp behind NATIVE_REPLICATOR_DESERIALIZE_REF (a 623/627-byte near miss).
			void readInstanceDelete(RakNet::BitStream& stream);
		};

#ifndef NATIVE_REPLICATOR_NO_STATS_ITEM
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
			virtual void update();                                                  // 004b6530 (NetworkReplicator2008StatsItem.cpp)
		};
#endif
	}
}
