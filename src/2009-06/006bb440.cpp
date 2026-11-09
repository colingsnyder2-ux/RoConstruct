// from server: 100% by EspClaude
// roc 2009-06 006bb440  unit: RBX::Lua::LuaArguments  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006bb440
//
// 006bb440  83ec0c               sub esp, 0xc
// 006bb443  56                   push esi
// 006bb444  6a00                 push 0
// 006bb446  6880249e00           push 0x9e2480
// 006bb44b  8bf1                 mov esi, ecx
// 006bb44d  8b06                 mov eax, dword ptr [esi]
// 006bb44f  6874c29d00           push 0x9dc274
// 006bb454  6a00                 push 0
// 006bb456  50                   push eax
// 006bb457  e81ee80500           call 0x719c7a
// 006bb45c  83c414               add esp, 0x14
// 006bb45f  85c0                 test eax, eax
// 006bb461  751e                 jne 0x6bb481
// 006bb463  6850d38a00           push 0x8ad350
// 006bb468  8d4c2408             lea ecx, [esp + 8]
// 006bb46c  ff1570e98900         call dword ptr [0x89e970]
// 006bb472  68b04b9800           push 0x984bb0
// 006bb477  8d442408             lea eax, [esp + 8]
// 006bb47b  50                   push eax
// 006bb47c  e8c9e50500           call 0x719a4a
// 006bb481  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006bb485  8b4018               mov eax, dword ptr [eax + 0x18]
// 006bb488  8b10                 mov edx, dword ptr [eax]
// 006bb48a  8b520c               mov edx, dword ptr [edx + 0xc]
// 006bb48d  51                   push ecx
// 006bb48e  8b4e04               mov ecx, dword ptr [esi + 4]
// 006bb491  51                   push ecx
// 006bb492  8bc8                 mov ecx, eax
// 006bb494  ffd2                 call edx
// 006bb496  5e                   pop esi
// 006bb497  83c40c               add esp, 0xc
// 006bb49a  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABVTextureId@RBX@@@Z)

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
namespace RBX { class Instance; class TextureId; }
namespace G3D { class Color3; class Vector3; }
namespace RBX { class BrickColor; }
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const RBX::TextureId&); };
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
    void set(const RBX::TextureId& value);
};
void ChangePropertyItem::set(const RBX::TextureId& value)
{
    RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>*>(descriptor);
    typed->accessor->set(instance, value);
}