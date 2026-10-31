// from server: 100% by EspClaude
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
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    shared_ptr() : px(0), pn(0) {}
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) { if (pn) _InterlockedIncrement(&pn->use_count_); }
    ~shared_ptr() { if (pn) pn->release(); }
    T* operator->() const { return px; }
    T* get() const { return px; }
};
template<class T, class U> shared_ptr<T> shared_static_cast(shared_ptr<U> const& r) throw();
template<class T> class enable_shared_from_this {
public:
    shared_ptr<T> shared_from_this();
};
}
namespace RBX {
class Pad { public: virtual ~Pad(); char p[0x20]; };
class Instance : public Pad, public boost::enable_shared_from_this<Instance> {};
class GuiItem : public Instance {};
template <class T>
boost::shared_ptr<T> shared_from(T* r)
{
    return r != 0 ? boost::shared_static_cast<T>(r->shared_from_this()) : boost::shared_ptr<T>();
}
template boost::shared_ptr<GuiItem> shared_from<GuiItem>(GuiItem*);
}
