// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <stddef.h>
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
template<class T> class shared_ptr;
template<class T>
class intrusive_ptr {
    T* px;
public:
    intrusive_ptr() : px(0) {}
    intrusive_ptr(T* p) : px(p) { if (px != 0) intrusive_ptr_add_ref(px); }
    intrusive_ptr(const intrusive_ptr& rhs) : px(rhs.px) { if (px != 0) intrusive_ptr_add_ref(px); }
    ~intrusive_ptr();
};
namespace _mfi { template<class R, class T> class mf0 { R (T::*f_)(); }; }
namespace _bi {
template<class T> class value { T t_; };
template<class A1> class list1 { A1 a1_; };
template<class R, class F, class L> class bind_t { F f_; L l_; };
}
}
namespace RBX {
class Instance;
class VB { int a; }; class VC { int b; };
class VelocityMotor : public VB, public VC {};
}
namespace rbx {
template<class T, class Count = int, int a = 0, int b = 0>
class intrusive_ptr_target {
public:
    void* operator new(size_t size) throw();
};
template<class T, class Count, int a, int b>
void intrusive_ptr_add_ref(const intrusive_ptr_target<T, Count, a, b>* p);
template<int N, typename Signature>
class icallable {
public:
    virtual void call() = 0;
};
template<class Base, class F, int N, typename Signature>
class callable : public Base {
protected:
    F func;
public:
    template<class A>
    callable(const F& f, A a) : Base(a), func(f) {}
    virtual void call();
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
    connection(islot* s) : slot_(s) {}
private:
    boost::intrusive_ptr<islot> slot_;
};
template<typename Signature>
class signal {
public:
    class slot : public connection::islot, public rbx::icallable<2, Signature> {
    public:
        boost::intrusive_ptr<slot> next;
        signal* sig;
        slot(signal* s) : sig(s) {}
        virtual void disconnect();
        virtual bool connected() const;
    };
    template<class F>
    class callable_slot : public rbx::callable<slot, F, 2, Signature> {
    public:
        callable_slot(const F& f, signal* s) : rbx::callable<slot, F, 2, Signature>(f, s) {}
    };
    boost::intrusive_ptr<slot> head;
    void insert(slot* item);
    template<class F>
    connection connect(const F& f)
    {
        callable_slot<F>* item = new callable_slot<F>(f, this);
        insert(item);
        return connection(item);
    }
};
}
}
typedef void Sig(boost::shared_ptr<RBX::Instance>, boost::shared_ptr<RBX::Instance>);
typedef boost::_bi::bind_t<void, boost::_mfi::mf0<void, RBX::VelocityMotor>, boost::_bi::list1<boost::_bi::value<RBX::VelocityMotor*> > > Bound;
template rbx::signals::connection rbx::signals::signal<Sig>::connect<Bound>(const Bound&);

