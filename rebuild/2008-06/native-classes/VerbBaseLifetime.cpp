// >>> native-status (generated) -- do not edit >>>
// VerbBaseLifetime | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 7326625f | roc native-status --write
#include "v8tree/Verb.h"

RBX::Verb::~Verb()
{
    if (container) container->verbs.erase(&name);
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::pair<std::_Tree<std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0> >::iterator,std::_Tree<std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0> >::iterator>;
