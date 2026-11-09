// from server: 100% by EspClaude
// roc 2009-06 004e50d0  unit: CRobloxWnd::UserInputJob  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e50d0
//
// 004e50d0  83ec0c               sub esp, 0xc
// 004e50d3  56                   push esi
// 004e50d4  6a00                 push 0
// 004e50d6  684c269e00           push 0x9e264c
// 004e50db  8bf1                 mov esi, ecx
// 004e50dd  8b06                 mov eax, dword ptr [esi]
// 004e50df  6874c29d00           push 0x9dc274
// 004e50e4  6a00                 push 0
// 004e50e6  50                   push eax
// 004e50e7  e88e4b2300           call 0x719c7a
// 004e50ec  83c414               add esp, 0x14
// 004e50ef  85c0                 test eax, eax
// 004e50f1  751e                 jne 0x4e5111
// 004e50f3  6850d38a00           push 0x8ad350
// 004e50f8  8d4c2408             lea ecx, [esp + 8]
// 004e50fc  ff1570e98900         call dword ptr [0x89e970]
// 004e5102  68b04b9800           push 0x984bb0
// 004e5107  8d442408             lea eax, [esp + 8]
// 004e510b  50                   push eax
// 004e510c  e839492300           call 0x719a4a
// 004e5111  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e5115  8b4018               mov eax, dword ptr [eax + 0x18]
// 004e5118  8b10                 mov edx, dword ptr [eax]
// 004e511a  8b520c               mov edx, dword ptr [edx + 0xc]
// 004e511d  51                   push ecx
// 004e511e  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e5121  51                   push ecx
// 004e5122  8bc8                 mov ecx, eax
// 004e5124  ffd2                 call edx
// 004e5126  5e                   pop esi
// 004e5127  83c40c               add esp, 0xc
// 004e512a  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABM@Z)

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
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const float&); };
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
    void set(const float& value);
};
void ChangePropertyItem::set(const float& value)
{
    RBX::Reflection::TypedPropertyDescriptor<float>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<float>*>(descriptor);
    typed->accessor->set(instance, value);
}