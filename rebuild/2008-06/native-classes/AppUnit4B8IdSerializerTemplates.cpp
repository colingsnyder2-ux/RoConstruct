// 2008-06 native STL instance of the Network/Replicator.cpp unit inside the application range 004b8000..004bc000
// (inactive): std::_Tree<map<Guid::Data, std::vector<IdSerializer::WaitItem> > traits>::erase(const_iterator,
// const_iterator) at 004b8a80, on the IdSerializer::waitItems element types of the read-only
// native-headers/Network/IdSerializer.h (+0x2b54). Evidence: the original body calls the map's own
// erase(const_iterator) 004a8d50 and _Erase(_Node*) 004b7e10 (bodies bytes-equal to this build's instances of the
// Guid::Data tree), and the IdSerializer map destructor 004b93d0 (counted by network-replicator) calls it.
// The std::string -> unsigned char dictionary tree builds the same bytes, but its erase(first, last) relocations
// point at its own helpers (folded with set<ContentId> 0046af90), so 004b8a80 is the Guid::Data instance.
// Explicit instantiation of the tree class only (VS2008 applies the access checks to an explicit member-function
// instantiation, C2248 on the protected WaitItem, but not to an explicit class instantiation; std::map does not
// instantiate the members of its _Tree base, so the tree itself is named). Verified by tests/record_native_app_unit4b8.py.
#include "Network/IdSerializer.h"

template class std::_Tree<std::_Tmap_traits<RBX::Guid::Data, std::vector<RBX::Network::IdSerializer::WaitItem>,
	std::less<RBX::Guid::Data>, std::allocator<std::pair<const RBX::Guid::Data,
	std::vector<RBX::Network::IdSerializer::WaitItem> > >, false> >;
