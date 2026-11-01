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
struct IUnknownLike {
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
template<class T> struct ComPtr {
    T* p;
    ~ComPtr() { if (p) p->Release(); }
};
struct Poly { virtual ~Poly(); };
struct Plain { ~Plain(); };
struct TableLike { ~TableLike(); };
struct Obj;
class DialogBase { public: virtual ~DialogBase(); char pad[0x50]; };
class Iface54 { public: virtual void i54(); };
class Base58 { public: ~Base58(); char pad[0x40]; };
class S : public DialogBase, public Iface54, public Base58 {
public:
    ~S();
    void reset(int);
    boost::shared_ptr<Obj> m98;
    boost::shared_ptr<Obj> ma0;
    boost::shared_ptr<Obj> ma8;
    int mb0, mb4;
    boost::shared_ptr<Obj> mb8;
    boost::shared_ptr<Obj> mc0;
    ComPtr<IUnknownLike> mc8;
    boost::shared_ptr<Obj> mcc;
    int md4;
    boost::scoped_ptr<Plain> md8;
    int mdc;
    boost::scoped_ptr<Poly> me0;
    int me4, me8, mec, mf0;
    boost::scoped_ptr<TableLike> mf4;
    boost::scoped_ptr<Poly> mf8;
    boost::scoped_ptr<Poly> mfc;
};
S::~S()
{
    reset(0);
}
