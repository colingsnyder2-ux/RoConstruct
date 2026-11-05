// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <intrin.h>
struct sp_counted_base { void* vt; long use_count_; long weak_count_; };
struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count();
};
struct SP { void* px; shared_count pn; };
struct Inner { std::string s; SP p; ~Inner(); };
struct Arg { int a; Inner i; };
struct Base { Base(Arg a, int n); };
struct X : Base { X(Arg a, int); };
X::X(Arg a, int) : Base(a, 0) {}
