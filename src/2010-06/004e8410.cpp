// from server: 100% by Yeetserama
// roc 2010-06 004e8410  unit: G3D::VRay::?$holder  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e8410
//
// 004e8410  83ec0c               sub esp, 0xc
// 004e8413  56                   push esi
// 004e8414  6a00                 push 0
// 004e8416  687020b900           push 0xb92070
// 004e841b  8bf1                 mov esi, ecx
// 004e841d  8b06                 mov eax, dword ptr [esi]
// 004e841f  68ac92b700           push 0xb792ac
// 004e8424  6a00                 push 0
// 004e8426  50                   push eax
// 004e8427  e8be072c00           call 0x7a8bea
// 004e842c  83c414               add esp, 0x14
// 004e842f  85c0                 test eax, eax
// 004e8431  751e                 jne 0x4e8451
// 004e8433  68540aa000           push 0xa00a54
// 004e8438  8d4c2408             lea ecx, [esp + 8]
// 004e843c  ff159ca89e00         call dword ptr [0x9ea89c]
// 004e8442  689022b100           push 0xb12290
// 004e8447  8d442408             lea eax, [esp + 8]
// 004e844b  50                   push eax
// 004e844c  e861052c00           call 0x7a89b2
// 004e8451  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e8454  8b742414             mov esi, dword ptr [esp + 0x14]
// 004e8458  51                   push ecx
// 004e8459  56                   push esi
// 004e845a  8bc8                 mov ecx, eax
// 004e845c  e80ff7ffff           call 0x4e7b70
// 004e8461  8bc6                 mov eax, esi
// 004e8463  5e                   pop esi
// 004e8464  83c40c               add esp, 0xc
// 004e8467  c20400               ret 4
// copied from an identical function in another client (function ?f@ChangePropertyItem@@QAEABVCoordinateFrame@G3D@@ABV23@@Z)

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
namespace G3D { class Color3; class CoordinateFrame; class Vector3; }
namespace RBX { class BrickColor; namespace Soundscape { class SoundId; } }
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(void*, void*); virtual void set(void*, const G3D::CoordinateFrame&); };
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
    const G3D::CoordinateFrame& f(const G3D::CoordinateFrame& value);
};
struct TypedDescriptorHelper {
    const void* invoke(const void* value, void* instance);
};
const G3D::CoordinateFrame& ChangePropertyItem::f(const G3D::CoordinateFrame& value)
{
    RBX::Reflection::TypedPropertyDescriptor<G3D::CoordinateFrame>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<G3D::CoordinateFrame>*>(descriptor);
    reinterpret_cast<TypedDescriptorHelper*>(typed)->invoke(&value, instance);
    return value;
}