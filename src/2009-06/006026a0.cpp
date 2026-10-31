// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <string>
#include <vector>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
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
    shared_ptr(const shared_ptr&);
};
class any {
public:
    template<class T> any& operator=(const T& rhs);
    void* content;
};
}
namespace RBX {
class Instance;
class ContentId {
public:
    std::string id;
    int mimeType;
};
namespace Reflection {
class Type { public: template<class T> static const Type& singleton(); };
template<class T> struct ExeCounter { static int n; };
class Value {
public:
    template<class T> const T& convert() const;
    template<class T> Value& operator=(const T& v)
    {
        ++ExeCounter<T>::n;
        type = &Type::singleton<T>();
        value = v;
        return *this;
    }
    const Type* type;
    boost::any value;
};
class FunctionDescriptor {
public:
    virtual ~FunctionDescriptor();
    char pad[0x34];
};
template<class Class> class FuncDesc : public FunctionDescriptor { };
template<class Class, class Function, int N> class BoundFuncDesc;
template<class Class, class R, class Arg1> class BoundFuncDesc<Class, R(Arg1), 1> : public FuncDesc<Class> {
public:
    typedef R (Class::*FunctionSig)(Arg1);
    FunctionSig function;
    template<typename ReturnType>
    void call(Class* o, Value& returnValue, Value& arg1) const
    {
        returnValue = (o->*function)(arg1.convert<Arg1>());
    }
};
}
class ExeBase { public: virtual void f(); };
class ExeBase2 { public: virtual void g(); };
class DataModel : public ExeBase, public ExeBase2 { };
typedef boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > Instances;
template void Reflection::BoundFuncDesc<DataModel, Instances(ContentId), 1>::call<Instances>(DataModel*, Reflection::Value&, Reflection::Value&) const;
}
