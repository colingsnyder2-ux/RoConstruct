// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
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
    template<class Y> shared_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}
};
}
namespace RBX {
class GuidItemBase { public: virtual ~GuidItemBase(); int g[4]; };
template<class T> class AbstractFactoryProduct { public: virtual ~AbstractFactoryProduct(); };
class Instance : public GuidItemBase, public AbstractFactoryProduct<Instance> { public: virtual ~Instance(); };
template<class Base> class Creatable { public: template<class T> static boost::shared_ptr<T> create(); };
class Team : public Instance { public: Team(); };
template<class Class, class Base> class FactoryProduct {
public:
    class Creator {
    public:
        virtual boost::shared_ptr<AbstractFactoryProduct<Base> > create() const;
    };
};
template<class Class, class Base>
boost::shared_ptr<AbstractFactoryProduct<Base> > FactoryProduct<Class, Base>::Creator::create() const {
    return Creatable<Base>::template create<Class>();
}
template class FactoryProduct<Team, Instance>;
}
