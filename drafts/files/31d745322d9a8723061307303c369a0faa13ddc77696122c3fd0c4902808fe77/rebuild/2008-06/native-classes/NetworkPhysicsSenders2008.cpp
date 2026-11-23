// 2008-06 native RBX::Network::PhysicsSender / InterpolatingPhysicsReceiver (inactive); evidence in
// native-headers/Network/PhysicsSenders2008.h. Verified by tests/record_native_network_physics_senders2008.py.
// Rows compiled here: the out-of-line part hash hash_value 004ca5b0, the two constructors, PhysicsSender's destructor
// and both scalar deleting destructors, plus the boost 1.34.1 multi_index_container instantiations they reach
// (container constructors/destructors, hashed index constructor, bucket array constructor, max-load calculation,
// ordered empty_initialize, delete_all_nodes and the compiler-generated PartItem/History destructors) and, from the
// explicit sender container instantiation below, the sender index members 004c9b20..004cc580. step/sendPackets/
// receivePacket are declared only (open: they need the native Replicator). Built with /fp:fast (calculate_max_load
// 004ca090 keeps the product on the x87 stack).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "Network/PhysicsSenders2008.h"
#include "v8datamodel/PartInstance.h"  // complete PartInstance for shared_dynamic_cast 005d4080

namespace RBX
{
	// 004ca5b0 (cdecl; `mov eax,[esp+4]; mov ecx,[eax]; mov eax,ecx; shr eax,3; add eax,ecx; ret`). Inlined in the
	// sender's own index code (replace_ 004cc5e0 at 004cc64f); the receiver calls this copy.
	std::size_t hash_value(const boost::shared_ptr<PartInstance>& part)
	{
		return boost::hash<PartInstance*>()(part.get());
	}

	namespace Network
	{
		PhysicsSender::PhysicsSender(Replicator* replicator)
			: replicator(replicator)
			, stepCount(0)
		{
		}

		PhysicsSender::~PhysicsSender()
		{
		}

		// 004cd170 (registry placeholder func_004cd170; thiscall `ret 8`, bound by step 004cd920 through boost::bind and by
		// the PhysicsService connection): shared_dynamic_cast<PartInstance> 005d4080 of the instance; the hashed index-0
		// find 004cb340 (three-argument body with RBX::hash_value 004ca5b0 inlined, which is why it lives in this unit);
		// when the part is not there, insert 004cc960 of PartItem(part) 004ca500 (by-value shared_ptr copy).
		void PhysicsSender::addPhysicsInstance(boost::shared_ptr<Instance> instance)
		{
			boost::shared_ptr<PartInstance> part = boost::shared_dynamic_cast<PartInstance>(instance);

			if (items.find(part) == items.end())
				items.insert(PartItem(part));
		}

		InterpolatingPhysicsReceiver::InterpolatingPhysicsReceiver(Replicator* replicator)
			: replicator(replicator)
		{
		}
	}
}

// The sender container's remaining index members (explicit instantiation, as AppUnit4BC_2008Receiver.cpp does for the
// receiver container): the hashed / ordered link, link_point, in_place, insert_, erase_, replace_ and reserve bodies
// and the PartItem copy / assignment the sender's step / sendPackets reach (004c9b20..004cc580).
template class boost::multi_index::multi_index_container<
	RBX::Network::PhysicsSender::PartItem,
	RBX::Network::PhysicsSender::PartItems::index_specifier_type_list>;

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::multi_index::detail::auto_space<boost::multi_index::detail::copy_map_entry<boost::multi_index::detail::hashed_index_node<boost::multi_index::detail::ordered_index_node<boost::multi_index::detail::ordered_index_node<boost::multi_index::detail::index_node_base<RBX::Network::PhysicsSender::PartItem> > > > >,std::allocator<RBX::Network::PhysicsSender::PartItem> >;
template class boost::multi_index::detail::auto_space<boost::multi_index::detail::hashed_index_node_impl,std::allocator<RBX::Network::InterpolatingPhysicsReceiver::PartItem> >;
template class boost::multi_index::detail::auto_space<unsigned int,std::allocator<RBX::Network::PhysicsSender::PartItem> >;
template class boost::multi_index::detail::bidir_node_iterator<boost::multi_index::detail::ordered_index_node<boost::multi_index::detail::ordered_index_node<boost::multi_index::detail::index_node_base<RBX::Network::PhysicsSender::PartItem> > >,boost::mpl::na>;
template class boost::multi_index::detail::bucket_array<std::allocator<RBX::Network::InterpolatingPhysicsReceiver::PartItem> >;
template class boost::shared_ptr<RBX::PhysicsService>;
template class std::_Vector_val<float,std::allocator<float> >;
template class std::allocator<RBX::Network::PhysicsSender::PartItem>;
template class std::pair<boost::multi_index::detail::copy_map_entry<boost::multi_index::detail::hashed_index_node<boost::multi_index::detail::ordered_index_node<boost::multi_index::detail::ordered_index_node<boost::multi_index::detail::index_node_base<RBX::Network::PhysicsSender::PartItem> > > > > *,boost::multi_index::detail::copy_map_entry<boost::multi_index::detail::hashed_index_node<boost::multi_index::detail::ordered_index_node<boost::multi_index::detail::ordered_index_node<boost::multi_index::detail::index_node_base<RBX::Network::PhysicsSender::PartItem> > > > > *>;
template class std::vector<float,std::allocator<float> >;

// 004cc7e0: the hashed index-0 modify_(node*) that the container's modify_<Modifier> 004cca10
// (AppUnit4CCPhysicsSenderIndex.cpp) reaches. hashed_index is a base of the container, so the container's explicit
// instantiation above does not emit its members; it must be emitted here because it inlines RBX::hash_value 004ca5b0
// (`mov eax,ecx; shr eax,3; add eax,ecx` at 004cc82a), whose definition is in this unit.
template bool RBX::Network::PhysicsSender::PartItems::nth_index<0>::type::modify_(
	RBX::Network::PhysicsSender::PartItems::nth_index<0>::type::node_type* x);
