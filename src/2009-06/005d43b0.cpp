// from server: 100% by EspClaude
// roc 2009-06 005d43b0  BoundFuncDesc 1-arg ctor
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost { template<class T> class shared_ptr { T* px; void* pn; }; }
namespace RBX {
class Instance;
class Name { public: static const Name& declare(const char* name); };
namespace Reflection {
class ClassDescriptor;
class Type { public: template<class T> static const Type& singleton(); };
template<class T> struct ExeCounter { static int n; };
template<class T> inline const Type& countedType() { ++ExeCounter<T>::n; return Type::singleton<T>(); }
class Value { public: Value(); ~Value(); char pad[8]; };
class FunctionDescriptor {
public:
    enum Security { AnyCaller };
    struct Signature {
        const Type* resultType; char pad[0x20];
        void addArgument(const Name& name, const Type& type, const Value& def);
    };
protected:
    FunctionDescriptor(ClassDescriptor& c, const char* name, Security security);
public:
    virtual ~FunctionDescriptor();
    char pad[0x10];
    Signature signature;
};
template<class Class> class FuncDesc : public FunctionDescriptor {
public:
    FuncDesc(const char* name, Security security)
        : FunctionDescriptor(Class::classDescriptor(), name, security) {}
};
template<class Class, class Function, int N> class BoundFuncDesc;
template<class Class, class R, class Arg1> class BoundFuncDesc<Class, R(Arg1), 1> : public FuncDesc<Class> {
public:
    typedef R (Class::*FunctionSig)(Arg1);
    FunctionSig function;
    Value default1;
    void declareSignature(const char* arg1Name)
    {
        signature.resultType = &countedType<R>();
        signature.addArgument(Name::declare(arg1Name), countedType<Arg1>(), default1);
    }
    BoundFuncDesc(FunctionSig function, const char* name, const char* arg1Name, Security security)
        : FuncDesc<Class>(name, security), function(function)
    {
        declareSignature(arg1Name);
    }
    virtual ~BoundFuncDesc() {}
};
}
namespace Network {
class ExeBase { public: virtual void f(); };
class ExeBase2 { public: virtual void g(); };
class Players : public ExeBase, public ExeBase2 { public: static Reflection::ClassDescriptor& classDescriptor(); };
}
template class Reflection::BoundFuncDesc<Network::Players, boost::shared_ptr<Instance>(int), 1>;
}
