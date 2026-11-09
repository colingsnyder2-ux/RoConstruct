// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_instance_predelete_774736f7fbf4a3d4.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Instance.h"

#include <algorithm>

namespace RBX {

inline ChildRemoved::ChildRemoved(Instance* child)
    : child(shared_from(child))
{
}

// The body is the authentic November 2007 RBXGS implementation.  It is emitted
// against the later OpenRBX class declaration, whose virtual ordering matches
// the 2008-06 target (onAncestorChanged +0x10, onChildRemoving +0x20).
void Instance::predelete()
{
    while (children) {
        boost::shared_ptr<Instance> child;

        {
            boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > c = children.write();

            child = *(c->end() - 1);

            signalDescendentRemoving(child, this, NULL);

            this->onChildRemoving(child.get());
            child->parent = NULL;
            c->pop_back();

            if (c->empty()) {
                children.reset();
            }
        }

        event_childRemoved.fire(this, child);
        Notifier<Instance, ChildRemoved>::raise(ChildRemoved(child.get()));

        child->onAncestorChanged(AncestorChanged(child.get(), this, NULL));
        child->raisePropertyChanged(propParent);
    }
}

} // namespace RBX
