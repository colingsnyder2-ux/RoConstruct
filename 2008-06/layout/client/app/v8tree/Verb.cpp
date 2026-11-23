#include "v8tree/Verb.h"
#include "util/Name.h"

namespace RBX
{
	VerbContainer::~VerbContainer()
	{
		while (verbs.begin() != verbs.end())
		{
			delete verbs.begin()->second;
		}
	}

	Verb* VerbContainer::getVerb(std::string name)
	{
		return getVerb(Name::lookup(name));
	}

	Verb* VerbContainer::getVerb(const Name& name)
	{
		if (Name::getNullName() == name)
			return NULL;

		std::map<const Name*, Verb*>::iterator iter = verbs.find(&name);

		if (iter != verbs.end())
			return iter->second;

		if (!parent)
			return NULL;

		return parent->getVerb(name);
	}
}

#include "StandardVerbs.h"

RBX::Verb::Verb(VerbContainer* container, std::string name)
    : name(Name::declare(name.c_str(), -1)), container(container) {
    container->verbs[&this->name] = this;
}

template class std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,RBX::Verb *,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >,0> >;
template class std::allocator<std::pair<RBX::Name const * const,RBX::Verb *> >;

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
