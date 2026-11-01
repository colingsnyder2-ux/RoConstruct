// from server: 100% by Yeetserama
// roc 2010-06 005ecb90  unit: RBX::VChangeHistoryService::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ecb90
//
// 005ecb90  8b442404             mov eax, dword ptr [esp + 4]
// 005ecb94  83ec0c               sub esp, 0xc
// 005ecb97  56                   push esi
// 005ecb98  6a00                 push 0
// 005ecb9a  6868b7ba00           push 0xbab768
// 005ecb9f  684090b700           push 0xb79040
// 005ecba4  6a00                 push 0
// 005ecba6  50                   push eax
// 005ecba7  8bf1                 mov esi, ecx
// 005ecba9  e83cc01b00           call 0x7a8bea
// 005ecbae  83c414               add esp, 0x14
// 005ecbb1  85c0                 test eax, eax
// 005ecbb3  751e                 jne 0x5ecbd3
// 005ecbb5  68540aa000           push 0xa00a54
// 005ecbba  8d4c2408             lea ecx, [esp + 8]
// 005ecbbe  ff159ca89e00         call dword ptr [0x9ea89c]
// 005ecbc4  689022b100           push 0xb12290
// 005ecbc9  8d4c2408             lea ecx, [esp + 8]
// 005ecbcd  51                   push ecx
// 005ecbce  e8dfbd1b00           call 0x7a89b2
// 005ecbd3  8b542418             mov edx, dword ptr [esp + 0x18]
// 005ecbd7  83c204               add edx, 4
// 005ecbda  52                   push edx
// 005ecbdb  50                   push eax
// 005ecbdc  8bce                 mov ecx, esi
// 005ecbde  e83d63faff           call 0x592f20
// 005ecbe3  5e                   pop esi
// 005ecbe4  83c40c               add esp, 0xc
// 005ecbe7  c20800               ret 8
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
