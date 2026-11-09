// from server: 100% by EspClaude
// roc 2009-06 004e5bb0  unit: CRobloxWnd::UserInputJob  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e5bb0
//
// 004e5bb0  83ec0c               sub esp, 0xc
// 004e5bb3  56                   push esi
// 004e5bb4  6a00                 push 0
// 004e5bb6  68f41e9f00           push 0x9f1ef4
// 004e5bbb  8bf1                 mov esi, ecx
// 004e5bbd  8b06                 mov eax, dword ptr [esi]
// 004e5bbf  6874c29d00           push 0x9dc274
// 004e5bc4  6a00                 push 0
// 004e5bc6  50                   push eax
// 004e5bc7  e8ae402300           call 0x719c7a
// 004e5bcc  83c414               add esp, 0x14
// 004e5bcf  85c0                 test eax, eax
// 004e5bd1  751e                 jne 0x4e5bf1
// 004e5bd3  6850d38a00           push 0x8ad350
// 004e5bd8  8d4c2408             lea ecx, [esp + 8]
// 004e5bdc  ff1570e98900         call dword ptr [0x89e970]
// 004e5be2  68b04b9800           push 0x984bb0
// 004e5be7  8d442408             lea eax, [esp + 8]
// 004e5beb  50                   push eax
// 004e5bec  e8593e2300           call 0x719a4a
// 004e5bf1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e5bf5  8b4018               mov eax, dword ptr [eax + 0x18]
// 004e5bf8  8b10                 mov edx, dword ptr [eax]
// 004e5bfa  8b520c               mov edx, dword ptr [edx + 0xc]
// 004e5bfd  51                   push ecx
// 004e5bfe  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e5c01  51                   push ecx
// 004e5c02  8bc8                 mov ecx, eax
// 004e5c04  ffd2                 call edx
// 004e5c06  5e                   pop esi
// 004e5c07  83c40c               add esp, 0xc
// 004e5c0a  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABN@Z)

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
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const double&); };
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
    void set(const double& value);
};
void ChangePropertyItem::set(const double& value)
{
    RBX::Reflection::TypedPropertyDescriptor<double>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<double>*>(descriptor);
    typed->accessor->set(instance, value);
}