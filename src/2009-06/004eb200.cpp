// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    long use_count_; long weak_count_;
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(shared_count const& r);
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    template<class Y> shared_ptr& operator=(shared_ptr<Y> const& r) { px = r.px; pn = r.pn; return *this; }
    T* get() const { return px; }
};
struct once_flag { long epoch; };
void call_once(once_flag& flag, void (*f)());
}
namespace RBX {
class Instance {
public:
    void setParent(Instance* parent);
};
template<class Base> class Creatable {
public:
    template<class T> static boost::shared_ptr<T> create();
};
template<class T> struct ServiceIndex {
    static boost::once_flag flag;
    static size_t get();
    static void init() { get(); }
    static size_t index() { boost::call_once(flag, &init); return get(); }
};
class ServiceProvider : public Instance {
    char pad[0x8c];
    std::vector<boost::shared_ptr<Instance> > serviceArray;
public:
    template<class T> T* find();
    template<class T> T* create()
    {
        T* t = find<T>();
        if (t == 0) {
            boost::shared_ptr<T> s = Creatable<Instance>::create<T>();
            t = s.get();
            serviceArray[ServiceIndex<T>::index()] = s;
            t->setParent(this);
        }
        return t;
    }
};
class SomeService : public Instance {};
template SomeService* ServiceProvider::create<SomeService>();
}
