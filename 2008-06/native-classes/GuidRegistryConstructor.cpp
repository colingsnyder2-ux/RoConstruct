// >>> native-status (generated) -- do not edit >>>
// GuidRegistryConstructor | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (chatgpt:gpt-6.1-sol)
// <<< native-status | src 5e9a03e2 | roc native-status --write
#include "util/GuidRegistry.h"

RBX::GuidRegistry::GuidRegistry() : tree(), mutex() {}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Guid::Data const ,RBX::Instance *> > >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Guid::Data,RBX::Instance *,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,RBX::Instance *> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Guid::Data const ,RBX::Instance *> >;
template class std::map<RBX::Guid::Data,RBX::Instance *,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,RBX::Instance *> > >;
