// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}
class A; class B;
class LevelGenFunc {
public:
    virtual void slot0();
    int count;
    LevelGenFunc(int c) : count(c) {}
};
class BuilderLevelGenFunc : public LevelGenFunc {
public:
    int zero;
    float value;
    boost::shared_ptr<A> first;
    boost::shared_ptr<B> second;
    BuilderLevelGenFunc(const boost::shared_ptr<A>& a, const boost::shared_ptr<B>& b, int c);
    virtual void slot0();
};
BuilderLevelGenFunc::BuilderLevelGenFunc(const boost::shared_ptr<A>& a, const boost::shared_ptr<B>& b, int c) : LevelGenFunc(c), zero(0), value(0.0f), first(a), second(b) {}

