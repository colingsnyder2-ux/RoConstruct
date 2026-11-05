// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}
namespace RBX {
class Obj;
struct Arg {
    void* a;
    void* b;
    boost::shared_ptr<Obj> p;
};
class Registry {
public:
    bool add(Arg a, void* out);
};
extern Registry registry;
class Holder {
public:
    Registry* owner;
    int pad;
    char item[4];
    void attach(Arg a);
};
void Holder::attach(Arg a)
{
    owner = registry.add(a, &item) ? &registry : 0;
}
}
