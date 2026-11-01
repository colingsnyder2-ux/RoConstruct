// from server: 92% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class Instance;
template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
};
struct Mutex { int m[4]; };
struct Lock { Lock(Mutex&); ~Lock(); Mutex* m; bool locked; };
struct Sig { void operator()(shared_ptr<Instance>); };
struct Adapter {
    char pad[5];
    bool enabled;
    char pad2[2];
    Mutex mutex;
    Sig sig;
    static void invoke(Adapter* a, shared_ptr<Instance> p);
};
void Adapter::invoke(Adapter* a, shared_ptr<Instance> p)
{
    Lock lock(a->mutex);
    if (a->enabled)
        a->sig(p);
}
