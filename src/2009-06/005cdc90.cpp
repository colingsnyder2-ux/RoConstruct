// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) { destroy(); } }
};
}
template<class T> class shared_ptr {
public:
    typedef T* shared_ptr::*unspecified_bool_type;
    T* px;
    detail::sp_counted_base* pn;
    ~shared_ptr() { if (pn != 0) pn->release(); }
    T* operator->() const { return px; }
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};
}
namespace RBX {
class Instance {
public:
    char pad[0x48];
    Instance* parent;
    bool isAncestorOf(const Instance* descendent) const;
    bool isAncestorOf2(boost::shared_ptr<Instance> descendent) const;
    bool isDescendentOf(const Instance* ancestor) const
    {
        if (parent == ancestor) return true;
        return ancestor->isAncestorOf(parent);
    }
};
bool Instance::isAncestorOf2(boost::shared_ptr<Instance> descendent) const
{
    return !descendent ? false : descendent->isDescendentOf(this);
}
}
