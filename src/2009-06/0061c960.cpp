// from server: 100% by EspClaude
// roc 2009-06 0061c960  unit: RBX::VChangeHistoryService::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0061c960
//
// 0061c960  8b442404             mov eax, dword ptr [esp + 4]
// 0061c964  83ec0c               sub esp, 0xc
// 0061c967  56                   push esi
// 0061c968  6a00                 push 0
// 0061c96a  68fc9ca000           push 0xa09cfc
// 0061c96f  68c4bf9d00           push 0x9dbfc4
// 0061c974  6a00                 push 0
// 0061c976  50                   push eax
// 0061c977  8bf1                 mov esi, ecx
// 0061c979  e8fcd20f00           call 0x719c7a
// 0061c97e  83c414               add esp, 0x14
// 0061c981  85c0                 test eax, eax
// 0061c983  751e                 jne 0x61c9a3
// 0061c985  6850d38a00           push 0x8ad350
// 0061c98a  8d4c2408             lea ecx, [esp + 8]
// 0061c98e  ff1570e98900         call dword ptr [0x89e970]
// 0061c994  68b04b9800           push 0x984bb0
// 0061c999  8d4c2408             lea ecx, [esp + 8]
// 0061c99d  51                   push ecx
// 0061c99e  e8a7d00f00           call 0x719a4a
// 0061c9a3  8b542418             mov edx, dword ptr [esp + 0x18]
// 0061c9a7  83c204               add edx, 4
// 0061c9aa  52                   push edx
// 0061c9ab  50                   push eax
// 0061c9ac  8bce                 mov ecx, esi
// 0061c9ae  e88dfaffff           call 0x61c440
// 0061c9b3  5e                   pop esi
// 0061c9b4  83c40c               add esp, 0xc
// 0061c9b7  c20800               ret 8
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
