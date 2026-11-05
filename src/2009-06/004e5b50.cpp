// from server: 100% by EspClaude
// roc 2009-06 004e5b50  unit: CRobloxWnd::UserInputJob  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e5b50
//
// 004e5b50  83ec0c               sub esp, 0xc
// 004e5b53  56                   push esi
// 004e5b54  6a00                 push 0
// 004e5b56  68f41e9f00           push 0x9f1ef4
// 004e5b5b  8bf1                 mov esi, ecx
// 004e5b5d  8b06                 mov eax, dword ptr [esi]
// 004e5b5f  6874c29d00           push 0x9dc274
// 004e5b64  6a00                 push 0
// 004e5b66  50                   push eax
// 004e5b67  e80e412300           call 0x719c7a
// 004e5b6c  83c414               add esp, 0x14
// 004e5b6f  85c0                 test eax, eax
// 004e5b71  751e                 jne 0x4e5b91
// 004e5b73  6850d38a00           push 0x8ad350
// 004e5b78  8d4c2408             lea ecx, [esp + 8]
// 004e5b7c  ff1570e98900         call dword ptr [0x89e970]
// 004e5b82  68b04b9800           push 0x984bb0
// 004e5b87  8d442408             lea eax, [esp + 8]
// 004e5b8b  50                   push eax
// 004e5b8c  e8b93e2300           call 0x719a4a
// 004e5b91  8b4818               mov ecx, dword ptr [eax + 0x18]
// 004e5b94  8b7604               mov esi, dword ptr [esi + 4]
// 004e5b97  8b11                 mov edx, dword ptr [ecx]
// 004e5b99  8b4208               mov eax, dword ptr [edx + 8]
// 004e5b9c  56                   push esi
// 004e5b9d  ffd0                 call eax
// 004e5b9f  5e                   pop esi
// 004e5ba0  83c40c               add esp, 0xc
// 004e5ba3  c3                   ret 
// copied from an identical function in another client (function ?get@ChangePropertyItem@@QAENXZ)

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
struct AccessorT { virtual void s0() = 0; virtual void s1() = 0; virtual double get(void*) = 0; };
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
    double get();
};
double ChangePropertyItem::get()
{
    RBX::Reflection::TypedPropertyDescriptor<double>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<double>*>(descriptor);
    AccessorT* accessor = typed->accessor;
    void* object = instance;
    return accessor->get(object);
}