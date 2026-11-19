// native-flags: /O2 /GS- /EHsc /MD
//
// RBX::Instance recovery for 2008-06, two byte-exact members in one unit:
//   00559350  ?sub_00559350@Instance@RBX@@QAE?AUResult@@XZ   (name unknown; 28-byte sret)
//   0055a8f0  ?setParent@Instance@RBX@@QAEXPAV12@@Z
//
// The canonical rebuild/2008-06/native-headers/v8tree/Instance.h is locked by another
// worker. This leased, task-owned copy of the native header carries the required
// `// INFERRED:` declarations until the canonical header merge can be applied:
//   Result, shared_from_out_of_line, isAncestorOf, signalDescendentRemoving/Added.
#include "../../../work/native-client/lane-drafts/class_RBX_Instance/v8tree/Instance.h"
#include <G3D/format.h>
#include <stdexcept>
#include <algorithm>

// ---------------------------------------------------------------------------
// 00559350 local codegen helpers. These are not stand-ins for RBX::Instance:
// they are the XML root child list and the 28-byte value returned by 00559250.
// ---------------------------------------------------------------------------
struct Node {
    Node* next;
};

struct List {
    Node* first;
    Node* last;
    void add(Node* node)
    {
        if (!last)
            first = node;
        else
            last->next = node;
        last = node;
    }
};

struct Root {
    int reserved;
    List children;
    ~Root();
};

struct Result {
    char storage[28];
    ~Result();
};

extern Root* __cdecl makeRoot();
extern Result __cdecl convertRoot(Root*);
void __cdecl operator delete(void*);

struct Owner {
    Root* pointer;
    explicit Owner(Root* p);
    ~Owner();
};

inline Owner::Owner(Root* p)
    : pointer(p)
{
}

inline Owner::~Owner()
{
    delete pointer;
}

Result RBX::Instance::sub_00559350()
{
    Root* root = makeRoot();
    Node* node = reinterpret_cast<Node*>(write());
    root->children.add(node);

    Owner owner(root);
    return convertRoot(root);
}

// ---------------------------------------------------------------------------
// 0055a8f0 setParent helpers. ChildAdded/ChildRemoved mirror the canonical
// v8tree/InstanceEvents.h single-shared_ptr layout; the local header only
// forward-declares them.
// ---------------------------------------------------------------------------
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
