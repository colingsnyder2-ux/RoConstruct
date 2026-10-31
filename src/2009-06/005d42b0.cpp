// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
}
}
namespace boost {
namespace detail {
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}
namespace std { template<class T> class allocator; template<class T, class A> class vector; }
namespace RBX {
class Instance;
namespace Reflection {
class Type { public: template<class T> static const Type& singleton(); };
template<class T> struct ExeCounter { static int n; };
class Any { public: template<class T> Any& operator=(const T& v); };
class Value {
public:
    const Type* type;
    Any value;
    template<class T> Value& operator=(const T& v)
    {
        ++ExeCounter<T>::n;
        type = &Type::singleton<T>();
        value = v;
        return *this;
    }
};
class FunctionDescriptor {
public:
    virtual ~FunctionDescriptor();
    char pad[0x34];
};
template<class Class, class Function, int N> class BoundFuncDesc;
template<class Class, class R> class BoundFuncDesc<Class, R(), 0> : public FunctionDescriptor {
public:
    typedef R (Class::*FunctionSig)();
    FunctionSig function;
    void exec(Class* o, Value& v) const { call<R>(o, v); }
private:
    template<class RR> void call(Class* o, Value& returnValue) const
    {
        returnValue = (o->*function)();
    }
};
}
class ExeBase { public: virtual void f(); };
class ExeBase2 { public: virtual void g(); };
class Selection : public ExeBase, public ExeBase2 { };
typedef boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>, std::allocator<boost::shared_ptr<Instance> > > > SelR;
template class Reflection::BoundFuncDesc<Selection, SelR(), 0>;
}
