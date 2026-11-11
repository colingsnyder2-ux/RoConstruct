#pragma once
// >>> native-status (generated) -- do not edit >>>
// PhysicsSenders2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src f3e22a64 | roc native-status --write
// 2008-06 native RBX::Network::PhysicsSender and InterpolatingPhysicsReceiver (inactive). The interfaces, the two
// simple implementations and the owner evidence are in Network/PhysicsReplication.h (committed, read-only here); this
// header has its own name, so no donor header is shadowed. The donor tree has neither class. Every base, field, index
// and size below is read from the 2008-06 binary; names are descriptive (no symbol evidence).
//
// PhysicsSender (vtable 00826928, RTTI [PhysicsSender, IPhysicsSender, boost::noncopyable])
//   size     0x74: Replicator 004ba094 news 0x74 before the constructor 004ccb10.
//   ctor     004ccb10: vtable, items(default ctor_args_list, allocator) 004cc400 at +4, +0x3c = replicator argument,
//            +0x40 = 0, shared_ptr +0x44/+0x48 = 0, scoped_connection +0x4c (px/pn +0x50/+0x54 = 0, controlling
//            +0x58 = false, released +0x5c = false), scoped_connection +0x60 (+0x64/+0x68, +0x6c, +0x70). +0x38 is
//            not written: a default-constructed ordered-index iterator.
//   dtor     004ccb90 (out of line): ~scoped_connection 005954b0 on +0x60 then +0x4c, shared_ptr release +0x44/+0x48,
//            ~multi_index_container 004ccab0 on +4; ??_G 004ccde0.
//   fields   +0x38 an iterator of index 1 (step/sendPackets 004cce00 compare it with that index's header node, advance
//            it through the ordered node at node +0x60, and copy the item it designates with 004c9d90);
//            +0x3c Replicator* (passed to ServiceProvider::create<PhysicsService> 004cd8d0 in step 004cd920);
//            +0x40 int step counter (`inc [ebp+0x40]` in 004cd920, passed to the item update 004c9e30);
//            +0x44 shared_ptr<PhysicsService> (shared_from(create<PhysicsService>(replicator)) in 004cd920; its
//            parts set head +0x150 is walked there); +0x4c scoped_connection (assigned 00595540 from the connection
//            004a3340 returns for the static signal 0097abec that PhysicsService::onAdded fires); +0x60 the second
//            scoped_connection.
//   items    boost 1.34.1 multi_index_container<PartItem, indexed_by<hashed_unique, ordered_non_unique,
//            ordered_non_unique>>, 0x34 bytes: header node new(0x78) (004cc400; node: value 0x50, index 2 ordered
//            impl +0x50, index 1 ordered impl +0x60, hashed impl +0x70), hashed_index ctor 004cbdc0 (ordered
//            empty_initialize 004cadd0 / 004cacc0, bucket_array ctor 004cb540, mlf = 1.0f, calculate_max_load
//            004ca090), node_count +0x30. Destructor 004ccab0 (delete_all_nodes 004cc460: ~PartItem releases only
//            the shared_ptr at value +0).
//              index 0 hashed_unique on value +0: replace_ 004cc5e0 compares the two shared_ptr pointers and hashes
//                      x + (x >> 3) of the pointer inline: boost::hash<shared_ptr<PartInstance> > (boost 1.34.1 has no
//                      hash_value(shared_ptr)) reaching RBX::hash_value, defined out of line at 004ca5b0 in this
//                      unit (NetworkPhysicsSenders2008.cpp) and called by the receiver (below).
//              index 1 ordered_non_unique on the double at value +8 with std::greater<double> (node impl +0x60).
//              index 2 ordered_non_unique on the int at value +0x44 with std::less<int>: in_place 004caf40 is the
//                      non-unique form (`v < prev` rejects, then `!(next < v)`), link_point 004cb280 uses setl.
//   PartItem 0x50: copy constructor 004c9d90 (compiler generated): shared_ptr<PartInstance> +0 (deref'd as the part:
//            ->getCoordinateFrame 00598cb0 in 004c9e30), double +8, CoordinateFrame +0x10 (Matrix3 copy 00513220 +
//            translation), float +0x40, int +0x44, float +0x48 (+0x4c is the double-alignment tail).
//
// InterpolatingPhysicsReceiver (vtable 00824ee4, RTTI [InterpolatingPhysicsReceiver, IPhysicsReceiver, noncopyable])
//   size     0x3c: Replicator 004ba0e8 news 0x3c before the constructor 004b5e80.
//   ctor     004b5e80: +4 = replicator argument, vtable, items(default ctor_args_list, allocator) 004b0ae0 at +8.
//   dtor     implicit and inline: ??_G 004b6290 runs ~multi_index_container 004b58f0 on +8 and deletes.
//   items    multi_index_container<PartItem, indexed_by<hashed_unique, ordered_non_unique>>, 0x34 bytes: header node
//            new(0x298) (004b0ae0 inlines the hashed_index ctor: ordered empty_initialize 004acc30, bucket_array ctor
//            004cb540 and calculate_max_load 004ca090, both identical-code folded with the sender's); node: value
//            0x280, ordered impl +0x280, hashed impl +0x290. Destructor 004b58f0 (delete_all_nodes 004b43c0 calls
//            ~PartItem 004af950).
//              index 0 hashed_unique on value +0 (shared_ptr, boost::hash; find 004c72b0, unchecked_rehash
//                      004c7330, replace_ 004c8b70 and insert_ 004c8e40 call hash_value 004ca5b0).
//              index 1 ordered_non_unique on the unsigned at value +8: link_point 004c7110 compares with setb and
//                      always returns true (non-unique form).
//   PartItem 0x280: ~PartItem 004af950 (compiler generated): eh vector destructor 006a165b over 8 History of 0x4c at
//            +0x20 (element destructor 004ae910), then the shared_ptr<PartInstance> at +0. Step helper 004c6f70: the
//            part at +0 (PartInstance 00598d10), double +0x10 (fsub qword), int +0x18 (ring index, `(i + 8) % 8`
//            with 0x4c stride from +0x20), int +0x1c (history count). +8 is the ordered key (unsigned, above).
//   History  0x4c: unsigned timestamp +0 (fild + 2^32 correction in 004c6f70), CoordinateFrame +4 (interpolated by
//            00518a50 in 004c6dc0), std::vector<float> +0x34 (VS2008 checked vector, 0x18 bytes: ~History 004ae910
//            frees _Myfirst +0x40, clears +0x40/+0x44/+0x48 and deletes the owned aux +0x34; 004c6dc0 lerps its
//            elements with fld dword and passes each to the motor joint 005e5da0).
#include "Network/PhysicsReplication.h"
#include <boost/shared_ptr.hpp>
#include <boost/functional/hash.hpp>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/signals/connection.hpp>
#include <G3D/CoordinateFrame.h>
#include <functional>
#include <vector>

