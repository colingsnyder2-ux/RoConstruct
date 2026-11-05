// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <typeinfo>
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace boost {
template<class Target, class Source> inline Target polymorphic_cast(Source* x)
{
    Target tmp = dynamic_cast<Target>(x);
    if (tmp == 0) throw std::bad_cast("bad cast");
    return tmp;
}
}
namespace RBX {
namespace Reflection {
class Type;
template<class T> struct ExeCounter { static int n; };
template<class T> const Type& singletonOf();
class Holder { public: void set(const G3D::Vector3& v); };
class DescribedBase { public: virtual ~DescribedBase(); };
class Value {
public:
    const Type* type;
    Holder holder;
    Value& operator=(const G3D::Vector3& v)
    {
        ++ExeCounter<G3D::Vector3>::n;
        type = &singletonOf<G3D::Vector3>();
        holder.set(v);
        return *this;
    }
};
class FunctionDescriptor {
public:
    class Arguments { public: int pad; Value returnValue; };
    virtual ~FunctionDescriptor();
    virtual void execute(DescribedBase* instance, Arguments& arguments) const = 0;
    char pad[0x34];
};
template<class Class, class Function, int N> class BoundFuncDesc;
template<class Class> class BoundFuncDesc<Class, G3D::Vector3(), 0> : public FunctionDescriptor {
public:
    typedef G3D::Vector3 (Class::*FunctionSig)();
    FunctionSig function;
    virtual void execute(DescribedBase* instance, Arguments& arguments) const
    {
        call(boost::polymorphic_cast<Class*>(instance), arguments.returnValue);
    }
    void call(Class* o, Value& returnValue) const
    {
        returnValue = (o->*function)();
    }
};
}
class ExeBase { public: virtual void f(); };
class Lighting : public ExeBase, public Reflection::DescribedBase { public: G3D::Vector3 get(); };
template class Reflection::BoundFuncDesc<Lighting, G3D::Vector3(), 0>;
}
