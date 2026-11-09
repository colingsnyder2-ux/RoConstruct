// from server: 100% by Yeetserama
// roc 2010-06 005d6cb0  unit: RBX::VDataModel::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005d6cb0
//
// 005d6cb0  8b442404             mov eax, dword ptr [esp + 4]
// 005d6cb4  83ec0c               sub esp, 0xc
// 005d6cb7  56                   push esi
// 005d6cb8  6a00                 push 0
// 005d6cba  68b051b800           push 0xb851b0
// 005d6cbf  684090b700           push 0xb79040
// 005d6cc4  6a00                 push 0
// 005d6cc6  50                   push eax
// 005d6cc7  8bf1                 mov esi, ecx
// 005d6cc9  e81c1f1d00           call 0x7a8bea
// 005d6cce  83c414               add esp, 0x14
// 005d6cd1  85c0                 test eax, eax
// 005d6cd3  751e                 jne 0x5d6cf3
// 005d6cd5  68540aa000           push 0xa00a54
// 005d6cda  8d4c2408             lea ecx, [esp + 8]
// 005d6cde  ff159ca89e00         call dword ptr [0x9ea89c]
// 005d6ce4  689022b100           push 0xb12290
// 005d6ce9  8d4c2408             lea ecx, [esp + 8]
// 005d6ced  51                   push ecx
// 005d6cee  e8bf1c1d00           call 0x7a89b2
// 005d6cf3  8b542418             mov edx, dword ptr [esp + 0x18]
// 005d6cf7  83c204               add edx, 4
// 005d6cfa  52                   push edx
// 005d6cfb  50                   push eax
// 005d6cfc  8bce                 mov ecx, esi
// 005d6cfe  e88d840500           call 0x62f190
// 005d6d03  5e                   pop esi
// 005d6d04  83c40c               add esp, 0xc
// 005d6d07  c20800               ret 8
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
