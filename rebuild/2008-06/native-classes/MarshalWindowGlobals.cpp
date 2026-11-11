// >>> native-status (generated) -- do not edit >>>
// MarshalWindowGlobals | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src fb34148b | roc native-status --write
#include "util/MarshaledListener.h"
#include <map>

namespace RBX {
std::map<DWORD, CMarshalWindow*> marshalWindows;
ATL::CCriticalSection marshalRegistryLock;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<unsigned long const ,RBX::CMarshalWindow *> > >;
template class std::_Tmap_traits<unsigned long,RBX::CMarshalWindow *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,RBX::CMarshalWindow *> >,0>;
template class std::_Tree<std::_Tmap_traits<unsigned long,RBX::CMarshalWindow *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,RBX::CMarshalWindow *> >,0> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<unsigned long,RBX::CMarshalWindow *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,RBX::CMarshalWindow *> >,0> >::_Node *>;
template class std::allocator<std::pair<unsigned long const ,RBX::CMarshalWindow *> >;
template class std::map<unsigned long,RBX::CMarshalWindow *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,RBX::CMarshalWindow *> > >;
