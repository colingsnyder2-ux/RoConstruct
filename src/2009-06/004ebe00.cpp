// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
template<class Class, class R> class BoundFuncDesc<Class, R(), 0> : public FunctionDescriptor {
public:
    typedef R (Class::*FunctionSig)();
    FunctionSig function;
    template<typename ReturnType>
    void call(Class* o, Value& returnValue) const
    {
        returnValue = (o->*function)();
    }
};
}
class ExeBase { public: virtual void f(); };
class ExeBase2 { public: virtual void g(); };
class Selection : public ExeBase, public ExeBase2 { public: static Reflection::ClassDescriptor& classDescriptor(); };
}
#include <vector>
namespace RBX {
typedef boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > SelR;
template void Reflection::BoundFuncDesc<Selection, SelR(), 0>::call<SelR>(Selection*, Reflection::Value&) const;
}