struct NativeNetworkPhysicsSendersLayout;

namespace RBX
{
	class PartInstance;
	class PhysicsService;

	// Out-of-line hash of the part pointer (004ca5b0, cdecl: `return p + (p >> 3)` of part.get()). boost::hash<
	// shared_ptr<PartInstance> > reaches it by ADL. The receiver's find 004c72b0, unchecked_rehash 004c7330, replace_
	// 004c8b70 and insert_ 004c8e40 call it (004c72ba, 004c73e5, 004c8bc0, 004c8e60, `add esp, 4` after each).
	std::size_t hash_value(const boost::shared_ptr<PartInstance>& part);

	namespace Network
	{
		class PhysicsSender : public IPhysicsSender
		{
			friend struct ::NativeNetworkPhysicsSendersLayout; // tests/NativeNetworkPhysicsSenders2008Layout.cpp
		public:
			struct PartItem
			{
				boost::shared_ptr<PartInstance> part;                              // +0x0  (index 0 key)
				double priority;                                                   // +0x8  (index 1 key)
				G3D::CoordinateFrame lastFrame;                                    // +0x10
				float accumulated;                                                 // +0x40
				int lastSendStep;                                                  // +0x44 (index 2 key)
				float error;                                                       // +0x48
			};
			typedef boost::multi_index::multi_index_container<
				PartItem,
				boost::multi_index::indexed_by<
					boost::multi_index::hashed_unique<
						boost::multi_index::member<PartItem, boost::shared_ptr<PartInstance>, &PartItem::part> >,
					boost::multi_index::ordered_non_unique<
						boost::multi_index::member<PartItem, double, &PartItem::priority>, std::greater<double> >,
					boost::multi_index::ordered_non_unique<
						boost::multi_index::member<PartItem, int, &PartItem::lastSendStep> >
				>
			> PartItems;

