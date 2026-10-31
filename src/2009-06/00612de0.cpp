// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class ClassDescriptor;
class Type { public: template<class T> static const Type& singleton(); };
extern int exeFuncDescCount;
class FunctionDescriptor {
public:
    enum Security { AnyCaller };
    struct Signature { const Type* resultType; char pad[0x1c]; Signature(); };
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
template<class Class> class BoundFuncDesc<Class, void(), 0> : public FuncDesc<Class> {
public:
    typedef void (Class::*FunctionSig)();
    FunctionSig function;
    BoundFuncDesc(FunctionSig function, const char* name, Security security)
        : FuncDesc<Class>(name, security), function(function)
    {
        ++exeFuncDescCount;
        signature.resultType = &Type::singleton<void>();
    }
    virtual ~BoundFuncDesc() {}
};
}
class ExeBase { public: virtual void f(); };
class ExeBase2 { public: virtual void g(); };
class ModelInstance : public ExeBase, public virtual ExeBase2 { public: static Reflection::ClassDescriptor& classDescriptor(); };
template class Reflection::BoundFuncDesc<ModelInstance, void(), 0>;
}
