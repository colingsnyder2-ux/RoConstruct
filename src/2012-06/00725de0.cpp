// from server: 100% by Xemicl
// roc 2012-06 00725de0  unit: RBX::Workspace  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00725de0
//
// 00725de0  8b442404             mov eax, dword ptr [esp + 4]
// 00725de4  83ec0c               sub esp, 0xc
// 00725de7  6a00                 push 0
// 00725de9  683ca4d900           push 0xd9a43c
// 00725dee  68ac03d600           push 0xd603ac
// 00725df3  6a00                 push 0
// 00725df5  50                   push eax
// 00725df6  e84dd62500           call 0x983448
// 00725dfb  83c414               add esp, 0x14
// 00725dfe  85c0                 test eax, eax
// 00725e00  751e                 jne 0x725e20
// 00725e02  682841b400           push 0xb44128
// 00725e07  8d4c2404             lea ecx, [esp + 4]
// 00725e0b  ff15202ab200         call dword ptr [0xb22a20]
// 00725e11  68c0d5cd00           push 0xcdd5c0
// 00725e16  8d4c2404             lea ecx, [esp + 4]
// 00725e1a  51                   push ecx
// 00725e1b  e824d32500           call 0x983144
// 00725e20  83c40c               add esp, 0xc
// 00725e23  c3                   ret 
// copied from an identical function in another client (function ??$polymorphic_cast@PAVCamera@RBX@@VDescribedBase@Reflection@2@@boost@@YAPAVCamera@RBX@@PAVDescribedBase@Reflection@2@@Z)

#include <typeinfo>
namespace RBX { namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; } }
namespace RBX { class Camera : public RBX::Reflection::DescribedBase { }; }
namespace boost {
template<class Target, class Source>
Target polymorphic_cast(Source* x)
{
    Target tmp = dynamic_cast<Target>(x);
    if (tmp == 0)
        throw std::bad_cast("bad cast");
    return tmp;
}
}

template RBX::Camera* boost::polymorphic_cast<RBX::Camera*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);