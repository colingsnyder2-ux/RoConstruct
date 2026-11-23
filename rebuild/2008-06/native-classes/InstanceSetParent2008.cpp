// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native Instance::setParent 0055a8f0 (inactive). Same shape as the 2007 donor Instance.cpp:420 (read for evidence only)
// plus the two argument checks the 2008 exe makes first: parent == this and isAncestorOf(newParent) (005574d0 getFullName,
// G3D::format 00509b10, std::runtime_error 00409d50, throw 006a158c).
#include "v8tree/Instance.h"
#include "v8tree/PropertyChanged.h"
#include <G3D/format.h>
#include <algorithm>
#include <stdexcept>

namespace RBX
{
	void Instance::setParent(Instance* newParent)
	{
		Instance* const currentParent = parent;
		if (newParent == currentParent)
			return;

		if (newParent == this)
		{
			const std::string message = G3D::format("Attempt to set %s as its own parent", getFullName().c_str());
			throw std::runtime_error(message);
		}
		if (isAncestorOf(newParent))
		{
			const std::string message = G3D::format("Attempt to set parent of %s to %s results in circular reference",
				getFullName().c_str(), newParent->getFullName().c_str());
			throw std::runtime_error(message);
		}

		boost::shared_ptr<Instance> oldParent = shared_from(currentParent);
		boost::shared_ptr<Instance> self = this->shared_from_this();

		if (oldParent)
		{
			if (!oldParent->contains(newParent))
				signalDescendentRemoving(self, oldParent.get(), newParent);

			oldParent->onChildRemoving(this);

			boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& c = oldParent->children.write();
			c->erase(std::find(c->begin(), c->end(), self));

			if (c->empty())
				oldParent->children.reset();

			parent = NULL;

			event_childRemoved.fire(oldParent.get(), self);
			oldParent->Notifier<Instance, ChildRemoved>::raise(ChildRemoved(this));

			oldParent->onChildRemoved(this);

			if (oldParent->numChildren() == 0)
				oldParent->onLastChildRemoved();
		}

		if (newParent)
			newParent->children.write()->push_back(self);

		parent = newParent;

		if (newParent)
		{
			newParent->onChildAdded(this);

			if (!newParent->contains(oldParent.get()))
				signalDescendentAdded(this, newParent, oldParent.get());

			newParent->Notifier<Instance, ChildAdded>::raise(ChildAdded(this));
			event_childAdded.fire(newParent, self);
		}

		onAncestorChanged(AncestorChanged(this, oldParent.get(), newParent));
		raisePropertyChanged(propParent);
	}
}
