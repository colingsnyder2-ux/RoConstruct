// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost {
namespace noncopyable_ {
class noncopyable {
protected:
    noncopyable() {}
    ~noncopyable() {}
private:
    noncopyable(const noncopyable&);
    const noncopyable& operator=(const noncopyable&);
};
}
typedef noncopyable_::noncopyable noncopyable;
namespace detail { namespace function {
union function_buffer {
    void* obj_ptr;
    double align;
    char data[16];
};
struct vtable_base {
    void (*manager)(const function_buffer& in, function_buffer& out, int op);
};
} }
template<typename Signature> class function;
template<typename R, typename T0>
class function<R(T0)> {
public:
    detail::function::vtable_base* vtable;
    detail::function::function_buffer functor;
    function(const function& f) : vtable(0)
    {
        if (f.vtable) {
            vtable = f.vtable;
            f.vtable->manager(f.functor, functor, 0);
        }
    }
    ~function();
};
}
namespace RBX { class Humanoid { public: enum Status { A }; }; }
namespace rbx {
template<class T, class Count = int, int a = 0, int b = 0>
class intrusive_ptr_target {
};
template<class T>
class intrusive_ptr {
    T* p;
public:
    intrusive_ptr() : p(0) {}
    ~intrusive_ptr();
};
template<int N, typename Signature>
class icallable {
public:
    virtual void call(RBX::Humanoid::Status) = 0;
};
template<class Base, class F, int N, typename Signature>
class callable : public Base {
    F func;
public:
    template<class A>
    callable(const F& f, A a);
    virtual void call(RBX::Humanoid::Status);
};
namespace signals {
class connection {
public:
    class islot : boost::noncopyable, public rbx::intrusive_ptr_target<islot> {
    public:
        virtual ~islot();
        virtual void disconnect() = 0;
        virtual bool connected() const = 0;
    };
};
template<typename Signature>
class signal {
public:
    class slot : public connection::islot, public rbx::icallable<1, Signature> {
    public:
        rbx::intrusive_ptr<slot> next;
        signal* sig;
        slot(signal* s) : sig(s) {}
        virtual void disconnect();
        virtual bool connected() const;
    };
};
}
template<class Base, class F, int N, typename Signature>
template<class A>
callable<Base, F, N, Signature>::callable(const F& f, A a)
    : Base(a), func(f)
{
}
}
typedef void Sig(RBX::Humanoid::Status);
template rbx::callable<rbx::signals::signal<Sig>::slot, boost::function<Sig>, 1, Sig>::callable(const boost::function<Sig>&, rbx::signals::signal<Sig>*);
