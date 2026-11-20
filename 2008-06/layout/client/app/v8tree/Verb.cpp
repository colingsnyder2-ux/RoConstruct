#include "v8tree/Verb.h"

RBX::Verb::~Verb()
{
    if (container) container->verbs.erase(&name);
}

template class std::pair<std::_Tree<std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0> >::iterator,std::_Tree<std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0> >::iterator>;

#include "v8tree/VerbContainer.h"

RBX::VerbContainer::VerbContainer(VerbContainer* parent) : parent(parent) {}

void RBX::VerbContainer::setVerbParent(VerbContainer* parent)
{
    this->parent = parent;
}

template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> > >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0> >::_Node *>;
template class std::map<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> > >;
