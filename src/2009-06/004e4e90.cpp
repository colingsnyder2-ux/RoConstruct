// from server: 100% by EspClaude
// roc 2009-06 004e4e90  unit: CRobloxWnd::UserInputJob  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e4e90
//
// 004e4e90  83ec0c               sub esp, 0xc
// 004e4e93  56                   push esi
// 004e4e94  6a00                 push 0
// 004e4e96  6810269e00           push 0x9e2610
// 004e4e9b  8bf1                 mov esi, ecx
// 004e4e9d  8b06                 mov eax, dword ptr [esi]
// 004e4e9f  6874c29d00           push 0x9dc274
// 004e4ea4  6a00                 push 0
// 004e4ea6  50                   push eax
// 004e4ea7  e8ce4d2300           call 0x719c7a
// 004e4eac  83c414               add esp, 0x14
// 004e4eaf  85c0                 test eax, eax
// 004e4eb1  751e                 jne 0x4e4ed1
// 004e4eb3  6850d38a00           push 0x8ad350
// 004e4eb8  8d4c2408             lea ecx, [esp + 8]
// 004e4ebc  ff1570e98900         call dword ptr [0x89e970]
// 004e4ec2  68b04b9800           push 0x984bb0
// 004e4ec7  8d442408             lea eax, [esp + 8]
// 004e4ecb  50                   push eax
// 004e4ecc  e8794b2300           call 0x719a4a
// 004e4ed1  8b4818               mov ecx, dword ptr [eax + 0x18]
// 004e4ed4  8b7604               mov esi, dword ptr [esi + 4]
// 004e4ed7  8b11                 mov edx, dword ptr [ecx]
// 004e4ed9  8b4208               mov eax, dword ptr [edx + 8]
// 004e4edc  56                   push esi
// 004e4edd  ffd0                 call eax
// 004e4edf  5e                   pop esi
// 004e4ee0  83c40c               add esp, 0xc
// 004e4ee3  c3                   ret 
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
    RBX::Reflection::TypedPropertyDescriptor<int>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<int>*>(descriptor);
    AccessorT* accessor = typed->accessor;
    void* object = instance;
    return accessor->get(object);
}