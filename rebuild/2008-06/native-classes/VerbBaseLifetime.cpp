// >>> native-status (generated) -- do not edit >>>
// VerbBaseLifetime | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 7326625f | roc native-status --write
#include "v8tree/Verb.h"

RBX::Verb::~Verb()
{
    if (container) container->verbs.erase(&name);
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::pair<std::_Tree<std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0> >::iterator,std::_Tree<std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0> >::iterator>;
