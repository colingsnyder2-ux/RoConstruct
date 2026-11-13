// 2008-06 native STL instance of the Network/Replicator.cpp unit inside the application range 004ac000..004b0000
// (inactive): the tree of std::map<Guid::Data, Instance*>, the GuidRegistry::tree of the read-only
// native-headers/util/GuidRegistry.h. Rows: erase(const key_type&) 004af4c0 (caller 004b3760) with its
// _Eqrange 004ad940 and std::_Distance2<const_iterator, unsigned int> 004ad520; erase(first, last) is 004983f0
// (outside this range). Verified by tests/record_native_app_unit4ac.py.
#include "util/GuidRegistry.h"

template class std::_Tree<std::_Tmap_traits<RBX::Guid::Data, RBX::Instance*, std::less<RBX::Guid::Data>,
	std::allocator<std::pair<const RBX::Guid::Data, RBX::Instance*> >, false> >;
