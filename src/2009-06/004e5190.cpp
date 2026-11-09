// from server: 100% by EspClaude
// roc 2009-06 004e5190  unit: CRobloxWnd::UserInputJob  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e5190
//
// 004e5190  83ec0c               sub esp, 0xc
// 004e5193  56                   push esi
// 004e5194  6a00                 push 0
// 004e5196  68e83e9f00           push 0x9f3ee8
// 004e519b  8bf1                 mov esi, ecx
// 004e519d  8b06                 mov eax, dword ptr [esi]
// 004e519f  6874c29d00           push 0x9dc274
// 004e51a4  6a00                 push 0
// 004e51a6  50                   push eax
// 004e51a7  e8ce4a2300           call 0x719c7a
// 004e51ac  83c414               add esp, 0x14
// 004e51af  85c0                 test eax, eax
// 004e51b1  751e                 jne 0x4e51d1
// 004e51b3  6850d38a00           push 0x8ad350
// 004e51b8  8d4c2408             lea ecx, [esp + 8]
// 004e51bc  ff1570e98900         call dword ptr [0x89e970]
// 004e51c2  68b04b9800           push 0x984bb0
// 004e51c7  8d442408             lea eax, [esp + 8]
// 004e51cb  50                   push eax
// 004e51cc  e879482300           call 0x719a4a
// 004e51d1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e51d5  8b4018               mov eax, dword ptr [eax + 0x18]
// 004e51d8  8b10                 mov edx, dword ptr [eax]
// 004e51da  8b520c               mov edx, dword ptr [edx + 0xc]
// 004e51dd  51                   push ecx
// 004e51de  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e51e1  51                   push ecx
// 004e51e2  8bc8                 mov ecx, eax
// 004e51e4  ffd2                 call edx
// 004e51e6  5e                   pop esi
// 004e51e7  83c40c               add esp, 0xc
// 004e51ea  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABVCoordinateFrame@G3D@@@Z)

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
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const G3D::CoordinateFrame&); };
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
    void set(const G3D::CoordinateFrame& value);
};
void ChangePropertyItem::set(const G3D::CoordinateFrame& value)
{
    RBX::Reflection::TypedPropertyDescriptor<G3D::CoordinateFrame>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<G3D::CoordinateFrame>*>(descriptor);
    typed->accessor->set(instance, value);
}