// from server: 100% by EspClaude
// roc 2009-06 004e4bc0  unit: CRobloxWnd::UserInputJob  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e4bc0
//
// 004e4bc0  83ec0c               sub esp, 0xc
// 004e4bc3  56                   push esi
// 004e4bc4  6a00                 push 0
// 004e4bc6  6830259e00           push 0x9e2530
// 004e4bcb  8bf1                 mov esi, ecx
// 004e4bcd  8b06                 mov eax, dword ptr [esi]
// 004e4bcf  6874c29d00           push 0x9dc274
// 004e4bd4  6a00                 push 0
// 004e4bd6  50                   push eax
// 004e4bd7  e89e502300           call 0x719c7a
// 004e4bdc  83c414               add esp, 0x14
// 004e4bdf  85c0                 test eax, eax
// 004e4be1  751e                 jne 0x4e4c01
// 004e4be3  6850d38a00           push 0x8ad350
// 004e4be8  8d4c2408             lea ecx, [esp + 8]
// 004e4bec  ff1570e98900         call dword ptr [0x89e970]
// 004e4bf2  68b04b9800           push 0x984bb0
// 004e4bf7  8d442408             lea eax, [esp + 8]
// 004e4bfb  50                   push eax
// 004e4bfc  e8494e2300           call 0x719a4a
// 004e4c01  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e4c05  8b4018               mov eax, dword ptr [eax + 0x18]
// 004e4c08  8b10                 mov edx, dword ptr [eax]
// 004e4c0a  8b520c               mov edx, dword ptr [edx + 0xc]
// 004e4c0d  51                   push ecx
// 004e4c0e  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e4c11  51                   push ecx
// 004e4c12  8bc8                 mov ecx, eax
// 004e4c14  ffd2                 call edx
// 004e4c16  5e                   pop esi
// 004e4c17  83c40c               add esp, 0xc
// 004e4c1a  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABVVector3@G3D@@@Z)

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
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const G3D::Vector3&); };
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
    void set(const G3D::Vector3& value);
};
void ChangePropertyItem::set(const G3D::Vector3& value)
{
    RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>*>(descriptor);
    typed->accessor->set(instance, value);
}