// from server: 100% by EspClaude
// roc 2009-06 004e4fb0  unit: CRobloxWnd::UserInputJob  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e4fb0
//
// 004e4fb0  83ec0c               sub esp, 0xc
// 004e4fb3  56                   push esi
// 004e4fb4  6a00                 push 0
// 004e4fb6  68e83e9f00           push 0x9f3ee8
// 004e4fbb  8bf1                 mov esi, ecx
// 004e4fbd  8b06                 mov eax, dword ptr [esi]
// 004e4fbf  6874c29d00           push 0x9dc274
// 004e4fc4  6a00                 push 0
// 004e4fc6  50                   push eax
// 004e4fc7  e8ae4c2300           call 0x719c7a
// 004e4fcc  83c414               add esp, 0x14
// 004e4fcf  85c0                 test eax, eax
// 004e4fd1  751e                 jne 0x4e4ff1
// 004e4fd3  6850d38a00           push 0x8ad350
// 004e4fd8  8d4c2408             lea ecx, [esp + 8]
// 004e4fdc  ff1570e98900         call dword ptr [0x89e970]
// 004e4fe2  68b04b9800           push 0x984bb0
// 004e4fe7  8d442408             lea eax, [esp + 8]
// 004e4feb  50                   push eax
// 004e4fec  e8594a2300           call 0x719a4a
// 004e4ff1  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e4ff4  8b742414             mov esi, dword ptr [esp + 0x14]
// 004e4ff8  51                   push ecx
// 004e4ff9  56                   push esi
// 004e4ffa  8bc8                 mov ecx, eax
// 004e4ffc  e8cff8ffff           call 0x4e48d0
// 004e5001  8bc6                 mov eax, esi
// 004e5003  5e                   pop esi
// 004e5004  83c40c               add esp, 0xc
// 004e5007  c20400               ret 4
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