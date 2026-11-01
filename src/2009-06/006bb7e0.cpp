// from server: 100% by EspClaude
// roc 2009-06 006bb7e0  unit: RBX::Lua::LuaArguments  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006bb7e0
//
// 006bb7e0  83ec0c               sub esp, 0xc
// 006bb7e3  56                   push esi
// 006bb7e4  6a00                 push 0
// 006bb7e6  680829a200           push 0xa22908
// 006bb7eb  8bf1                 mov esi, ecx
// 006bb7ed  8b06                 mov eax, dword ptr [esi]
// 006bb7ef  6874c29d00           push 0x9dc274
// 006bb7f4  6a00                 push 0
// 006bb7f6  50                   push eax
// 006bb7f7  e87ee40500           call 0x719c7a
// 006bb7fc  83c414               add esp, 0x14
// 006bb7ff  85c0                 test eax, eax
// 006bb801  751e                 jne 0x6bb821
// 006bb803  6850d38a00           push 0x8ad350
// 006bb808  8d4c2408             lea ecx, [esp + 8]
// 006bb80c  ff1570e98900         call dword ptr [0x89e970]
// 006bb812  68b04b9800           push 0x984bb0
// 006bb817  8d442408             lea eax, [esp + 8]
// 006bb81b  50                   push eax
// 006bb81c  e829e20500           call 0x719a4a
// 006bb821  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006bb825  8b4018               mov eax, dword ptr [eax + 0x18]
// 006bb828  8b10                 mov edx, dword ptr [eax]
// 006bb82a  8b520c               mov edx, dword ptr [edx + 0xc]
// 006bb82d  51                   push ecx
// 006bb82e  8b4e04               mov ecx, dword ptr [esi + 4]
// 006bb831  51                   push ecx
// 006bb832  8bc8                 mov ecx, eax
// 006bb834  ffd2                 call edx
// 006bb836  5e                   pop esi
// 006bb837  83c40c               add esp, 0xc
// 006bb83a  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABV?$shared_ptr@VDescribedBase@Reflection@RBX@@@boost@@@Z)

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
namespace RBX { class BrickColor; namespace Reflection { class DescribedBase; } }
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const boost::shared_ptr<RBX::Reflection::DescribedBase>&); };
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
    void set(const boost::shared_ptr<RBX::Reflection::DescribedBase>& value);
};
void ChangePropertyItem::set(const boost::shared_ptr<RBX::Reflection::DescribedBase>& value)
{
    RBX::Reflection::TypedPropertyDescriptor<boost::shared_ptr<RBX::Reflection::DescribedBase>>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<boost::shared_ptr<RBX::Reflection::DescribedBase>>*>(descriptor);
    typed->accessor->set(instance, value);
}