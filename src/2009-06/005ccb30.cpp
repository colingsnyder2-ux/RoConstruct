// from server: 100% by EspClaude
// roc 2009-06 005ccb30  unit: RBX::VDebugSettings::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ccb30
//
// 005ccb30  8b442404             mov eax, dword ptr [esp + 4]
// 005ccb34  83ec0c               sub esp, 0xc
// 005ccb37  56                   push esi
// 005ccb38  6a00                 push 0
// 005ccb3a  6854e29f00           push 0x9fe254
// 005ccb3f  68c4bf9d00           push 0x9dbfc4
// 005ccb44  6a00                 push 0
// 005ccb46  50                   push eax
// 005ccb47  8bf1                 mov esi, ecx
// 005ccb49  e82cd11400           call 0x719c7a
// 005ccb4e  83c414               add esp, 0x14
// 005ccb51  85c0                 test eax, eax
// 005ccb53  751e                 jne 0x5ccb73
// 005ccb55  6850d38a00           push 0x8ad350
// 005ccb5a  8d4c2408             lea ecx, [esp + 8]
// 005ccb5e  ff1570e98900         call dword ptr [0x89e970]
// 005ccb64  68b04b9800           push 0x984bb0
// 005ccb69  8d4c2408             lea ecx, [esp + 8]
// 005ccb6d  51                   push ecx
// 005ccb6e  e8d7ce1400           call 0x719a4a
// 005ccb73  8b542418             mov edx, dword ptr [esp + 0x18]
// 005ccb77  83c204               add edx, 4
// 005ccb7a  52                   push edx
// 005ccb7b  50                   push eax
// 005ccb7c  8bce                 mov ecx, esi
// 005ccb7e  e8bdf80400           call 0x61c440
// 005ccb83  5e                   pop esi
// 005ccb84  83c40c               add esp, 0xc
// 005ccb87  c20800               ret 8
// copied from an identical function in another client (function ?execute@S@ns_ROCX0000c5@@QAEXPAX0@Z)

namespace ns_ROCX0000c5 {
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
