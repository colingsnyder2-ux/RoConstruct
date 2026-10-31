// from server: 100% by EspClaude
// roc 2009-06 004de440  unit: RBX::Network::IdSerializer  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004de440
//
// 004de440  83ec0c               sub esp, 0xc
// 004de443  56                   push esi
// 004de444  6a00                 push 0
// 004de446  6878259e00           push 0x9e2578
// 004de44b  8bf1                 mov esi, ecx
// 004de44d  8b06                 mov eax, dword ptr [esi]
// 004de44f  6874c29d00           push 0x9dc274
// 004de454  6a00                 push 0
// 004de456  50                   push eax
// 004de457  e81eb82300           call 0x719c7a
// 004de45c  83c414               add esp, 0x14
// 004de45f  85c0                 test eax, eax
// 004de461  751e                 jne 0x4de481
// 004de463  6850d38a00           push 0x8ad350
// 004de468  8d4c2408             lea ecx, [esp + 8]
// 004de46c  ff1570e98900         call dword ptr [0x89e970]
// 004de472  68b04b9800           push 0x984bb0
// 004de477  8d442408             lea eax, [esp + 8]
// 004de47b  50                   push eax
// 004de47c  e8c9b52300           call 0x719a4a
// 004de481  8b4818               mov ecx, dword ptr [eax + 0x18]
// 004de484  8b4604               mov eax, dword ptr [esi + 4]
// 004de487  8b11                 mov edx, dword ptr [ecx]
// 004de489  8b742414             mov esi, dword ptr [esp + 0x14]
// 004de48d  8b5208               mov edx, dword ptr [edx + 8]
// 004de490  50                   push eax
// 004de491  56                   push esi
// 004de492  ffd2                 call edx
// 004de494  8bc6                 mov eax, esi
// 004de496  5e                   pop esi
// 004de497  83c40c               add esp, 0xc
// 004de49a  c20400               ret 4
// copied from an identical function in another client (function ?get@ChangePropertyItem@@QAEPAXPAX@Z)

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
struct AccessorT { virtual void s0(); virtual void s1(); virtual void get(void*, void*); };
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
    void* get(void* result);
};
void* ChangePropertyItem::get(void* result)
{
    RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>*>(descriptor);
    typed->accessor->get(result, instance);
    return result;
}