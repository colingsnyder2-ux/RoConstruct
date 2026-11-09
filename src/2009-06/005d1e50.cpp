// from server: 82% by EspClaude
// roc 2009-06 005d1e50  unit: RBX::Instance::setParent  size: 1018 bytes
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
namespace boost {
template<class T> class shared_ptr {
public:
    T* px;
    void* pn;
    shared_ptr(const shared_ptr& r);
    ~shared_ptr();
    shared_ptr& operator=(const shared_ptr& r);
    void reset();
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
namespace G3D { std::string __cdecl format(const char*, ...); }
namespace RBX {
class Instance;
namespace Reflection { class PropertyDescriptor { int x; }; }
template<class T> class CopyOnWrite {
public:
    boost::shared_ptr<T> object;
    boost::shared_ptr<T>& write();
    void reset() { object.reset(); }
};
template<class T> class ExeESFT {
public:
    void* wpx;
    void* wpn;
    boost::shared_ptr<T> shared_from_this();
};
class ChildSignal {
public:
    void* impl;
    void operator()(boost::shared_ptr<Instance> child);
};
struct AncestorChanged {
    Instance* const child;
    Instance* const oldParent;
    Instance* const newParent;
    AncestorChanged(Instance* c, Instance* o, Instance* n) : child(c), oldParent(o), newParent(n) {}
};
template<class T> boost::shared_ptr<T> __cdecl shared_from(T*);
typedef std::vector<boost::shared_ptr<Instance> > Children;
class Instance {
public:
    virtual ~Instance();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void onAncestorChanged(const AncestorChanged&);
    virtual void v8();
    virtual void v9();
    virtual void onChildAdded(Instance*);
    virtual void onChildRemoving(Instance*);
    virtual void onChildRemoved(Instance*);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void onLastChildRemoved();
    char pad4[0x20];
    ExeESFT<Instance> esft;
    char pad2c[0x1c];
    Instance* parent;
    CopyOnWrite<Children> children;
    std::string name;
    char pad70;
    bool lockedParent;
    char pad72[2];
    ChildSignal childAddedSignal;
    ChildSignal childRemovedSignal;
    static const Reflection::PropertyDescriptor propParent;
    std::string getFullName() const;
    bool isAncestorOf(const Instance*) const;
    bool contains(const Instance* child) const;
    int numChildren() const;
    static void signalDescendentRemoving(const boost::shared_ptr<Instance>&, Instance*, Instance*);
    static void signalDescendentAdded(Instance*, Instance*, Instance*);
    void raisePropertyChanged(const Reflection::PropertyDescriptor&);
    void setParent(Instance*);
};
}
namespace std {
template<> RBX::Children::iterator RBX::Children::begin();
template<> RBX::Children::iterator RBX::Children::end();
template<> RBX::Children::reference RBX::Children::back();
template<> void RBX::Children::pop_back();
template<> void RBX::Children::clear();
template<> RBX::Children::iterator RBX::Children::erase(RBX::Children::const_iterator);
template<> void RBX::Children::push_back(const boost::shared_ptr<RBX::Instance>&);
template<> RBX::Children::iterator find(RBX::Children::iterator, RBX::Children::iterator, const boost::shared_ptr<RBX::Instance>&);
template<> RBX::Children::iterator::reference RBX::Children::iterator::operator*() const;
}
namespace RBX {
void Instance::setParent(Instance* newParent)
{
    Instance* previousParent = parent;
    if (previousParent == newParent)
        return;
    if (lockedParent)
    {
        std::string message = G3D::format("The Parent property of %s is locked", getFullName().c_str());
        throw std::runtime_error(message);
    }
    if (this == newParent)
    {
        std::string message = G3D::format("Attempt to set %s as its own parent", getFullName().c_str());
        throw std::runtime_error(message);
    }
    if (isAncestorOf(newParent))
    {
        std::string message = G3D::format("Attempt to set parent of %s to %s results in circular reference", getFullName().c_str(), newParent->getFullName().c_str());
        throw std::runtime_error(message);
    }
    boost::shared_ptr<Instance> oldParent = shared_from(previousParent);
    boost::shared_ptr<Instance> self = esft.shared_from_this();
    if (oldParent)
    {
        if (!oldParent->contains(newParent))
            signalDescendentRemoving(self, oldParent.get(), newParent);
        oldParent->onChildRemoving(this);
        boost::shared_ptr<Children>& c = oldParent->children.write();
        if (c->size() == 1)
        {
            c->clear();
            oldParent->children.reset();
        }
        else
        {
            Children::iterator iter = std::find(c->begin(), c->end(), self);
            if (c->size() > 20)
            {
                *iter = c->back();
                c->pop_back();
            }
            else
                c->erase(iter);
        }
        parent = 0;
        oldParent->childRemovedSignal(self);
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
        newParent->childAddedSignal(self);
    }
    onAncestorChanged(AncestorChanged(this, oldParent.get(), newParent));
    raisePropertyChanged(propParent);
}
}
