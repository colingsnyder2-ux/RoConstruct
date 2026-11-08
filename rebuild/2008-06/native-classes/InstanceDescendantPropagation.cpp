// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// InstanceDescendantPropagation | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 6039f8fd | roc native-status --write
#include "v8tree/Instance.h"
namespace RBX {
	void Instance::signalDescendentAdded(Instance* instance, Instance* beginParent, Instance* oldParent)
	{
		for (Instance* parent = beginParent; parent != NULL; parent = parent->getParent())
		{
			if (parent == oldParent || parent->isAncestorOf(oldParent))
				break;

			parent->onDescendentAdded(instance);
		}

		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = instance->children.read();

		if (c)
		{
			for (std::vector<boost::shared_ptr<Instance>>::const_iterator iter = c->begin(); iter != c->end(); iter++)
			{
				signalDescendentAdded((*iter).get(), beginParent, oldParent);
			}
		}
	}

	void Instance::signalDescendentRemoving(const boost::shared_ptr<Instance>& instance, Instance* beginParent, Instance* newParent)
	{
		for (Instance* parent = beginParent; parent != NULL; parent = parent->getParent())
		{
			if (parent == newParent || parent->isAncestorOf(newParent))
				break;

			parent->onDescendentRemoving(instance);
		}

		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = instance->children.read();

		if (c)
		{
			for (std::vector<boost::shared_ptr<Instance>>::const_iterator iter = c->begin(); iter != c->end(); iter++)
			{
				signalDescendentRemoving((*iter), beginParent, newParent);
			}
		}
	}

}
