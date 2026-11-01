// from server: 100% by Yeetserama
// roc 2010-06 005e9220  unit: G3D::VCoordinateFrame::?$TypedPropertyDescriptor  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e9220
//
// 005e9220  8b442404             mov eax, dword ptr [esp + 4]
// 005e9224  83ec0c               sub esp, 0xc
// 005e9227  6a00                 push 0
// 005e9229  68c0c8b700           push 0xb7c8c0
// 005e922e  684090b700           push 0xb79040
// 005e9233  6a00                 push 0
// 005e9235  50                   push eax
// 005e9236  e8aff91b00           call 0x7a8bea
// 005e923b  83c414               add esp, 0x14
// 005e923e  85c0                 test eax, eax
// 005e9240  751e                 jne 0x5e9260
// 005e9242  68540aa000           push 0xa00a54
// 005e9247  8d4c2404             lea ecx, [esp + 4]
// 005e924b  ff159ca89e00         call dword ptr [0x9ea89c]
// 005e9251  689022b100           push 0xb12290
// 005e9256  8d4c2404             lea ecx, [esp + 4]
// 005e925a  51                   push ecx
// 005e925b  e852f71b00           call 0x7a89b2
// 005e9260  83c40c               add esp, 0xc
// 005e9263  c3                   ret 
// copied from an identical function in another client (function ??$polymorphic_cast@PAVPartInstance@RBX@@VDescribedBase@Reflection@2@@boost@@YAPAVPartInstance@RBX@@PAVDescribedBase@Reflection@2@@Z)

// from server: 100% by tester
#include <typeinfo>
namespace RBX { namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; } }
namespace RBX { class PartInstance : public RBX::Reflection::DescribedBase { }; }
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

template RBX::PartInstance* boost::polymorphic_cast<RBX::PartInstance*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);