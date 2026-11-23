// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native (inactive): Instance::isAncestorOf 004c9c50, signalDescendentAdded 00558220 and signalDescendentRemoving
// 00558370. Same shape as the 2007 donor Instance.cpp:343/364 (read for evidence only): walk from the new/old parent up to the
// first ancestor that is also an ancestor of the other parent, notifying each, then recurse into the children.
#include "v8tree/Instance.h"

namespace RBX
{
	bool Instance::isAncestorOf(const Instance* descendent) const
	{
		if (descendent)
		{
			do
			{
				descendent = descendent->parent;
				if (descendent == this)
					return true;
			} while (descendent);
		}
		return false;
	}

	void Instance::signalDescendentAdded(Instance* instance, Instance* beginParent, Instance* oldParent)
	{
		for (Instance* p = beginParent; p != NULL; p = p->parent)
		{
			if (p == oldParent || p->isAncestorOf(oldParent))
				break;
			p->onDescendentAdded(instance);
		}

		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = instance->children.read();
		if (c)
		{
			for (std::vector<boost::shared_ptr<Instance> >::const_iterator iter = c->begin(); iter != c->end(); iter++)
				signalDescendentAdded((*iter).get(), beginParent, oldParent);
		}
	}

	void Instance::signalDescendentRemoving(const boost::shared_ptr<Instance>& instance, Instance* beginParent, Instance* newParent)
	{
		for (Instance* p = beginParent; p != NULL; p = p->parent)
		{
			if (p == newParent || p->isAncestorOf(newParent))
				break;
			p->onDescendentRemoving(instance);
		}

		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = instance->children.read();
		if (c)
		{
			for (std::vector<boost::shared_ptr<Instance> >::const_iterator iter = c->begin(); iter != c->end(); iter++)
				signalDescendentRemoving(*iter, beginParent, newParent);
		}
	}
}
