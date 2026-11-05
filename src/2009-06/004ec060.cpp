// from server: 100% by EspClaude
// roc 2009-06 004ec060  unit: RBX::Network::VReplicator::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ec060
//
// 004ec060  8b442404             mov eax, dword ptr [esp + 4]
// 004ec064  83ec0c               sub esp, 0xc
// 004ec067  56                   push esi
// 004ec068  6a00                 push 0
// 004ec06a  680c259f00           push 0x9f250c
// 004ec06f  68c4bf9d00           push 0x9dbfc4
// 004ec074  6a00                 push 0
// 004ec076  50                   push eax
// 004ec077  8bf1                 mov esi, ecx
// 004ec079  e8fcdb2200           call 0x719c7a
// 004ec07e  83c414               add esp, 0x14
// 004ec081  85c0                 test eax, eax
// 004ec083  751e                 jne 0x4ec0a3
// 004ec085  6850d38a00           push 0x8ad350
// 004ec08a  8d4c2408             lea ecx, [esp + 8]
// 004ec08e  ff1570e98900         call dword ptr [0x89e970]
// 004ec094  68b04b9800           push 0x984bb0
// 004ec099  8d4c2408             lea ecx, [esp + 8]
// 004ec09d  51                   push ecx
// 004ec09e  e8a7d92200           call 0x719a4a
// 004ec0a3  8b542418             mov edx, dword ptr [esp + 0x18]
// 004ec0a7  83c204               add edx, 4
// 004ec0aa  52                   push edx
// 004ec0ab  50                   push eax
// 004ec0ac  8bce                 mov ecx, esi
// 004ec0ae  e8cd3d0e00           call 0x5cfe80
// 004ec0b3  5e                   pop esi
// 004ec0b4  83c40c               add esp, 0xc
// 004ec0b7  c20800               ret 8
// copied from an identical function in another client (function ?invoke@Holder@@QAEXPAVDescribedBase@Reflection@RBX@@PAUArg@@@Z)

#include <typeinfo>
namespace RBX { namespace Reflection { class DescribedBase { public: virtual ~DescribedBase(); }; } }
namespace RBX { namespace Network { class Replicator : public RBX::Reflection::DescribedBase { }; } }
struct Arg { int header; int member; };
struct Holder {
    void apply(RBX::Network::Replicator* object, int* value);
    void invoke(RBX::Reflection::DescribedBase* source, Arg* arg);
};

void Holder::invoke(RBX::Reflection::DescribedBase* source, Arg* arg)
{
    RBX::Network::Replicator* object = dynamic_cast<RBX::Network::Replicator*>(source);
    if (!object)
        throw std::bad_cast("bad cast");
    apply(object, &arg->member);
}