// from server: 100% by EspClaude
// roc 2009-06 004e4e30  unit: CRobloxWnd::UserInputJob  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e4e30
//
// 004e4e30  83ec0c               sub esp, 0xc
// 004e4e33  56                   push esi
// 004e4e34  6a00                 push 0
// 004e4e36  6838c29d00           push 0x9dc238
// 004e4e3b  8bf1                 mov esi, ecx
// 004e4e3d  8b06                 mov eax, dword ptr [esi]
// 004e4e3f  6874c29d00           push 0x9dc274
// 004e4e44  6a00                 push 0
// 004e4e46  50                   push eax
// 004e4e47  e82e4e2300           call 0x719c7a
// 004e4e4c  83c414               add esp, 0x14
// 004e4e4f  85c0                 test eax, eax
// 004e4e51  751e                 jne 0x4e4e71
// 004e4e53  6850d38a00           push 0x8ad350
// 004e4e58  8d4c2408             lea ecx, [esp + 8]
// 004e4e5c  ff1570e98900         call dword ptr [0x89e970]
// 004e4e62  68b04b9800           push 0x984bb0
// 004e4e67  8d442408             lea eax, [esp + 8]
// 004e4e6b  50                   push eax
// 004e4e6c  e8d94b2300           call 0x719a4a
// 004e4e71  8b4818               mov ecx, dword ptr [eax + 0x18]
// 004e4e74  8b7604               mov esi, dword ptr [esi + 4]
// 004e4e77  8b11                 mov edx, dword ptr [ecx]
// 004e4e79  8b4208               mov eax, dword ptr [edx + 8]
// 004e4e7c  56                   push esi
// 004e4e7d  ffd0                 call eax
// 004e4e7f  5e                   pop esi
// 004e4e80  83c40c               add esp, 0xc
// 004e4e83  c3                   ret 
// copied from an identical function in another client (function ?get@ChangePropertyItem@@QAEHXZ)

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
struct AccessorT { virtual void s0() = 0; virtual void s1() = 0; virtual int get(void*) = 0; };
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
    int get();
};
int ChangePropertyItem::get()
{
    RBX::Reflection::TypedPropertyDescriptor<bool>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<bool>*>(descriptor);
    AccessorT* accessor = typed->accessor;
    void* object = instance;
    return accessor->get(object);
}