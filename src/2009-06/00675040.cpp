// from server: 100% by EspClaude
// roc 2009-06 00675040  unit: RBX::VTeams::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00675040
//
// 00675040  8b442404             mov eax, dword ptr [esp + 4]
// 00675044  83ec0c               sub esp, 0xc
// 00675047  56                   push esi
// 00675048  6a00                 push 0
// 0067504a  68d000a000           push 0xa000d0
// 0067504f  68c4bf9d00           push 0x9dbfc4
// 00675054  6a00                 push 0
// 00675056  50                   push eax
// 00675057  8bf1                 mov esi, ecx
// 00675059  e81c4c0a00           call 0x719c7a
// 0067505e  83c414               add esp, 0x14
// 00675061  85c0                 test eax, eax
// 00675063  751e                 jne 0x675083
// 00675065  6850d38a00           push 0x8ad350
// 0067506a  8d4c2408             lea ecx, [esp + 8]
// 0067506e  ff1570e98900         call dword ptr [0x89e970]
// 00675074  68b04b9800           push 0x984bb0
// 00675079  8d4c2408             lea ecx, [esp + 8]
// 0067507d  51                   push ecx
// 0067507e  e8c7490a00           call 0x719a4a
// 00675083  8b542418             mov edx, dword ptr [esp + 0x18]
// 00675087  83c204               add edx, 4
// 0067508a  52                   push edx
// 0067508b  50                   push eax
// 0067508c  8bce                 mov ecx, esi
// 0067508e  e81df2f5ff           call 0x5d42b0
// 00675093  5e                   pop esi
// 00675094  83c40c               add esp, 0xc
// 00675097  c20800               ret 8
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
