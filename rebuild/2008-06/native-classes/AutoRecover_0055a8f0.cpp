// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0055a8f0 RBX::Instance::setParent (2008-06)
#include "AppUnit558_2008/InstanceDescendantRemoving2008.h"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>
#include <boost/bind.hpp>

namespace G3D {
std::string format(const char* fmt, ...);
}

namespace RBX {
void Instance::setParent(Instance* newParent)
{
    if (newParent == parent)
        return;

    if (this == newParent) {
        // INFERRED: message and runtime_error throw from the string literals at 0082d908 / 008d1bc8
        throw std::runtime_error(G3D::format("Attempt to set %s as its own parent", getFullName().c_str()));
    }

    if (isAncestorOf(newParent)) {
        std::string parentName = newParent->getFullName();
        std::string selfName = getFullName();
        throw std::runtime_error(G3D::format("Attempt to set parent of %s to %s results in circular reference",
                                             selfName.c_str(), parentName.c_str()));
    }

    boost::shared_ptr<Instance> oldParent = shared_from(parent);
    boost::shared_ptr<Instance> self = shared_from_this();

    if (oldParent) {
        if (!oldParent->contains(newParent))
            signalDescendentRemoving(self, oldParent.get(), newParent);

        oldParent->onChildRemoving(this);

        boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& c = oldParent->children.write();
        c->erase(std::find(c->begin(), c->end(), self));

        if (c->size() == 0)
            oldParent->children.reset();

        parent = NULL;

        event_childRemoved.fire(oldParent.get(), self);
        // INFERRED: ChildRemoved carries a shared_ptr (disasm calls shared_from(this) before raise)
        oldParent->Notifier<Instance, ChildRemoved>::raise(ChildRemoved(shared_from(this)));
        oldParent->onChildRemoved(this);

        if (oldParent->numChildren() == 0)
            oldParent->onLastChildRemoved();
    }

    if (newParent)
        newParent->children.write()->push_back(self);

    parent = newParent;

    if (newParent) {
        newParent->onChildAdded(this);

        if (!newParent->contains(oldParent.get()))
            signalDescendentAdded(this, newParent, oldParent.get());

        newParent->Notifier<Instance, ChildAdded>::raise(ChildAdded(shared_from(this)));
        event_childAdded.fire(newParent, self);
    }

    onAncestorChanged(AncestorChanged(this, oldParent.get(), newParent));
    raisePropertyChanged(propParent);
}
} // namespace RBX