		private:
			PartItems items;                                                       // +0x4
			PartItems::nth_index<1>::type::iterator nextItem;                      // +0x38
			Replicator* replicator;                                                // +0x3c
			int stepCount;                                                         // +0x40
			boost::shared_ptr<PhysicsService> physicsService;                      // +0x44
			boost::signals::scoped_connection partAddedConnection;                 // +0x4c
			boost::signals::scoped_connection secondConnection;                    // +0x60 (dtor 004ccb90)

		public:
			PhysicsSender(Replicator* replicator);                                 // 004ccb10
			~PhysicsSender();                                                      // 004ccb90 (??_G 004ccde0)
			/*override*/ virtual void step();                                      // 004cd920 (open)
			/*override*/ virtual int sendPackets(int maxPackets);                  // 004cce00 (open)
		};

		class InterpolatingPhysicsReceiver : public IPhysicsReceiver
		{
			friend struct ::NativeNetworkPhysicsSendersLayout; // tests/NativeNetworkPhysicsSenders2008Layout.cpp
		public:
			struct History
			{
				unsigned int timestamp;                                            // +0x0
				G3D::CoordinateFrame frame;                                        // +0x4
				std::vector<float> motorAngles;                                    // +0x34
			};
			struct PartItem
			{
				boost::shared_ptr<PartInstance> part;                              // +0x0  (index 0 key)
				unsigned int timestamp;                                            // +0x8  (index 1 key)
				double interval;                                                   // +0x10
				int head;                                                          // +0x18
				int count;                                                         // +0x1c
				History history[8];                                                // +0x20
				// 004c7a10 (ret 4, only caller receivePacket 004c9120): copies the part (add-ref), zeroes interval (fldz /
				// fstp qword +0x10), head and count (+0x18 / +0x1c); the eh vector constructor 006a1598 runs History()
				// 004c76a0 over history[8]. The ordered key +8 is not written.
				PartItem(const boost::shared_ptr<PartInstance>& part);
			};
			typedef boost::multi_index::multi_index_container<
				PartItem,
				boost::multi_index::indexed_by<
					boost::multi_index::hashed_unique<
						boost::multi_index::member<PartItem, boost::shared_ptr<PartInstance>, &PartItem::part> >,
					boost::multi_index::ordered_non_unique<
						boost::multi_index::member<PartItem, unsigned int, &PartItem::timestamp> >
				>
			> PartItems;

		private:
			Replicator* replicator;                                                // +0x4
			PartItems items;                                                       // +0x8

		public:
			InterpolatingPhysicsReceiver(Replicator* replicator);                  // 004b5e80
			/*override*/ virtual void step(unsigned int time);                     // 004c8fa0 (open)
			/*override*/ virtual void receivePacket(RakNet::BitStream& bitStream, unsigned int timeStamp); // 004c9120 (open)
		};
	}
}
