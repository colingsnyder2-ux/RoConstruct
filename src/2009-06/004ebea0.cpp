// from server: 100% by EspClaude
// roc 2009-06 004ebea0  unit: RBX::Network::VReplicator::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ebea0
//
// 004ebea0  8b442404             mov eax, dword ptr [esp + 4]
// 004ebea4  83ec0c               sub esp, 0xc
// 004ebea7  56                   push esi
// 004ebea8  6a00                 push 0
// 004ebeaa  680c259f00           push 0x9f250c
// 004ebeaf  68c4bf9d00           push 0x9dbfc4
// 004ebeb4  6a00                 push 0
// 004ebeb6  50                   push eax
// 004ebeb7  8bf1                 mov esi, ecx
// 004ebeb9  e8bcdd2200           call 0x719c7a
// 004ebebe  83c414               add esp, 0x14
// 004ebec1  85c0                 test eax, eax
// 004ebec3  751e                 jne 0x4ebee3
// 004ebec5  6850d38a00           push 0x8ad350
// 004ebeca  8d4c2408             lea ecx, [esp + 8]
// 004ebece  ff1570e98900         call dword ptr [0x89e970]
// 004ebed4  68b04b9800           push 0x984bb0
// 004ebed9  8d4c2408             lea ecx, [esp + 8]
// 004ebedd  51                   push ecx
// 004ebede  e867db2200           call 0x719a4a
// 004ebee3  8b542418             mov edx, dword ptr [esp + 0x18]
// 004ebee7  83c204               add edx, 4
// 004ebeea  52                   push edx
// 004ebeeb  50                   push eax
// 004ebeec  8bce                 mov ecx, esi
// 004ebeee  e80dffffff           call 0x4ebe00
// 004ebef3  5e                   pop esi
// 004ebef4  83c40c               add esp, 0xc
// 004ebef7  c20800               ret 8
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