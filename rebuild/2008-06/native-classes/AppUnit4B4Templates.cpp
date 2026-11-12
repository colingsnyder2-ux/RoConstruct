// 2008-06 native template instances of the Network/Replicator.cpp unit inside the application range 004b4000..004b8000
// (inactive). Explicit instantiations only, against the read-only native headers stats/Stats.h and
// Network/IdSerializer.h; the Replicator members that use them in the original (the ReplicatorStatsItem constructor
// 004b62c0 and the signal-instance lookup 004b6730) read Replicator members past +0x2b90 that Network/Replicator2008.h
// leaves pending, so the instances are requested here instead of being implied by those bodies.
//   * Stats::TypedStatsItem<bool> (vtable 00824e9c .?AV?$TypedStatsItem@_N@Stats@RBX@@): update 004b51d0; its
//     Creatable<Instance>::create<TypedStatsItem<bool>, const bool*> 004b5ca0 (malloc 0x178, constructor 004b5100) and
//     Item::createBoundChildItem<bool> 004b60c0 (called from the ReplicatorStatsItem constructor 004b63a9 and from
//     005afe8f). The constructor 004b5100 keeps the known Stats.h gap (the original inlines function0::assign_to down
//     to has_empty_target, 194 bytes; this build 120), as TypedStatsItem<unsigned int> / <int> / <G3D::Stopwatch>.
//   * boost::shared_ptr<SharedStringDictionary>(SharedStringDictionary*): shared_count constructor 004b5d20 (new 0x10,
//     sp_counted_impl_p vtable 00824708 .?AV?$sp_counted_impl_p@VSharedStringDictionary@Network@RBX@@@detail@boost@@),
//     its catch(...) funclet 004b5d8e, boost::checked_delete<SharedStringDictionary> 004b5200 and
//     sp_counted_impl_p<SharedStringDictionary>::dispose 004b5e60 (both call ~SharedStringDictionary 004b3d70);
//     the only caller is the signal-instance lookup 004b6730 (new 0x2a24, SharedStringDictionary() 004b3d10).
//   * std::_Tree<map<Guid::Data, std::vector<IdSerializer::WaitItem> > traits>::_Erase 004b7e10 (IdSerializer::waitItems
//     +0x2b54; ~vector<WaitItem> 004a7fa0), the tree whose erase(first, last) 004b8a80 app-unit4b8 counts.
// Verified by tests/record_native_app_unit4b4.py.
#include "Network/IdSerializer.h"
#include "stats/Stats.h"
#include <boost/shared_ptr.hpp>

namespace RBX
{
	namespace Stats
	{
		template class TypedStatsItem<bool>;                                          // vtable 00824e9c, update 004b51d0
		template Item* Item::createBoundChildItem<bool>(const char*, const bool&);    // 004b60c0
	}
	template boost::shared_ptr<Stats::TypedStatsItem<bool> >
		Creatable<Instance>::create<Stats::TypedStatsItem<bool>, const bool*>(const bool*); // 004b5ca0
}

template boost::detail::shared_count::shared_count(RBX::Network::SharedStringDictionary*); // 004b5d20

// Explicit class instantiation (an explicit member instantiation trips C2248 on the protected WaitItem, see
// AppUnit4B8IdSerializerTemplates.cpp).
template class std::_Tree<std::_Tmap_traits<RBX::Guid::Data, std::vector<RBX::Network::IdSerializer::WaitItem>,
	std::less<RBX::Guid::Data>, std::allocator<std::pair<const RBX::Guid::Data,
	std::vector<RBX::Network::IdSerializer::WaitItem> > >, false> >;                // _Erase 004b7e10
