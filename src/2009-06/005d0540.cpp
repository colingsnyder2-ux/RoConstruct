// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <string>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
namespace boost {
namespace noncopyable_ { class noncopyable { protected: noncopyable() {} ~noncopyable() {} }; }
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
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
};
namespace detail { namespace function {
union any_pointer { void* obj_ptr; };
union function_buffer { double d; char data[0x18]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
    void clear(function_buffer& functor) { if (manager) manager(functor, functor, destroy_functor_tag); }
};
} }
class function_base {
public:
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
    function_base() : vtable(0) {}
};
template<class Sig> class function : public function_base {
public:
    function(const function& f) : function_base() { assign_to_own(f); }
    ~function() { clear(); }
    void assign_to_own(const function& f)
    {
        if (f.vtable) {
            this->vtable = f.vtable;
            this->vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
    void clear()
    {
        if (vtable) {
            vtable->clear(functor);
            vtable = 0;
        }
    }
};
}
namespace RBX {
class Instance;
template<class T> class Countable {
    static long count;
public:
    Countable() { InterlockedIncrement(&count); }
    ~Countable() { InterlockedDecrement(&count); }
};
}
extern void* const gDefault;
struct NP { void* p; NP() : p(0) {} };
namespace rbx { namespace signals {
class connection {
public:
    class slot : boost::noncopyable_::noncopyable, RBX::Countable<slot> {
    public:
        slot() : def(gDefault) {}
        virtual ~slot() {}
        struct BoolT { bool v; BoolT() : v(true) {} } connected;
        NP next;
        void* def;
    };
};
template<class Sig> class signal {
public:
    class slot : public connection::slot {
    public:
        slot(boost::function<Sig> f, void* owner) : owner(owner), func(f) {}
        virtual ~slot();
        void* owner;
        boost::function<Sig> func;
        boost::shared_ptr<void> p1;
        boost::shared_ptr<void> p2;
    };
};
template<class Sig> signal<Sig>::slot::~slot() {}
} }
template class rbx::signals::signal<void(boost::shared_ptr<RBX::Instance>)>::slot;
