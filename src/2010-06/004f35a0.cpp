// from server: 100% by Yeetserama
// roc 2010-06 004f35a0  unit: RBX::Network::VReplicator::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004f35a0
//
// 004f35a0  8b442404             mov eax, dword ptr [esp + 4]
// 004f35a4  83ec0c               sub esp, 0xc
// 004f35a7  56                   push esi
// 004f35a8  6a00                 push 0
// 004f35aa  68ac0cb900           push 0xb90cac
// 004f35af  684090b700           push 0xb79040
// 004f35b4  6a00                 push 0
// 004f35b6  50                   push eax
// 004f35b7  8bf1                 mov esi, ecx
// 004f35b9  e82c562b00           call 0x7a8bea
// 004f35be  83c414               add esp, 0x14
// 004f35c1  85c0                 test eax, eax
// 004f35c3  751e                 jne 0x4f35e3
// 004f35c5  68540aa000           push 0xa00a54
// 004f35ca  8d4c2408             lea ecx, [esp + 8]
// 004f35ce  ff159ca89e00         call dword ptr [0x9ea89c]
// 004f35d4  689022b100           push 0xb12290
// 004f35d9  8d4c2408             lea ecx, [esp + 8]
// 004f35dd  51                   push ecx
// 004f35de  e8cf532b00           call 0x7a89b2
// 004f35e3  8b542418             mov edx, dword ptr [esp + 0x18]
// 004f35e7  83c204               add edx, 4
// 004f35ea  52                   push edx
// 004f35eb  50                   push eax
// 004f35ec  8bce                 mov ecx, esi
// 004f35ee  e8ed350a00           call 0x596be0
// 004f35f3  5e                   pop esi
// 004f35f4  83c40c               add esp, 0xc
// 004f35f7  c20800               ret 8
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
