// from server: 100% by EspClaude
// roc 2009-06 005cfc10  BoundFuncDesc<Instance, shared_ptr<Instance>(std::string,bool),2>::call (2009 ExeCounter)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <intrin.h>
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
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r);
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
class any {
public:
    void* content;
    template<class T> any& operator=(const T& rhs);
};
}
namespace RBX {
class Instance;
namespace Reflection {
class ClassDescriptor;
class Type { public: template<class T> static const Type& singleton(); };
template<class T> struct ExeCounter { static int n; };
template<class T> inline const Type& countedType() { ++ExeCounter<T>::n; return Type::singleton<T>(); }
class Value {
public:
    const Type* _type;
    boost::any value;
    template<class T> T& convert();
    template<class T> Value& operator=(const T& rhs)
    {
        this->_type = &countedType<T>();
        this->value = rhs;
        return *this;
    }
};
class FunctionDescriptor {
public:
    enum Security { AnyCaller };
    virtual ~FunctionDescriptor();
    char pad[0x34];
};
template<class Class, class Function, int N> class BoundFuncDesc;
template<class Class, class R, class Arg1, class Arg2> class BoundFuncDesc<Class, R(Arg1, Arg2), 2> : public FunctionDescriptor {
public:
    typedef R (Class::*FunctionSig)(Arg1, Arg2);
    FunctionSig function;
    template<typename ReturnType>
    void call(Class* o, Value& returnValue, Value& arg1, Value& arg2) const
    {
        returnValue = (o->*function)(arg1.convert<Arg1>(), arg2.convert<Arg2>());
    }
};
}
class ExeBase { public: virtual void f(); };
class ExeBase2 { public: virtual void g(); };
class Instance : public ExeBase, public ExeBase2 { };
template void Reflection::BoundFuncDesc<Instance, boost::shared_ptr<Instance>(std::string, bool), 2>::call<boost::shared_ptr<Instance> >(Instance*, Reflection::Value&, Reflection::Value&, Reflection::Value&) const;
}
