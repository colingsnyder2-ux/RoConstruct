// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Instance::clone 00559350 and setParent 0055a8f0 drafts (inactive), rows of the v8tree/Instance.cpp
// unit (AppUnit558_2008Instance.cpp holds the rest; flags are that unit's defaults). Batch 32 replaced the former body
// of this file: it included work/native-client/lane-drafts/class_RBX_Instance/v8tree/Instance.h, which no longer
// exists (every prove compiled nothing), and spelled 00559350 as a placeholder `sub_00559350` returning a 28-byte
// struct. 00559350 is ?clone@Instance@RBX@@QAE?AV?$shared_ptr@VInstance@RBX@@@boost@@XZ (registry; callers
// Flag::doUglyPeriodicCloneHack 00618f70 and the PlayerCharacter backpack copy): SerializerV2::newRootElement 00591a30,
// write() (vtable +0x38), the inline XmlElement::addChild (Parent list first +4 / last +8), func_00559250 =
// Instance::fromXmlRoot (static; ArchiveBinder 00593480 + SerializerV2::loadInstances 00593250 into a vector, front or
// empty; openrbx v8tree/Instance.cpp fromXmlRoot), then `delete root` (~XmlElement 00413a70, operator delete).
//
// Both bodies are guarded. clone needs `static boost::shared_ptr<Instance> fromXmlRoot(::XmlElement*); // 00559250` in
// the core v8tree/Instance.h (proposal). Measured batch 32 against a scratch copy of that header with the declaration:
// 00559350 IDENTICAL (relocs masked, 149 B).
#include "v8tree/Instance.h"
#include "v8xml/SerializerV2.h"
#include <boost/scoped_ptr.hpp>

#ifdef NATIVE_INSTANCE_FROMXMLROOT_DECLARED
namespace RBX {
// INFERRED: the donor's inline Instance::toNewXmlRoot(Instance*) (openrbx v8tree/Instance.cpp), file-local because the
// core header does not declare it; it is inlined into clone in the target.
static inline XmlElement* toNewXmlRoot(Instance* instance)
{
    XmlElement* root = SerializerV2::newRootElement();
    root->addChild(instance->write());
    return root;
}

// 00559350
boost::shared_ptr<Instance> Instance::clone()
{
    boost::scoped_ptr<XmlElement> root(toNewXmlRoot(this));
    return fromXmlRoot(root.get());
}
}
#endif

// 0055a8f0 setParent: the earlier draft, kept guarded. It needs declarations the core v8tree/Instance.h lacks
// (isAncestorOf 004c9c50, signalDescendentAdded 00558220, signalDescendentRemoving 00558370, an out-of-line
// shared_from) and the ChildAdded / ChildRemoved payload definitions; see the batch 31 Instance.h proposal.
#ifdef NATIVE_INSTANCE_SETPARENT_DECLARED
#include <G3D/format.h>
#include <stdexcept>
#include <algorithm>
namespace RBX {

// INFERRED: 0055a8f0 raises ChildAdded; mirror of the canonical layout.
struct ChildAdded {
    const boost::shared_ptr<Instance> child;
    ChildAdded(Instance* value) : child(shared_from_out_of_line(value)) {}
    ChildAdded(const ChildAdded&); // 004116f0
};

// INFERRED: 0055a8f0 raises ChildRemoved; same single-shared_ptr layout.
struct ChildRemoved {
    const boost::shared_ptr<Instance> child;
    ChildRemoved(Instance* value) : child(shared_from_out_of_line(value)) {}
    ChildRemoved(const ChildRemoved&); // 004116f0
};

// INFERRED: the original TU had this inline; defining it here lets the optimizer
// keep oldParent in ECX across the `contains` call in setParent (byte-exact codegen).
bool Instance::contains(const Instance* child) const
{
    while (child) {
        if (child == this)
            return true;
        child = child->parent;
    }
    return false;
}

void Instance::setParent(Instance* newParent)
{
    Instance* previousParent = parent;
    if (newParent == previousParent)
        return;
    if (this == newParent) {
        std::string message = G3D::format("Attempt to set %s as its own parent", getFullName().c_str());
        throw std::runtime_error(message);
    }
    if (isAncestorOf(newParent)) {
        std::string message = G3D::format("Attempt to set parent of %s to %s results in circular reference",
                                          getFullName().c_str(), newParent->getFullName().c_str());
        throw std::runtime_error(message);
    }
    boost::shared_ptr<Instance> oldParent = shared_from_out_of_line(previousParent);
    boost::shared_ptr<Instance> self = shared_from_this();
    if (oldParent) {
        if (!oldParent->contains(newParent))
            signalDescendentRemoving(self, oldParent.get(), newParent);
        oldParent->onChildRemoving(this);
        boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& c = oldParent->children.write();
        c->erase(std::find(c->begin(), c->end(), self));
        if (c->size() == 0)
            oldParent->children.reset();
        parent = 0;
        event_childRemoved.fire(oldParent.get(), self);
        oldParent->Notifier<Instance, ChildRemoved>::raise(ChildRemoved(this));
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
        newParent->Notifier<Instance, ChildAdded>::raise(ChildAdded(this));
        event_childAdded.fire(newParent, self);
    }
    onAncestorChanged(AncestorChanged(this, oldParent.get(), newParent));
    raisePropertyChanged(propParent);
}

} // namespace RBX
#endif
