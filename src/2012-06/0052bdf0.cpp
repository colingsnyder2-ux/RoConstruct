// from server: 100% by Xemicl
// roc 2012-06 0052bdf0  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0052bdf0
//
// 0052bdf0  8b442404             mov eax, dword ptr [esp + 4]
// 0052bdf4  83ec0c               sub esp, 0xc
// 0052bdf7  6a00                 push 0
// 0052bdf9  6864d3d700           push 0xd7d364
// 0052bdfe  68ac03d600           push 0xd603ac
// 0052be03  6a00                 push 0
// 0052be05  50                   push eax
// 0052be06  e83d764500           call 0x983448
// 0052be0b  83c414               add esp, 0x14
// 0052be0e  85c0                 test eax, eax
// 0052be10  751e                 jne 0x52be30
// 0052be12  682841b400           push 0xb44128
// 0052be17  8d4c2404             lea ecx, [esp + 4]
// 0052be1b  ff15202ab200         call dword ptr [0xb22a20]
// 0052be21  68c0d5cd00           push 0xcdd5c0
// 0052be26  8d4c2404             lea ecx, [esp + 4]
// 0052be2a  51                   push ecx
// 0052be2b  e814734500           call 0x983144
// 0052be30  83c40c               add esp, 0xc
// 0052be33  c3                   ret 
// copied from an identical function in another client (function ??$polymorphic_cast@PAVModelInstance@RBX@@VDescribedBase@Reflection@2@@boost@@YAPAVModelInstance@RBX@@PAVDescribedBase@Reflection@2@@Z)

#include <typeinfo>
namespace RBX { namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; } }
namespace RBX { class ModelInstance : public RBX::Reflection::DescribedBase { }; }
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

template RBX::ModelInstance* boost::polymorphic_cast<RBX::ModelInstance*, RBX::Reflection::DescribedBase>(RBX::Reflection::DescribedBase*);