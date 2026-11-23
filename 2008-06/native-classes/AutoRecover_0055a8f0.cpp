// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "AppUnit558_2008/InstanceDescendantRemoving2008.h"
#include "v8tree/Instance.h"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

namespace G3D {
std::string format(const char* fmt, ...);
}

namespace RBX {

// 0055a8f0
void Instance::setParent(Instance* newParent)
{
    if (newParent == parent)
        return;

    if (this == newParent) {
        throw std::runtime_error(G3D::format("Attempt to set %s as its own parent", getFullName().c_str()));
    }

    if (isAncestorOf(newParent)) {
        // INFERRED: argument order (this, newParent) from the push order in the disassembly
        throw std::runtime_error(G3D::format("Attempt to set parent of %s to %s results in circular reference",
                                             getFullName().c_str(), newParent->getFullName().c_str()));
    }

    boost::shared_ptr<Instance> oldParent = shared_from(parent);
    boost::shared_ptr<Instance> self = shared_from_this();

    if (oldParent) {
        if (!oldParent->contains(newParent))
            signalDescendentRemoving(self, oldParent.get(), newParent);

        oldParent->onChildRemoving(this);

        boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& c = oldParent->children.write();
        c->erase(std::find(c->begin(), c->end(), self));

        if (c->empty())
            oldParent->children.reset();

        parent = NULL;

        event_childRemoved.fire(oldParent.get(), self);
        // INFERRED: ChildRemoved is built from a shared_ptr (disassembly calls shared_from(this) before raise)
        oldParent->Notifier<Instance, ChildRemoved>::raise(ChildRemoved(shared_from(this)));

        oldParent->onChildRemoved(this);

        if (oldParent->numChildren() == 0)
            oldParent->onLastChildRemoved();
    }

    if (newParent) {
        newParent->children.write()->push_back(self);
    }

    parent = newParent;

    if (newParent) {
        newParent->onChildAdded(this);

        if (!newParent->contains(oldParent.get()))
            signalDescendentAdded(this, newParent, oldParent.get());

        newParent->Notifier<Instance, ChildAdded>::raise(ChildAdded(this));

        // INFERRED: tail of the function is cut off in the disassembly; follows the 2007 analog
        event_childAdded.fire(newParent, self);
    }

    onAncestorChanged(AncestorChanged(this, oldParent.get(), newParent));
    raisePropertyChanged(propParent);
}

} // namespace RBX
