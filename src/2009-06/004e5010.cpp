// from server: 100% by EspClaude
// roc 2009-06 004e5010  unit: CRobloxWnd::UserInputJob  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e5010
//
// 004e5010  83ec0c               sub esp, 0xc
// 004e5013  56                   push esi
// 004e5014  6a00                 push 0
// 004e5016  6838c29d00           push 0x9dc238
// 004e501b  8bf1                 mov esi, ecx
// 004e501d  8b06                 mov eax, dword ptr [esi]
// 004e501f  6874c29d00           push 0x9dc274
// 004e5024  6a00                 push 0
// 004e5026  50                   push eax
// 004e5027  e84e4c2300           call 0x719c7a
// 004e502c  83c414               add esp, 0x14
// 004e502f  85c0                 test eax, eax
// 004e5031  751e                 jne 0x4e5051
// 004e5033  6850d38a00           push 0x8ad350
// 004e5038  8d4c2408             lea ecx, [esp + 8]
// 004e503c  ff1570e98900         call dword ptr [0x89e970]
// 004e5042  68b04b9800           push 0x984bb0
// 004e5047  8d442408             lea eax, [esp + 8]
// 004e504b  50                   push eax
// 004e504c  e8f9492300           call 0x719a4a
// 004e5051  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e5055  8b4018               mov eax, dword ptr [eax + 0x18]
// 004e5058  8b10                 mov edx, dword ptr [eax]
// 004e505a  8b520c               mov edx, dword ptr [edx + 0xc]
// 004e505d  51                   push ecx
// 004e505e  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e5061  51                   push ecx
// 004e5062  8bc8                 mov ecx, eax
// 004e5064  ffd2                 call edx
// 004e5066  5e                   pop esi
// 004e5067  83c40c               add esp, 0xc
// 004e506a  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXAB_N@Z)

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
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const bool&); };
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
    void set(const bool& value);
};
void ChangePropertyItem::set(const bool& value)
{
    RBX::Reflection::TypedPropertyDescriptor<bool>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<bool>*>(descriptor);
    typed->accessor->set(instance, value);
}