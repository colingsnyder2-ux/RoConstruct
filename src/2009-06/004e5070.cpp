// from server: 100% by EspClaude
// roc 2009-06 004e5070  unit: CRobloxWnd::UserInputJob  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e5070
//
// 004e5070  83ec0c               sub esp, 0xc
// 004e5073  56                   push esi
// 004e5074  6a00                 push 0
// 004e5076  6810269e00           push 0x9e2610
// 004e507b  8bf1                 mov esi, ecx
// 004e507d  8b06                 mov eax, dword ptr [esi]
// 004e507f  6874c29d00           push 0x9dc274
// 004e5084  6a00                 push 0
// 004e5086  50                   push eax
// 004e5087  e8ee4b2300           call 0x719c7a
// 004e508c  83c414               add esp, 0x14
// 004e508f  85c0                 test eax, eax
// 004e5091  751e                 jne 0x4e50b1
// 004e5093  6850d38a00           push 0x8ad350
// 004e5098  8d4c2408             lea ecx, [esp + 8]
// 004e509c  ff1570e98900         call dword ptr [0x89e970]
// 004e50a2  68b04b9800           push 0x984bb0
// 004e50a7  8d442408             lea eax, [esp + 8]
// 004e50ab  50                   push eax
// 004e50ac  e899492300           call 0x719a4a
// 004e50b1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e50b5  8b4018               mov eax, dword ptr [eax + 0x18]
// 004e50b8  8b10                 mov edx, dword ptr [eax]
// 004e50ba  8b520c               mov edx, dword ptr [edx + 0xc]
// 004e50bd  51                   push ecx
// 004e50be  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e50c1  51                   push ecx
// 004e50c2  8bc8                 mov ecx, eax
// 004e50c4  ffd2                 call edx
// 004e50c6  5e                   pop esi
// 004e50c7  83c40c               add esp, 0xc
// 004e50ca  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABH@Z)

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
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const int&); };
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
    void set(const int& value);
};
void ChangePropertyItem::set(const int& value)
{
    RBX::Reflection::TypedPropertyDescriptor<int>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<int>*>(descriptor);
    typed->accessor->set(instance, value);
}