// from server: 100% by EspClaude
// roc 2009-06 004e5130  unit: CRobloxWnd::UserInputJob  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e5130
//
// 004e5130  83ec0c               sub esp, 0xc
// 004e5133  56                   push esi
// 004e5134  6a00                 push 0
// 004e5136  68c8259e00           push 0x9e25c8
// 004e513b  8bf1                 mov esi, ecx
// 004e513d  8b06                 mov eax, dword ptr [esi]
// 004e513f  6874c29d00           push 0x9dc274
// 004e5144  6a00                 push 0
// 004e5146  50                   push eax
// 004e5147  e82e4b2300           call 0x719c7a
// 004e514c  83c414               add esp, 0x14
// 004e514f  85c0                 test eax, eax
// 004e5151  751e                 jne 0x4e5171
// 004e5153  6850d38a00           push 0x8ad350
// 004e5158  8d4c2408             lea ecx, [esp + 8]
// 004e515c  ff1570e98900         call dword ptr [0x89e970]
// 004e5162  68b04b9800           push 0x984bb0
// 004e5167  8d442408             lea eax, [esp + 8]
// 004e516b  50                   push eax
// 004e516c  e8d9482300           call 0x719a4a
// 004e5171  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e5175  8b4018               mov eax, dword ptr [eax + 0x18]
// 004e5178  8b10                 mov edx, dword ptr [eax]
// 004e517a  8b520c               mov edx, dword ptr [edx + 0xc]
// 004e517d  51                   push ecx
// 004e517e  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e5181  51                   push ecx
// 004e5182  8bc8                 mov ecx, eax
// 004e5184  ffd2                 call edx
// 004e5186  5e                   pop esi
// 004e5187  83c40c               add esp, 0xc
// 004e518a  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABVColor3@G3D@@@Z)

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
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const G3D::Color3&); };
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
    void set(const G3D::Color3& value);
};
void ChangePropertyItem::set(const G3D::Color3& value)
{
    RBX::Reflection::TypedPropertyDescriptor<G3D::Color3>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<G3D::Color3>*>(descriptor);
    typed->accessor->set(instance, value);
}