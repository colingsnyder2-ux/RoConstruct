// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
// std::pair<const Guid::Data, std::vector<WaitItem> > destructor, standalone.
// VS2008 with _SECURE_SCL=0 (16-byte vector), not VS2005.
#include <vector>
#include <utility>
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
struct sp_counted_base {
    long use_count_; long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
struct shared_count {
    sp_counted_base* pi_;
    template<class Y> explicit shared_count(Y* p);
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
void sp_enable_shared_from_this(const shared_count&, ...);
template<class T> struct shared_ptr {
    T* px; shared_count pn;
    template<class Y> explicit shared_ptr(Y* p) : px(p), pn(p) { sp_enable_shared_from_this(pn, p, p); }
};
struct Instance;
struct Data { int scope; int index; };
struct WaitItem { void* desc; shared_ptr<Instance> instance; };
typedef std::pair<const Data, std::vector<WaitItem> > Entry;
void destroy(Entry* e) { e->~Entry(); }