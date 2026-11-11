// >>> native-status (generated) -- do not edit >>>
// Verb | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/3 mapped addresses byte-exact | 2 unproved | no mapped strings | by colin (+1) (mixed 2)
// <<< native-status | src 29581cb2 | roc native-status --write
#include "../native-headers/v8tree/Verb.h"
#include "StandardVerbs.h"

// 005833e0: intern the name, remember the container, register in its verb map.
RBX::Verb::Verb(VerbContainer* container, std::string name)
    : name(Name::declare(name.c_str(), -1)), container(container) {
    container->verbs[&this->name] = this;
}

RBX::RunStateVerb::~RunStateVerb() {}
RBX::EditSelectionVerb::~EditSelectionVerb() {}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0> >;
template class std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >;
