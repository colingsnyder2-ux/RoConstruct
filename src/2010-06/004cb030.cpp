// from server: 100% by Yeetserama
// roc 2010-06 004cb030  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004cb030
//
// 004cb030  8b442404             mov eax, dword ptr [esp + 4]
// 004cb034  83ec0c               sub esp, 0xc
// 004cb037  56                   push esi
// 004cb038  6a00                 push 0
// 004cb03a  68d873b800           push 0xb873d8
// 004cb03f  684090b700           push 0xb79040
// 004cb044  6a00                 push 0
// 004cb046  50                   push eax
// 004cb047  8bf1                 mov esi, ecx
// 004cb049  e89cdb2d00           call 0x7a8bea
// 004cb04e  83c414               add esp, 0x14
// 004cb051  85c0                 test eax, eax
// 004cb053  751e                 jne 0x4cb073
// 004cb055  68540aa000           push 0xa00a54
// 004cb05a  8d4c2408             lea ecx, [esp + 8]
// 004cb05e  ff159ca89e00         call dword ptr [0x9ea89c]
// 004cb064  689022b100           push 0xb12290
// 004cb069  8d4c2408             lea ecx, [esp + 8]
// 004cb06d  51                   push ecx
// 004cb06e  e83fd92d00           call 0x7a89b2
// 004cb073  8b542418             mov edx, dword ptr [esp + 0x18]
// 004cb077  83c204               add edx, 4
// 004cb07a  52                   push edx
// 004cb07b  50                   push eax
// 004cb07c  8bce                 mov ecx, esi
// 004cb07e  e8edaf1800           call 0x656070
// 004cb083  5e                   pop esi
// 004cb084  83c40c               add esp, 0xc
// 004cb087  c20800               ret 8
// copied from an identical function in another client (function ?invoke@Holder@@QAEXPAVDescribedBase@Reflection@RBX@@PAUArg@@@Z)

// from server: 100% by tester
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