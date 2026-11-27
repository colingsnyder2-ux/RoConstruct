// from server: 90% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0

#include <vector>
#include <string>
#include <algorithm>
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement, _InterlockedIncrement)
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base(); virtual void dispose(); virtual void destroy();
    long use_count_; long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    template <class Y> explicit shared_count(Y* p);
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
inline void sp_enable_shared_from_this(shared_count const&, ...) {}
}
template <class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    template <class Y> explicit shared_ptr(Y* p) : px(p), pn(p)
    { detail::sp_enable_shared_from_this(pn, p, p); }
    template <class Y> shared_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
    T& operator*() const { return *px; }
};
}
namespace RBX {
class Instance;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
struct ContentId { std::string id; int extra; };
void append(const boost::shared_ptr<Instance>& item, Instances* values);
template <class F, class A2> struct bind_t {
    F f_; A2 a2_;
    bind_t(F f, A2 a2) : f_(f), a2_(a2) {}
    template <class A1> void operator()(A1& a1) { f_(a1, a2_); }
    template <class A1> void operator()(A1 const& a1) { f_(a1, a2_); }
};
template <class F, class A2> bind_t<F, A2> bind(F f, A2 a2) { return bind_t<F, A2>(f, a2); }
class Workspace {
public:
    void loadContent(ContentId id, Instances& instances, bool a, bool b);
    boost::shared_ptr<const Instances> insertContent(ContentId contentId);
};
boost::shared_ptr<const Instances> Workspace::insertContent(ContentId contentId)
{
    Instances instances;
    loadContent(contentId, instances, true, true);
    boost::shared_ptr<Instances> result(new Instances());
    std::for_each(instances.begin(), instances.end(), bind(&append, result.px));
    return result;
}
}
