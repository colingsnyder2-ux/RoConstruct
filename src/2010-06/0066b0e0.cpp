// from server: 100% by Yeetserama
// roc 2010-06 0066b0e0  unit: RBX::VTeams::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0066b0e0
//
// 0066b0e0  8b442404             mov eax, dword ptr [esp + 4]
// 0066b0e4  83ec0c               sub esp, 0xc
// 0066b0e7  56                   push esi
// 0066b0e8  6a00                 push 0
// 0066b0ea  6868f5b900           push 0xb9f568
// 0066b0ef  684090b700           push 0xb79040
// 0066b0f4  6a00                 push 0
// 0066b0f6  50                   push eax
// 0066b0f7  8bf1                 mov esi, ecx
// 0066b0f9  e8ecda1300           call 0x7a8bea
// 0066b0fe  83c414               add esp, 0x14
// 0066b101  85c0                 test eax, eax
// 0066b103  751e                 jne 0x66b123
// 0066b105  68540aa000           push 0xa00a54
// 0066b10a  8d4c2408             lea ecx, [esp + 8]
// 0066b10e  ff159ca89e00         call dword ptr [0x9ea89c]
// 0066b114  689022b100           push 0xb12290
// 0066b119  8d4c2408             lea ecx, [esp + 8]
// 0066b11d  51                   push ecx
// 0066b11e  e88fd81300           call 0x7a89b2
// 0066b123  8b542418             mov edx, dword ptr [esp + 0x18]
// 0066b127  83c204               add edx, 4
// 0066b12a  52                   push edx
// 0066b12b  50                   push eax
// 0066b12c  8bce                 mov ecx, esi
// 0066b12e  e83daffeff           call 0x656070
// 0066b133  5e                   pop esi
// 0066b134  83c40c               add esp, 0xc
// 0066b137  c20800               ret 8
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
