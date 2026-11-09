// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <typeinfo>
namespace boost {
template<class Target, class Source>
inline Target polymorphic_cast(Source* x)
{
    Target tmp = dynamic_cast<Target>(x);
    if (tmp == 0)
        throw std::bad_cast("bad cast");
    return tmp;
}
}
namespace boost { template<class T> class shared_ptr; }
namespace RBX { class Instance; }
namespace G3D { class Color3; class Vector3; }
namespace RBX { class BrickColor; namespace Lua { class FunctionRef; } }
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const RBX::Lua::FunctionRef&); };
namespace RBX { namespace Reflection {
class PropertyDescriptor { public: virtual ~PropertyDescriptor(); };
template<class T>
class TypedPropertyDescriptor : public PropertyDescriptor {
public:
    unsigned char padding[20];
    AccessorT* accessor;
};
} }
struct ChangePropertyItem {
    RBX::Reflection::PropertyDescriptor* descriptor;
    void* instance;
    void set(const RBX::Lua::FunctionRef& value);
};
void ChangePropertyItem::set(const RBX::Lua::FunctionRef& value)
{
    RBX::Reflection::TypedPropertyDescriptor<RBX::Lua::FunctionRef>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<RBX::Lua::FunctionRef>*>(descriptor);
    typed->accessor->set(instance, value);
}
