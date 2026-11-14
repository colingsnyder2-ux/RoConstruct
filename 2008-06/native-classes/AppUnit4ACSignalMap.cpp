// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native STL instance of the Network/Replicator.cpp unit inside the application range 004ac000..004b0000
// (inactive): the tree of std::map<const Reflection::SignalDescriptor*, shared_ptr<Reflection::SignalInstance> >,
// the SignalSource::signals map of the read-only native-headers/reflection/signal.h. Rows: _Insert 004ae370,
// insert(const value_type&) 004af270 (caller 00592350) and erase(const_iterator, const_iterator) 004af530 (caller
// the map destructor 004b1160). Verified by tests/record_native_app_unit4ac.py.
#include "reflection/signal.h"

template class std::_Tree<std::_Tmap_traits<const RBX::Reflection::SignalDescriptor*,
	boost::shared_ptr<RBX::Reflection::SignalInstance>, std::less<const RBX::Reflection::SignalDescriptor*>,
	std::allocator<std::pair<const RBX::Reflection::SignalDescriptor* const,
	boost::shared_ptr<RBX::Reflection::SignalInstance> > >, false> >;
