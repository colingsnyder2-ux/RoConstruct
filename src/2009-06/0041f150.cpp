// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
struct sp_counted_base {
    virtual ~sp_counted_base();
    long use_count_; long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count();
};
template<class T> class shared_ptr {
public:
    T* px; shared_count pn;
};
struct T;
class X {
public:
    char pad[0x12c];
    shared_ptr<T> p;
    shared_ptr<T> get() const;
};
shared_ptr<T> X::get() const { return p; }
