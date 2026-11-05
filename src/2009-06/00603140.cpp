// from server: 100% by EspClaude
// roc 2009-06 00603140  unit: RBX::VDataModel::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00603140
//
// 00603140  8b442404             mov eax, dword ptr [esp + 4]
// 00603144  83ec0c               sub esp, 0xc
// 00603147  56                   push esi
// 00603148  6a00                 push 0
// 0060314a  68706b9e00           push 0x9e6b70
// 0060314f  68c4bf9d00           push 0x9dbfc4
// 00603154  6a00                 push 0
// 00603156  50                   push eax
// 00603157  8bf1                 mov esi, ecx
// 00603159  e81c6b1100           call 0x719c7a
// 0060315e  83c414               add esp, 0x14
// 00603161  85c0                 test eax, eax
// 00603163  751e                 jne 0x603183
// 00603165  6850d38a00           push 0x8ad350
// 0060316a  8d4c2408             lea ecx, [esp + 8]
// 0060316e  ff1570e98900         call dword ptr [0x89e970]
// 00603174  68b04b9800           push 0x984bb0
// 00603179  8d4c2408             lea ecx, [esp + 8]
// 0060317d  51                   push ecx
// 0060317e  e8c7681100           call 0x719a4a
// 00603183  8b542418             mov edx, dword ptr [esp + 0x18]
// 00603187  83c204               add edx, 4
// 0060318a  52                   push edx
// 0060318b  50                   push eax
// 0060318c  8bce                 mov ecx, esi
// 0060318e  e80dffffff           call 0x6030a0
// 00603193  5e                   pop esi
// 00603194  83c40c               add esp, 0xc
// 00603197  c20800               ret 8
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
