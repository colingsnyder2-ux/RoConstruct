// from server: 100% by tester
namespace boost {
template<class T>
class shared_ptr
{
    T* px;
    void* pn;
public:
    T* get() const { return px; }
};

namespace _mfi {
template<class R, class T>
class mf0
{
    R (T::*f_)();
public:
    R operator()(const shared_ptr<T>& p) const
    {
        return (p.get()->*f_)();
    }
};
}

namespace _bi {
template<class T>
class value
{
    T t_;
public:
    T& get() { return t_; }
};

template<class A1>
class list1
{
    A1 a1_;
public:
    template<class F>
    void operator()(F& f)
    {
        f(a1_.get());
    }
};

template<class R, class F, class L>
class bind_t
{
    F f_;
    L l_;
public:
    R operator()()
    {
        l_(f_);
    }
};
}

namespace detail {
namespace function {
class X;

union function_buffer
{
    void* obj_ptr;
    const void* const_obj_ptr;
    void (*func_ptr)();
    struct bound_memfunc_ptr_t
    {
        void (X::*memfunc_ptr)(int);
        void* obj_ptr;
    } bound_memfunc_ptr;
    mutable char data;
};

template<typename FunctionObj, typename R>
struct void_function_obj_invoker0
{
    static void invoke(function_buffer& function_obj_ptr)
    {
        FunctionObj* f = reinterpret_cast<FunctionObj*>(&function_obj_ptr.data);
        (*f)();
    }
};
}
}
}

namespace RBX {
class IEquipable
{
public:
    virtual ~IEquipable();
};

class PVInstance
{
    char data[0x1bc];
public:
    virtual ~PVInstance();
};

class Flag : public PVInstance, public virtual IEquipable
{
public:
    void onEvent_ownerChanged();
};
}

template struct boost::detail::function::void_function_obj_invoker0<
    boost::_bi::bind_t<void, boost::_mfi::mf0<void, RBX::Flag>, boost::_bi::list1<boost::_bi::value<boost::shared_ptr<RBX::Flag> > > >,
    void>;
