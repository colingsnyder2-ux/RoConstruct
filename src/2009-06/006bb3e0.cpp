// from server: 100% by EspClaude
// roc 2009-06 006bb3e0  unit: RBX::Lua::LuaArguments  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006bb3e0
//
// 006bb3e0  83ec0c               sub esp, 0xc
// 006bb3e3  56                   push esi
// 006bb3e4  6a00                 push 0
// 006bb3e6  6828249e00           push 0x9e2428
// 006bb3eb  8bf1                 mov esi, ecx
// 006bb3ed  8b06                 mov eax, dword ptr [esi]
// 006bb3ef  6874c29d00           push 0x9dc274
// 006bb3f4  6a00                 push 0
// 006bb3f6  50                   push eax
// 006bb3f7  e87ee80500           call 0x719c7a
// 006bb3fc  83c414               add esp, 0x14
// 006bb3ff  85c0                 test eax, eax
// 006bb401  751e                 jne 0x6bb421
// 006bb403  6850d38a00           push 0x8ad350
// 006bb408  8d4c2408             lea ecx, [esp + 8]
// 006bb40c  ff1570e98900         call dword ptr [0x89e970]
// 006bb412  68b04b9800           push 0x984bb0
// 006bb417  8d442408             lea eax, [esp + 8]
// 006bb41b  50                   push eax
// 006bb41c  e829e60500           call 0x719a4a
// 006bb421  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006bb425  8b4018               mov eax, dword ptr [eax + 0x18]
// 006bb428  8b10                 mov edx, dword ptr [eax]
// 006bb42a  8b520c               mov edx, dword ptr [edx + 0xc]
// 006bb42d  51                   push ecx
// 006bb42e  8b4e04               mov ecx, dword ptr [esi + 4]
// 006bb431  51                   push ecx
// 006bb432  8bc8                 mov ecx, eax
// 006bb434  ffd2                 call edx
// 006bb436  5e                   pop esi
// 006bb437  83c40c               add esp, 0xc
// 006bb43a  c20400               ret 4
// copied from an identical function in another client (function ?set@ChangePropertyItem@@QAEXABVSoundId@Soundscape@RBX@@@Z)

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
struct AccessorT { virtual void s0(); virtual void s1(); virtual void s2(); virtual void set(void*, const RBX::Soundscape::SoundId&); };
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
    void set(const RBX::Soundscape::SoundId& value);
};
void ChangePropertyItem::set(const RBX::Soundscape::SoundId& value)
{
    RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>*>(descriptor);
    typed->accessor->set(instance, value);
}