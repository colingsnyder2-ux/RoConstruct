// from server: 100% by EspClaude
// roc 2007-08 0041a620  RBX::Reflection::BoundFuncDesc<DHTMLWindow, void(), 0>::execute (global-namespace DHTMLWindow) (reflection/reflection.h: polymorphic_cast + 8-byte MI member-function pointer @+0x28)
// roc-flags: /O2 /GS /EHsc /MD
#include <typeinfo>
namespace boost {
template <class Target, class Source>
inline Target polymorphic_cast(Source* x)
{
    Target tmp = dynamic_cast<Target>(x);
    if (tmp == 0) throw std::bad_cast();
    return tmp;
}
}
namespace RBX {
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); int a; const void* descriptor; };
class Value;
class Arguments { public: Value* returnValue; };
template<class Class> class FuncDesc {
public:
    virtual ~FuncDesc();
    virtual void execute(DescribedBase* instance, Arguments& arguments) const = 0;
    char pad[0x28 - 4];
};
template<typename Class, typename Function, int N> class BoundFuncDesc;
template<typename Class>
class BoundFuncDesc<Class, void(), 0> : public FuncDesc<Class> {
public:
    typedef void (Class::*FunctionSig)();
private:
    FunctionSig function;
public:
    virtual void execute(DescribedBase* instance, Arguments& arguments) const
    {
        call(boost::polymorphic_cast<Class*>(instance), *arguments.returnValue);
    }
private:
    void call(Class* o, Value&) const { (o->*function)(); }
};
}
class V0 { public: virtual ~V0(); };
}
class DHTMLWindow : public RBX::V0, public RBX::Reflection::DescribedBase {
public:
    void close();
};
template class RBX::Reflection::BoundFuncDesc<DHTMLWindow, void(), 0>;

