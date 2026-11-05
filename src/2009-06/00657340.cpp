// from server: 100% by EspClaude
// roc 2009-06 00657340  unit: RBX::Stats::VItem::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00657340
//
// 00657340  8b442404             mov eax, dword ptr [esp + 4]
// 00657344  83ec0c               sub esp, 0xc
// 00657347  56                   push esi
// 00657348  6a00                 push 0
// 0065734a  68f4559e00           push 0x9e55f4
// 0065734f  68c4bf9d00           push 0x9dbfc4
// 00657354  6a00                 push 0
// 00657356  50                   push eax
// 00657357  8bf1                 mov esi, ecx
// 00657359  e81c290c00           call 0x719c7a
// 0065735e  83c414               add esp, 0x14
// 00657361  85c0                 test eax, eax
// 00657363  751e                 jne 0x657383
// 00657365  6850d38a00           push 0x8ad350
// 0065736a  8d4c2408             lea ecx, [esp + 8]
// 0065736e  ff1570e98900         call dword ptr [0x89e970]
// 00657374  68b04b9800           push 0x984bb0
// 00657379  8d4c2408             lea ecx, [esp + 8]
// 0065737d  51                   push ecx
// 0065737e  e8c7260c00           call 0x719a4a
// 00657383  8b542418             mov edx, dword ptr [esp + 0x18]
// 00657387  83c204               add edx, 4
// 0065738a  52                   push edx
// 0065738b  50                   push eax
// 0065738c  8bce                 mov ecx, esi
// 0065738e  e85dabffff           call 0x651ef0
// 00657393  5e                   pop esi
// 00657394  83c40c               add esp, 0xc
// 00657397  c20800               ret 8
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
