// from server: 100% by EspClaude
namespace boost { template<class T> class shared_ptr; }
namespace std { template<class T> class allocator; template<class T, class A> class vector; }
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection {
class ClassDescriptor;
class Type { public: template<class T> static const Type& singleton(); };
template<class T> struct ExeCounter { static int n; };
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
template<class Class, class R> class BoundFuncDesc<Class, R(), 0> : public FuncDesc<Class> {
public:
    typedef R (Class::*FunctionSig)();
    FunctionSig function;
    BoundFuncDesc(FunctionSig function, const char* name, Security security)
        : FuncDesc<Class>(name, security), function(function)
    {
        ++ExeCounter<R>::n;
        signature.resultType = &Type::singleton<R>();
    }
    virtual ~BoundFuncDesc() {}
};
}
class ExeBase { public: virtual void f(); };
class ExeBase2 { public: virtual void g(); };
class RunService : public ExeBase, public ExeBase2 { public: static Reflection::ClassDescriptor& classDescriptor(); };
template class Reflection::BoundFuncDesc<RunService, void(), 0>;
}
