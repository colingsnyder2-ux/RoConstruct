// from server: 100% by EspClaude
// roc 2009-06 006bb380  unit: RBX::Lua::LuaArguments  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006bb380
//
// 006bb380  83ec0c               sub esp, 0xc
// 006bb383  56                   push esi
// 006bb384  6a00                 push 0
// 006bb386  68202a9e00           push 0x9e2a20
// 006bb38b  8bf1                 mov esi, ecx
// 006bb38d  8b06                 mov eax, dword ptr [esi]
// 006bb38f  6874c29d00           push 0x9dc274
// 006bb394  6a00                 push 0
// 006bb396  50                   push eax
// 006bb397  e8dee80500           call 0x719c7a
// 006bb39c  83c414               add esp, 0x14
// 006bb39f  85c0                 test eax, eax
// 006bb3a1  751e                 jne 0x6bb3c1
// 006bb3a3  6850d38a00           push 0x8ad350
// 006bb3a8  8d4c2408             lea ecx, [esp + 8]
// 006bb3ac  ff1570e98900         call dword ptr [0x89e970]
// 006bb3b2  68b04b9800           push 0x984bb0
// 006bb3b7  8d442408             lea eax, [esp + 8]
// 006bb3bb  50                   push eax
// 006bb3bc  e889e60500           call 0x719a4a
// 006bb3c1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006bb3c5  8b4018               mov eax, dword ptr [eax + 0x18]
// 006bb3c8  8b10                 mov edx, dword ptr [eax]
// 006bb3ca  8b520c               mov edx, dword ptr [edx + 0xc]
// 006bb3cd  51                   push ecx
// 006bb3ce  8b4e04               mov ecx, dword ptr [esi + 4]
// 006bb3d1  51                   push ecx
// 006bb3d2  8bc8                 mov ecx, eax
// 006bb3d4  ffd2                 call edx
// 006bb3d6  5e                   pop esi
// 006bb3d7  83c40c               add esp, 0xc
// 006bb3da  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <typeinfo>
#include <string>
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
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const std::string&); };
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
    void set(const std::string& value);
};
void ChangePropertyItem::set(const std::string& value)
{
    RBX::Reflection::TypedPropertyDescriptor<std::string>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<std::string>*>(descriptor);
    typed->accessor->set(instance, value);
}