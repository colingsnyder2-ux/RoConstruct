// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc 2009-06 005cfb50  unit: RBX::VInstance::?$BoundFuncDesc  size: 187 bytes
// BoundFuncDesc<Instance, shared_ptr<Instance>(std::string,bool), 2> ctor with a bool default for arg 2
#include <string>
namespace boost { template<class T> class shared_ptr { T* px; void* pn; }; }
namespace RBX {
namespace Reflection {
class ClassDescriptor;
class Type { public: template<class T> static const Type& singleton(); };
template<class T> struct ExeCounter { static int n; };
template<class T> inline const Type& countedType() { ++ExeCounter<T>::n; return Type::singleton<T>(); }
class PlaceHolder { public: virtual ~PlaceHolder() {} virtual PlaceHolder* clone() const = 0; };
template<class T> class Holder : public PlaceHolder {
public:
    Holder(const T& v) : held(v) {}
    virtual PlaceHolder* clone() const { return new Holder(held); }
    T held;
};
class Value {
public:
    Value();
    template<class T> Value(const T& v) : type(&countedType<T>()), content(new Holder<T>(v)) {}
    ~Value();
    const Type* type;
    PlaceHolder* content;
};
class FunctionDescriptor {
public:
    enum Security { AnyCaller };
protected:
    FunctionDescriptor(ClassDescriptor& c, const char* name, Security security);
public:
    virtual ~FunctionDescriptor();
    char pad[0x34];
};
template<class Class> class FuncDesc : public FunctionDescriptor {
public:
    FuncDesc(const char* name, Security security)
        : FunctionDescriptor(Class::classDescriptor(), name, security) {}
};
template<class Class, class Function, int N> class BoundFuncDesc;
template<class Class, class R, class Arg1, class Arg2> class BoundFuncDesc<Class, R(Arg1, Arg2), 2> : public FuncDesc<Class> {
public:
    typedef R (Class::*FunctionSig)(Arg1, Arg2);
    FunctionSig function;
    Value default1;
    Value default2;
    void declareSignature(const char* arg1Name, const char* arg2Name);
    BoundFuncDesc(FunctionSig function, const char* name, const char* arg1Name, const char* arg2Name, Arg2 def2, Security security)
        : FuncDesc<Class>(name, security), function(function), default2(def2)
    {
        declareSignature(arg1Name, arg2Name);
    }
    virtual ~BoundFuncDesc() {}
};
}
class ExeBase { public: virtual void f(); };
class ExeBase2 { public: virtual void g(); };
class Instance : public ExeBase, public ExeBase2 { public: static Reflection::ClassDescriptor& classDescriptor(); };
template class Reflection::BoundFuncDesc<Instance, boost::shared_ptr<Instance>(std::string, bool), 2>;
}
