// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Standalone boost::_bi list constructor: forwards its by-value arguments to the
// out-of-line base (storage) constructor; every argument is a class type by value (bind value<>/reference_wrapper<>), and the
// trailing one is not forwarded; the scalar-typed version reuses its dead stack slot instead.
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
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
struct shared_ptr { void* px; shared_count pn; };
struct Placeholder {};
struct Wrap { void* p; };
struct storage4 { storage4(shared_ptr a1, Wrap a2, Wrap a3, Wrap a4); };
struct storage5 : storage4 {
    storage5(shared_ptr a1, Wrap a2, Wrap a3, Wrap a4, Wrap a5) : storage4(a1, a2, a3, a4) {}
};
storage5 make(shared_ptr a1, Wrap a2, Wrap a3, Wrap a4, Wrap a5) { return storage5(a1, a2, a3, a4, a5); }