// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(shared_count const& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr& operator=(shared_ptr const& r) { px = r.px; pn = r.pn; return *this; }
    T* get() const { return px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};
}
namespace rbx { namespace signals {
class connection {
public:
    ~connection();
    void disconnect() const;
    bool operator!=(const connection& other) const;
    connection& operator=(const connection& other);
    void* a; void* b; void* c; void* d;
};
class scoped_connection : public connection {
public:
    ~scoped_connection() { disconnect(); }
    scoped_connection& operator=(const connection& other)
    {
        if (*this != other) {
            disconnect();
            connection::operator=(other);
        }
        return *this;
    }
};
} }
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class Instance;
template<class T> struct value { T t_; };
struct arg1 {};
template<class A1, class A2> struct list2 { A1 a1_; A2 a2_; };
template<class F, class L> struct bind_t { F f_; L l_; };
template<class Sig> class Signal {
public:
    template<class F> rbx::signals::connection connect(F f);
};
class Part {
public:
    char pad[0x84];
    Signal<void(boost::shared_ptr<Instance>)> touched;
};
template<class T> boost::shared_ptr<T> shared_from(T* p);
extern const Reflection::PropertyDescriptor prop_Handle;
class Base1 { public: virtual ~Base1(); };
class Base2 { public: virtual ~Base2(); };
class Holder : public Base1, public Base2 {
public:
    char pad[0xb0 - 8];
    boost::shared_ptr<Part> part;
    rbx::signals::scoped_connection conn;
    void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
    void update(int a, Part* p);
    void onTouched(boost::shared_ptr<Instance> other);
    void setPart(Part* value);
};
typedef void (Holder::*Callback)(boost::shared_ptr<Instance>);
inline bind_t<Callback, list2<value<Holder*>, arg1> > bindIt(Callback f, Holder* h, arg1 a)
{
    bind_t<Callback, list2<value<Holder*>, arg1> > b;
    b.f_ = f; b.l_.a1_.t_ = h; b.l_.a2_ = a;
    return b;
}
void Holder::setPart(Part* value)
{
    if (value == part.get())
        return;
    part = shared_from(value);
    raisePropertyChanged(prop_Handle);
    update(1, part.get());
    if (Part* p = part.get())
        conn = p->touched.connect(bindIt(&Holder::onTouched, this, arg1()));
    else
        conn.disconnect();
}
}
