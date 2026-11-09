// from server: 100% by EspClaude
// roc 2009-06 006bb720  unit: RBX::Lua::LuaArguments  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006bb720
//
// 006bb720  83ec0c               sub esp, 0xc
// 006bb723  56                   push esi
// 006bb724  6a00                 push 0
// 006bb726  687829a200           push 0xa22978
// 006bb72b  8bf1                 mov esi, ecx
// 006bb72d  8b06                 mov eax, dword ptr [esi]
// 006bb72f  6874c29d00           push 0x9dc274
// 006bb734  6a00                 push 0
// 006bb736  50                   push eax
// 006bb737  e83ee50500           call 0x719c7a
// 006bb73c  83c414               add esp, 0x14
// 006bb73f  85c0                 test eax, eax
// 006bb741  751e                 jne 0x6bb761
// 006bb743  6850d38a00           push 0x8ad350
// 006bb748  8d4c2408             lea ecx, [esp + 8]
// 006bb74c  ff1570e98900         call dword ptr [0x89e970]
// 006bb752  68b04b9800           push 0x984bb0
// 006bb757  8d442408             lea eax, [esp + 8]
// 006bb75b  50                   push eax
// 006bb75c  e8e9e20500           call 0x719a4a
// 006bb761  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006bb765  8b4018               mov eax, dword ptr [eax + 0x18]
// 006bb768  8b10                 mov edx, dword ptr [eax]
// 006bb76a  8b520c               mov edx, dword ptr [edx + 0xc]
// 006bb76d  51                   push ecx
// 006bb76e  8b4e04               mov ecx, dword ptr [esi + 4]
// 006bb771  51                   push ecx
// 006bb772  8bc8                 mov ecx, eax
// 006bb774  ffd2                 call edx
// 006bb776  5e                   pop esi
// 006bb777  83c40c               add esp, 0xc
// 006bb77a  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABVFunctionRef@Lua@RBX@@@Z)

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
namespace RBX { class BrickColor; namespace Lua { class FunctionRef; } }
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const RBX::Lua::FunctionRef&); };
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
    void set(const RBX::Lua::FunctionRef& value);
};
void ChangePropertyItem::set(const RBX::Lua::FunctionRef& value)
{
    RBX::Reflection::TypedPropertyDescriptor<RBX::Lua::FunctionRef>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<RBX::Lua::FunctionRef>*>(descriptor);
    typed->accessor->set(instance, value);
}