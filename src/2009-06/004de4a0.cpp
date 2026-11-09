// from server: 100% by EspClaude
// roc 2009-06 004de4a0  unit: RBX::Network::IdSerializer  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004de4a0
//
// 004de4a0  83ec0c               sub esp, 0xc
// 004de4a3  56                   push esi
// 004de4a4  6a00                 push 0
// 004de4a6  6878259e00           push 0x9e2578
// 004de4ab  8bf1                 mov esi, ecx
// 004de4ad  8b06                 mov eax, dword ptr [esi]
// 004de4af  6874c29d00           push 0x9dc274
// 004de4b4  6a00                 push 0
// 004de4b6  50                   push eax
// 004de4b7  e8beb72300           call 0x719c7a
// 004de4bc  83c414               add esp, 0x14
// 004de4bf  85c0                 test eax, eax
// 004de4c1  751e                 jne 0x4de4e1
// 004de4c3  6850d38a00           push 0x8ad350
// 004de4c8  8d4c2408             lea ecx, [esp + 8]
// 004de4cc  ff1570e98900         call dword ptr [0x89e970]
// 004de4d2  68b04b9800           push 0x984bb0
// 004de4d7  8d442408             lea eax, [esp + 8]
// 004de4db  50                   push eax
// 004de4dc  e869b52300           call 0x719a4a
// 004de4e1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004de4e5  8b4018               mov eax, dword ptr [eax + 0x18]
// 004de4e8  8b10                 mov edx, dword ptr [eax]
// 004de4ea  8b520c               mov edx, dword ptr [edx + 0xc]
// 004de4ed  51                   push ecx
// 004de4ee  8b4e04               mov ecx, dword ptr [esi + 4]
// 004de4f1  51                   push ecx
// 004de4f2  8bc8                 mov ecx, eax
// 004de4f4  ffd2                 call edx
// 004de4f6  5e                   pop esi
// 004de4f7  83c40c               add esp, 0xc
// 004de4fa  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABVBrickColor@RBX@@@Z)

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
namespace RBX { class BrickColor; namespace Soundscape { class SoundId; } }
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const RBX::BrickColor&); };
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
    void set(const RBX::BrickColor& value);
};
void ChangePropertyItem::set(const RBX::BrickColor& value)
{
    RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>*>(descriptor);
    typed->accessor->set(instance, value);
}