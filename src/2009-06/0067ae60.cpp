// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
inline long atomic_decrement(long* pw) { return _InterlockedDecrement(pw); }
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_release() { if (atomic_decrement(&weak_count_) == 0) destroy(); }
    void release() { if (atomic_decrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
template<class T> class scoped_ptr {
public:
    T* px;
    ~scoped_ptr() { delete px; }
};
}
namespace RBX {
class Sky { public: ~Sky(); int x; };
class Thing;
struct B0 { virtual ~B0() {} char pad[0x10]; };
struct B1 { virtual ~B1() {} };
struct B2 { virtual ~B2() {} int x; };
struct B3 { virtual ~B3() {} };
class Instance : public B0, public B1, public B2, public B3 {
public:
    virtual ~Instance();
    char pad[0x234 - 0x24];
};
template<class T> class FactoryProduct : public Instance {
public:
    virtual ~FactoryProduct() {}
};
class __declspec(novtable) Lighting : public FactoryProduct<Lighting> {
public:
    boost::scoped_ptr<Sky> sky;
    boost::shared_ptr<Thing> thing;
    ~Lighting();
};
Lighting::~Lighting() {}
}
