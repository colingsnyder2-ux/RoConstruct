// from server: 100% by Yeetserama
// roc 2010-06 004f33e0  unit: RBX::Network::VReplicator::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004f33e0
//
// 004f33e0  8b442404             mov eax, dword ptr [esp + 4]
// 004f33e4  83ec0c               sub esp, 0xc
// 004f33e7  56                   push esi
// 004f33e8  6a00                 push 0
// 004f33ea  68ac0cb900           push 0xb90cac
// 004f33ef  684090b700           push 0xb79040
// 004f33f4  6a00                 push 0
// 004f33f6  50                   push eax
// 004f33f7  8bf1                 mov esi, ecx
// 004f33f9  e8ec572b00           call 0x7a8bea
// 004f33fe  83c414               add esp, 0x14
// 004f3401  85c0                 test eax, eax
// 004f3403  751e                 jne 0x4f3423
// 004f3405  68540aa000           push 0xa00a54
// 004f340a  8d4c2408             lea ecx, [esp + 8]
// 004f340e  ff159ca89e00         call dword ptr [0x9ea89c]
// 004f3414  689022b100           push 0xb12290
// 004f3419  8d4c2408             lea ecx, [esp + 8]
// 004f341d  51                   push ecx
// 004f341e  e88f552b00           call 0x7a89b2
// 004f3423  8b542418             mov edx, dword ptr [esp + 0x18]
// 004f3427  83c204               add edx, 4
// 004f342a  52                   push edx
// 004f342b  50                   push eax
// 004f342c  8bce                 mov ecx, esi
// 004f342e  e80dffffff           call 0x4f3340
// 004f3433  5e                   pop esi
// 004f3434  83c40c               add esp, 0xc
// 004f3437  c20800               ret 8
// copied from an identical function in another client (function ?execute@S@ns_ROCX00001c@@QAEXPAX0@Z)

namespace ns_ROCX00001c {
// from server: 100% by king_originala
extern char sourceType;
extern char targetType;
extern char badCastThrowInfo;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

extern "C" __declspec(noreturn) void __stdcall ThrowException(
    void*, void*);

typedef void (__thiscall *BadCastConstructor)(void*, const char*);
extern BadCastConstructor badCastConstructor;

struct S
{
    void execute(void* object, void* arguments);
    void invoke(void* object, void* arguments);
};

void S::execute(void* object, void* arguments)
{
    void* converted = __RTDynamicCast(
        object, 0, &sourceType, &targetType, 0);

    if (!converted)
    {
        unsigned long exception[3];
        badCastConstructor(exception, "bad cast");
        ThrowException(exception, &badCastThrowInfo);
    }

    invoke(converted, static_cast<char*>(arguments) + 4);
}
}
