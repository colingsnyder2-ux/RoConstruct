// from server: 100% by EspClaude
// roc 2009-06 004c01c0  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c01c0
//
// 004c01c0  8b442404             mov eax, dword ptr [esp + 4]
// 004c01c4  83ec0c               sub esp, 0xc
// 004c01c7  6a00                 push 0
// 004c01c9  6820ed9e00           push 0x9eed20
// 004c01ce  68c4bf9d00           push 0x9dbfc4
// 004c01d3  6a00                 push 0
// 004c01d5  50                   push eax
// 004c01d6  e89f9a2500           call 0x719c7a
// 004c01db  83c414               add esp, 0x14
// 004c01de  85c0                 test eax, eax
// 004c01e0  751e                 jne 0x4c0200
// 004c01e2  6850d38a00           push 0x8ad350
// 004c01e7  8d4c2404             lea ecx, [esp + 4]
// 004c01eb  ff1570e98900         call dword ptr [0x89e970]
// 004c01f1  68b04b9800           push 0x984bb0
// 004c01f6  8d4c2404             lea ecx, [esp + 4]
// 004c01fa  51                   push ecx
// 004c01fb  e84a982500           call 0x719a4a
// 004c0200  83c40c               add esp, 0xc
// 004c0203  c3                   ret 
// copied from an identical function in another client (function ??$polymorphic_cast@PAVPlayer@Network@RBX@@VDescribedBase@Reflection@3@@boost@@YAPAVPlayer@Network@RBX@@PAVDescribedBase@Reflection@3@@Z)

#include <typeinfo>
namespace RBX { namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; } }
namespace RBX { namespace Network { class Player : public RBX::Reflection::DescribedBase { }; } }
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

template RBX::Network::Player* boost::polymorphic_cast<RBX::Network::Player*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);