// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_; long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
};
template<int I> struct arg {};
namespace _bi {
template<class A1, class A2, class A3> struct list3 { A2 a2; A3 a3; };
template<class R, class F, class L> struct bind_t { F f; L l; };
}
template<class R, class B1, class B2, class B3, class A1, class A2, class A3>
_bi::bind_t<R, R (*)(B1, B2, B3), _bi::list3<A1, A2, A3> > bind(R (*f)(B1, B2, B3), A1 a1, A2 a2, A3 a3);
}
namespace { boost::arg<1> _1; }
namespace RBX {
class Instance;
typedef boost::_bi::bind_t<void, void (*)(boost::shared_ptr<Instance>, boost::shared_ptr<Instance>, boost::shared_ptr<Instance>),
    boost::_bi::list3<boost::arg<1>, boost::shared_ptr<Instance>, boost::shared_ptr<Instance> > > BT;
class Children {
public:
    void* p;
    void visit(BT f);
    static void doIt(boost::shared_ptr<Instance> d, boost::shared_ptr<Instance> a, boost::shared_ptr<Instance> b);
    void onChanged(boost::shared_ptr<Instance> a, boost::shared_ptr<Instance> b);
};
void Children::onChanged(boost::shared_ptr<Instance> a, boost::shared_ptr<Instance> b)
{
    visit(boost::bind(&Children::doIt, _1, a, b));
}
}
