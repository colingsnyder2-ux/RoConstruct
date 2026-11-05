// from server: 100% by Yeetserama
// roc 2011-06 0060d1d0  unit: G3D::VCoordinateFrame::?$TypedPropertyDescriptor  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0060d1d0
//
// 0060d1d0  8b442404             mov eax, dword ptr [esp + 4]
// 0060d1d4  83ec0c               sub esp, 0xc
// 0060d1d7  6a00                 push 0
// 0060d1d9  68ecbec000           push 0xc0beec
// 0060d1de  68f873c000           push 0xc073f8
// 0060d1e3  6a00                 push 0
// 0060d1e5  50                   push eax
// 0060d1e6  e8ffe01f00           call 0x80b2ea
// 0060d1eb  83c414               add esp, 0x14
// 0060d1ee  85c0                 test eax, eax
// 0060d1f0  751e                 jne 0x60d210
// 0060d1f2  680cc1a500           push 0xa5c10c
// 0060d1f7  8d4c2404             lea ecx, [esp + 4]
// 0060d1fb  ff15100aa400         call dword ptr [0xa40a10]
// 0060d201  68fc89b900           push 0xb989fc
// 0060d206  8d4c2404             lea ecx, [esp + 4]
// 0060d20a  51                   push ecx
// 0060d20b  e89cde1f00           call 0x80b0ac
// 0060d210  83c40c               add esp, 0xc
// 0060d213  c3                   ret 
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