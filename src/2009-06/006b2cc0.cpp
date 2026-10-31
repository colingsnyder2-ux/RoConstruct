// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
inline long atomic_increment(long* pw) { return _InterlockedIncrement(pw); }
inline long atomic_decrement(long* pw) { return _InterlockedDecrement(pw); }
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_add_ref() { atomic_increment(&weak_count_); }
    void weak_release() { if (atomic_decrement(&weak_count_) == 0) destroy(); }
    void release() { if (atomic_decrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
    template<class Y> weak_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
};
}
namespace RBX {
class PartInstance;
class ContactManager;
class World { public: char pad[0xb0]; ContactManager* contactManager; ContactManager* getContactManager() { return contactManager; } };
class RootInstance { public: char pad[0x150]; World* world; World* getWorld() { return world; } };
template<class T> boost::shared_ptr<T> shared_from(T* p);
class PartArray {
public:
    void* a; void* b; void* c; void* d;
    PartArray(const PartArray&);
    ~PartArray();
    char pad[8];
};
class MegaDragger {
public:
    boost::weak_ptr<PartInstance> mousePart;
    PartArray dragParts;
    bool joined;
    int extra;
    RootInstance* rootInstance;
    ContactManager* contactManager;
    MegaDragger(PartInstance* mousePartPtr, const PartArray& partArray, RootInstance* rootInstance, int extra);
};
MegaDragger::MegaDragger(PartInstance* mousePartPtr, const PartArray& partArray, RootInstance* rootInstance, int extra)
    : mousePart(shared_from(mousePartPtr)),
      dragParts(partArray),
      rootInstance(rootInstance),
      extra(extra),
      joined(true),
      contactManager(rootInstance->getWorld()->getContactManager())
{
}
}
