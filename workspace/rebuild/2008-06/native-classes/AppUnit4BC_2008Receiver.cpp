// 2008-06 native rows of the physics-replication receiver unit from 004c6d30 (it runs past 004c8000; inactive).
// Evidence: native-headers/Network/PhysicsSenders2008.h and native-headers/AppUnit4BC_2008/AssociationTimeStamp.h.
// Verified by tests/record_native_app_unit4bc_2008.py. Built with /fp:fast: hashed_index reserve 004c7730 and
// unchecked_rehash 004c7330 keep the max-load products on the x87 stack (121 / 504 bytes without it, 117 / 497 with it).
//
// Rows (explicit instantiations, as in OgreRbxSky.cpp / AdornRbxGfx.cpp):
//   * Association<Instance>::Item::~Item 004c6d30 and its ??_G 004c7090, Association<Instance>::get<TimeStamp>
//     004c7ef0 (the DirectPhysicsReceiver packet handler 004c83b0 calls it on Instance +0xec);
//   * the InterpolatingPhysicsReceiver::PartItems members the receiver's step / receivePacket reach: hashed
//     link_point 004c70b0, find 004c72b0, unchecked_rehash 004c7330, reserve 004c7730 and insert_ 004c8e40 (the
//     hashing ones call hash_value 004ca5b0 through boost::hash<shared_ptr<PartInstance> >), bucket_array
//     first_nonempty 004c70f0, ordered link_point 004c7110 / in_place 004c71d0 / erase_ 004c7e80 / insert_ 004c8cf0,
//     index_base insert_ 004c8b20, the compiler-generated History / PartItem copy constructors 004c7c10 / 004c7dd0 with
//     std::vector<float>'s copy constructor 004c77b0;
//   * PartItem(const shared_ptr<PartInstance>&) 004c7a10 with the implicit History() 004c76a0 it reaches.
#include "Network/PhysicsSenders2008.h"
#include "AppUnit4BC_2008/AssociationTimeStamp.h"

namespace RBX
{
	class Instance;
}

template TimeStamp& RBX::Association<RBX::Instance>::get<TimeStamp>();
template class std::vector<float>;
template class boost::multi_index::multi_index_container<
	RBX::Network::InterpolatingPhysicsReceiver::PartItem,
	RBX::Network::InterpolatingPhysicsReceiver::PartItems::index_specifier_type_list>;

// hashed find 004c72b0 (the one-argument find<Key> instantiation emits the three-argument body; it calls hash_value
// 004ca5b0 through boost::hash<shared_ptr<PartInstance> >).
typedef RBX::Network::InterpolatingPhysicsReceiver::PartItems::nth_index<0>::type ReceiverPartIndex;
template ReceiverPartIndex::iterator ReceiverPartIndex::find<boost::shared_ptr<RBX::PartInstance> >(
	const boost::shared_ptr<RBX::PartInstance>&) const;

namespace RBX
{
	namespace Network
	{
		// 004c7a10: copies the part (shared_ptr add-ref), zeroes interval (+0x10, fldz/fstp qword), head and count
		// (+0x18/+0x1c) and default-constructs the eight History entries (eh vector constructor, History() 004c76a0,
		// ~History 004ae910). The ordered key at +8 is not written.
		InterpolatingPhysicsReceiver::PartItem::PartItem(const boost::shared_ptr<PartInstance>& part)
			: part(part)
			, interval(0)
			, head(0)
			, count(0)
		{
		}
	}
}
