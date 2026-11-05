// from server: 100% by EspClaude
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
template<class Class, class R, class Arg1, class Arg2, class Arg3> class BoundFuncDesc<Class, R(Arg1, Arg2, Arg3), 3> : public FuncDesc<Class> {
public:
    typedef R (Class::*FunctionSig)(Arg1, Arg2, Arg3);
    FunctionSig function;
    Value default1;
    Value default2;
    Value default3;
    void declareSignature(const char* arg1Name, const char* arg2Name, const char* arg3Name)
    {
        signature.resultType = &countedType<R>();
        signature.addArgument(Name::declare(arg1Name), countedType<Arg1>(), default1);
        signature.addArgument(Name::declare(arg2Name), countedType<Arg2>(), default2);
        signature.addArgument(Name::declare(arg3Name), countedType<Arg3>(), default3);
    }
};
}
class ExeBase { public: virtual void f(); };
class ExeBase2 { public: virtual void g(); };
class DebrisService : public ExeBase, public ExeBase2 { public: static Reflection::ClassDescriptor& classDescriptor(); };
template void Reflection::BoundFuncDesc<DebrisService, bool(bool, bool, int), 3>::declareSignature(const char*, const char*, const char*);
}
