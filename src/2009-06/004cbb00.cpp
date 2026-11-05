// from server: 100% by EspClaude
// roc 2009-06 004cbb00  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004cbb00
//
// 004cbb00  8b442404             mov eax, dword ptr [esp + 4]
// 004cbb04  83ec0c               sub esp, 0xc
// 004cbb07  56                   push esi
// 004cbb08  6a00                 push 0
// 004cbb0a  6898009f00           push 0x9f0098
// 004cbb0f  68c4bf9d00           push 0x9dbfc4
// 004cbb14  6a00                 push 0
// 004cbb16  50                   push eax
// 004cbb17  8bf1                 mov esi, ecx
// 004cbb19  e85ce12400           call 0x719c7a
// 004cbb1e  83c414               add esp, 0x14
// 004cbb21  85c0                 test eax, eax
// 004cbb23  751e                 jne 0x4cbb43
// 004cbb25  6850d38a00           push 0x8ad350
// 004cbb2a  8d4c2408             lea ecx, [esp + 8]
// 004cbb2e  ff1570e98900         call dword ptr [0x89e970]
// 004cbb34  68b04b9800           push 0x984bb0
// 004cbb39  8d4c2408             lea ecx, [esp + 8]
// 004cbb3d  51                   push ecx
// 004cbb3e  e807df2400           call 0x719a4a
// 004cbb43  8b542418             mov edx, dword ptr [esp + 0x18]
// 004cbb47  83c204               add edx, 4
// 004cbb4a  52                   push edx
// 004cbb4b  50                   push eax
// 004cbb4c  8bce                 mov ecx, esi
// 004cbb4e  e85d871000           call 0x5d42b0
// 004cbb53  5e                   pop esi
// 004cbb54  83c40c               add esp, 0xc
// 004cbb57  c20800               ret 8
// copied from an identical function in another client (function ?invoke@Holder@@QAEXPAVDescribedBase@Reflection@RBX@@PAUArg@@@Z)

#include <typeinfo>
namespace RBX { namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; } }
namespace RBX { namespace Network { class Players : public RBX::Reflection::DescribedBase { }; } }
struct Arg { int header; int member; };
struct Holder {
    void apply(RBX::Network::Players* object, int* value);
    void invoke(RBX::Reflection::DescribedBase* source, Arg* arg);
};

void Holder::invoke(RBX::Reflection::DescribedBase* source, Arg* arg)
{
    RBX::Network::Players* object = dynamic_cast<RBX::Network::Players*>(source);
    if (!object)
        throw std::bad_cast("bad cast");
    apply(object, &arg->member);
}