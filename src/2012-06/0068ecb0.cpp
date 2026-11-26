// from server: 100% by Xemicl
// roc 2012-06 0068ecb0  unit: RBX::ModelInstance  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0068ecb0
//
// 0068ecb0  8b442404             mov eax, dword ptr [esp + 4]
// 0068ecb4  83ec0c               sub esp, 0xc
// 0068ecb7  6a00                 push 0
// 0068ecb9  68604cd900           push 0xd94c60
// 0068ecbe  68ac03d600           push 0xd603ac
// 0068ecc3  6a00                 push 0
// 0068ecc5  50                   push eax
// 0068ecc6  e87d472f00           call 0x983448
// 0068eccb  83c414               add esp, 0x14
// 0068ecce  85c0                 test eax, eax
// 0068ecd0  751e                 jne 0x68ecf0
// 0068ecd2  682841b400           push 0xb44128
// 0068ecd7  8d4c2404             lea ecx, [esp + 4]
// 0068ecdb  ff15202ab200         call dword ptr [0xb22a20]
// 0068ece1  68c0d5cd00           push 0xcdd5c0
// 0068ece6  8d4c2404             lea ecx, [esp + 4]
// 0068ecea  51                   push ecx
// 0068eceb  e854442f00           call 0x983144
// 0068ecf0  83c40c               add esp, 0xc
// 0068ecf3  c3                   ret 
// copied from an identical function in another client (function ??$polymorphic_cast@PAVPartInstance@RBX@@VDescribedBase@Reflection@2@@boost@@YAPAVPartInstance@RBX@@PAVDescribedBase@Reflection@2@@Z)

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