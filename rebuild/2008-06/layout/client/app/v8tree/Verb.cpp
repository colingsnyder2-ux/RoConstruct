#include "v8tree/Verb.h"
#include "StandardVerbs.h"

RBX::Verb::Verb(VerbContainer* container, std::string name)
    : name(Name::declare(name.c_str(), -1)), container(container) {
    container->verbs[&this->name] = this;
}

RBX::RunStateVerb::~RunStateVerb() {}
RBX::EditSelectionVerb::~EditSelectionVerb() {}

template class std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0> >;
template class std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >;
