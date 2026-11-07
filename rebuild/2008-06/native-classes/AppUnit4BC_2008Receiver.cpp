// 2008-06 native rows of the physics-replication receiver unit inside 004bc000..004c8000 (inactive). Evidence:
// native-headers/Network/PhysicsSenders2008.h (read-only, other owner) and native-headers/AppUnit4BC_2008/
// AssociationTimeStamp.h. Verified by tests/record_native_app_unit4bc_2008.py. Built with /fp:fast: hashed_index
// reserve 004c7730 and unchecked_rehash 004c7330 keep the max-load products on the x87 stack (121 / 504 bytes
// without it, 117 / 497 with it).
//
// Rows compiled from the current headers (explicit instantiations, as in OgreRbxSky.cpp / AdornRbxGfx.cpp):
//   * Association<Instance>::Item::~Item 004c6d30 and its ??_G 004c7090, Association<Instance>::get<TimeStamp>
//     004c7ef0 (the DirectPhysicsReceiver packet handler 004c83b0 calls it on Instance +0xec);
//   * the InterpolatingPhysicsReceiver::PartItems members the receiver's step / receivePacket reach: hashed
//     link_point 004c70b0, bucket_array first_nonempty 004c70f0, ordered link_point 004c7110 / in_place 004c71d0 /
//     erase_ 004c7e80, and the compiler-generated History / PartItem copy constructors 004c7c10 / 004c7dd0 with
//     std::vector<float>'s copy constructor 004c77b0. hashed reserve 004c7730 is byte-exact here too, but its call
//     target unchecked_rehash 004c7330 is exact only in the pending build, so it is recorded with the pending rows.
// NATIVE_APPUNIT4BC_PENDING (built only against the generated header copy
// out/native-layouts/app-unit4bc-2008-pending/Network/PhysicsSenders2008.h; see the recorder's proposal): the
// PartItem(const shared_ptr<PartInstance>&) constructor 004c7a10 (with the implicit History() 004c76a0 it reaches)
// and the hashed find 004c72b0 / unchecked_rehash 004c7330, which call the out-of-line hash 004ca5b0.
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

#ifdef NATIVE_APPUNIT4BC_PENDING
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

typedef RBX::Network::InterpolatingPhysicsReceiver::PartItems::nth_index<0>::type ReceiverPartIndex;
template ReceiverPartIndex::iterator ReceiverPartIndex::find<boost::shared_ptr<RBX::PartInstance> >(
	const boost::shared_ptr<RBX::PartInstance>&) const;
#endif
