// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _DLL
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
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX {
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); };
class Type { public: template<class T> static const Type& singleton(); };
class Storage { public: void assign(const G3D::Vector3& v); };
class Value
{
public:
    const Type* type;
    Storage storage;
    Value& operator=(const G3D::Vector3& v)
    {
        type = &Type::singleton<G3D::Vector3>();
        storage.assign(v);
        return *this;
    }
};
class FunctionDescriptor
{
public:
    class Arguments { public: virtual ~Arguments(); Value returnValue; };
    virtual void execute(DescribedBase* instance, Arguments& arguments) const = 0;
    char pad[0x34];
};
template<typename Class, typename Function>
class BoundFuncDesc : public FunctionDescriptor
{
public:
    G3D::Vector3 (Class::*function)();
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
class Other { public: virtual ~Other(); };
class Lighting : public Other, public Reflection::DescribedBase { public: G3D::Vector3 getAmbient(); };
template class Reflection::BoundFuncDesc<Lighting, G3D::Vector3()>;
}
