// from server: 100% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
#include <set>
#include <algorithm>

extern "C" __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);

namespace boost {
struct lock_error { lock_error(); };
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    void reset();
    T* get() const { return px; }
    T* operator->() const { return px; }
    T& operator*() const { return *px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

class recursive_mutex {
public:
    void do_lock();
    void do_unlock();
    void* m_mutex;
    bool m_critical_section;
    unsigned long m_count;
};
template<class M> class scoped_lock {
public:
    explicit scoped_lock(M& mx) : m_mutex(mx), m_locked(false) { lock(); }
    ~scoped_lock() { if (m_locked) unlock(); }
    void lock() { if (m_locked) throw lock_error(); m_mutex.do_lock(); m_locked = true; }
    void unlock() { if (!m_locked) throw lock_error(); m_mutex.do_unlock(); m_locked = false; }
    M& m_mutex;
    bool m_locked;
};
}

namespace RBX {
template<class A, class B> class Listener { public: virtual void onEvent(const A*, B) = 0; };
template<class A, class B> class Notifier {
public:
    void addListener(Listener<A, B>* l) const;
    void removeListener(Listener<A, B>* l) const;
    char pad[0x20];
};
struct E1 {};
class Instance;
struct PadI { char pad0[0x130]; };
class Instance : public PadI, public Notifier<Instance, E1> {
public:
    int pad150;
    std::vector<boost::shared_ptr<Instance> >* children;
};
template<class C, class E, class P> inline void removeL(const boost::shared_ptr<P>& p, Listener<C, E>* l)
{ if (p) p->Notifier<C, E>::removeListener(l); }
template<class C, class E, class P> inline void addL(const boost::shared_ptr<P>& p, Listener<C, E>* l)
{ if (p) p->Notifier<C, E>::addListener(l); }
template<class T> boost::shared_ptr<T> shared_from(T* p);
}

template<int I> struct arg {};
static arg<1> _1;
template<class C> struct bind_t {
    typedef void (C::*F)(boost::shared_ptr<RBX::Instance>);
    F f;
    C* p;
    arg<1> a;
    bind_t(F f_, C* p_, arg<1> a_) : f(f_), p(p_), a(a_) {}
    void operator()(boost::shared_ptr<RBX::Instance> i) { (p->*f)(i); }
};
template<class C> inline bind_t<C> bind(void (C::*f)(boost::shared_ptr<RBX::Instance>), C* p, arg<1> a2)
{
    return bind_t<C>(f, p, a2);
}

class PadA { public: virtual ~PadA(); char pad0[0x1c]; void* m_hWnd; char pad1[0x18c - 0x24];
public:
    boost::recursive_mutex mutex;   // 0x18c
    char pad2[0x1f4 - 0x198];
    bool posted;                    // 0x1f4
    bool dirty;                     // 0x1f5
    std::set<int> set1;             // 0x1f8
    std::set<void*> set2;           // 0x218
};

class CSelectionPropGrid : public PadA, public RBX::Listener<RBX::Instance, RBX::E1>
{
public:
    boost::shared_ptr<RBX::Instance> instance; // 0x23c? 
    void onChildRemoved(boost::shared_ptr<RBX::Instance> i);
    void onChildAdded(boost::shared_ptr<RBX::Instance> i);
    void setInstance(RBX::Instance* inst);
};

void CSelectionPropGrid::setInstance(RBX::Instance* inst)
{
    boost::scoped_lock<boost::recursive_mutex> lock(mutex);
    if (instance) {
        RBX::removeL<RBX::Instance, RBX::E1>(instance, this);
        std::for_each(instance->children->begin(), instance->children->end(), bind(&CSelectionPropGrid::onChildRemoved, this, _1));
    }
    set1.clear();
    set2.clear();
    instance = RBX::shared_from(inst);
    if (instance) {
        std::for_each(instance->children->begin(), instance->children->end(), bind(&CSelectionPropGrid::onChildAdded, this, _1));
        RBX::addL<RBX::Instance, RBX::E1>(instance, this);
    }
    dirty = true;
    {
        boost::scoped_lock<boost::recursive_mutex> lock2(mutex);
        if (!posted) {
            if (m_hWnd)
                PostMessageA(m_hWnd, 0x465, 0, 0);
            posted = true;
        }
    }
}
