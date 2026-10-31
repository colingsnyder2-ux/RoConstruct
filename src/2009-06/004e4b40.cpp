// from server: 100% by EspClaude
// roc 2009-06 004e4b40  unit: CRobloxWnd::UserInputJob  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e4b40
//
// 004e4b40  83ec0c               sub esp, 0xc
// 004e4b43  56                   push esi
// 004e4b44  6a00                 push 0
// 004e4b46  6830259e00           push 0x9e2530
// 004e4b4b  8bf1                 mov esi, ecx
// 004e4b4d  8b06                 mov eax, dword ptr [esi]
// 004e4b4f  6874c29d00           push 0x9dc274
// 004e4b54  6a00                 push 0
// 004e4b56  50                   push eax
// 004e4b57  e81e512300           call 0x719c7a
// 004e4b5c  83c414               add esp, 0x14
// 004e4b5f  85c0                 test eax, eax
// 004e4b61  751e                 jne 0x4e4b81
// 004e4b63  6850d38a00           push 0x8ad350
// 004e4b68  8d4c2408             lea ecx, [esp + 8]
// 004e4b6c  ff1570e98900         call dword ptr [0x89e970]
// 004e4b72  68b04b9800           push 0x984bb0
// 004e4b77  8d442408             lea eax, [esp + 8]
// 004e4b7b  50                   push eax
// 004e4b7c  e8c94e2300           call 0x719a4a
// 004e4b81  8b4818               mov ecx, dword ptr [eax + 0x18]
// 004e4b84  8b4604               mov eax, dword ptr [esi + 4]
// 004e4b87  8b11                 mov edx, dword ptr [ecx]
// 004e4b89  8b742414             mov esi, dword ptr [esp + 0x14]
// 004e4b8d  8b5208               mov edx, dword ptr [edx + 8]
// 004e4b90  50                   push eax
// 004e4b91  56                   push esi
// 004e4b92  ffd2                 call edx
// 004e4b94  8bc6                 mov eax, esi
// 004e4b96  5e                   pop esi
// 004e4b97  83c40c               add esp, 0xc
// 004e4b9a  c20400               ret 4
// copied from an identical function in another client (function ?get@ChangePropertyItem@@QAE?AVVector3@G3D@@XZ)

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
namespace G3D { class Color3; class Vector3 { float x,y,z; }; }
namespace RBX { class BrickColor; namespace Soundscape { class SoundId; } }
struct AccessorT { virtual void s0() = 0; virtual void s1() = 0; virtual G3D::Vector3 get(void*) = 0; };
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
    G3D::Vector3 get();
};
G3D::Vector3 ChangePropertyItem::get()
{
    RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>* typed = boost::polymorphic_cast<RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>*>(descriptor);
    AccessorT* accessor = typed->accessor;
    void* object = instance;
    return accessor->get(object);
}