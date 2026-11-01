// from server: 100% by EspClaude
// roc 2009-06 005d3740  size: 245 bytes
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count();
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}
struct A; struct B;
struct F { int f; };
struct L {
    boost::shared_ptr<A> a;
    boost::shared_ptr<B> b;
    ~L();
};
struct T {
    L l;
    T(F f, L l);
};
struct Result {
    int id;
    T t;
    Result(int i, const T& v) : id(i), t(v) {}
};
Result make(int id, F f, L l)
{
    return Result(id, T(f, l));
}
