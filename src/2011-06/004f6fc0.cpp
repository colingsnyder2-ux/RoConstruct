// from server: 100% by Yeetserama
// roc 2011-06 004f6fc0  unit: RBX::VRbxRay::?$holder  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004f6fc0
//
// 004f6fc0  83ec0c               sub esp, 0xc
// 004f6fc3  56                   push esi
// 004f6fc4  6a00                 push 0
// 004f6fc6  68f8abc200           push 0xc2abf8
// 004f6fcb  8bf1                 mov esi, ecx
// 004f6fcd  8b06                 mov eax, dword ptr [esi]
// 004f6fcf  68e479c000           push 0xc079e4
// 004f6fd4  6a00                 push 0
// 004f6fd6  50                   push eax
// 004f6fd7  e80e433100           call 0x80b2ea
// 004f6fdc  83c414               add esp, 0x14
// 004f6fdf  85c0                 test eax, eax
// 004f6fe1  751e                 jne 0x4f7001
// 004f6fe3  680cc1a500           push 0xa5c10c
// 004f6fe8  8d4c2408             lea ecx, [esp + 8]
// 004f6fec  ff15100aa400         call dword ptr [0xa40a10]
// 004f6ff2  68fc89b900           push 0xb989fc
// 004f6ff7  8d442408             lea eax, [esp + 8]
// 004f6ffb  50                   push eax
// 004f6ffc  e8ab403100           call 0x80b0ac
// 004f7001  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f7004  8b742414             mov esi, dword ptr [esp + 0x14]
// 004f7008  51                   push ecx
// 004f7009  56                   push esi
// 004f700a  8bc8                 mov ecx, eax
// 004f700c  e83ff5ffff           call 0x4f6550
// 004f7011  8bc6                 mov eax, esi
// 004f7013  5e                   pop esi
// 004f7014  83c40c               add esp, 0xc
// 004f7017  c20400               ret 4
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