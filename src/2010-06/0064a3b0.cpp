// from server: 100% by Yeetserama
// roc 2010-06 0064a3b0  unit: RBX::Stats::VItem::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0064a3b0
//
// 0064a3b0  8b442404             mov eax, dword ptr [esp + 4]
// 0064a3b4  83ec0c               sub esp, 0xc
// 0064a3b7  56                   push esi
// 0064a3b8  6a00                 push 0
// 0064a3ba  686c3bb800           push 0xb83b6c
// 0064a3bf  684090b700           push 0xb79040
// 0064a3c4  6a00                 push 0
// 0064a3c6  50                   push eax
// 0064a3c7  8bf1                 mov esi, ecx
// 0064a3c9  e81ce81500           call 0x7a8bea
// 0064a3ce  83c414               add esp, 0x14
// 0064a3d1  85c0                 test eax, eax
// 0064a3d3  751e                 jne 0x64a3f3
// 0064a3d5  68540aa000           push 0xa00a54
// 0064a3da  8d4c2408             lea ecx, [esp + 8]
// 0064a3de  ff159ca89e00         call dword ptr [0x9ea89c]
// 0064a3e4  689022b100           push 0xb12290
// 0064a3e9  8d4c2408             lea ecx, [esp + 8]
// 0064a3ed  51                   push ecx
// 0064a3ee  e8bfe51500           call 0x7a89b2
// 0064a3f3  8b542418             mov edx, dword ptr [esp + 0x18]
// 0064a3f7  83c204               add edx, 4
// 0064a3fa  52                   push edx
// 0064a3fb  50                   push eax
// 0064a3fc  8bce                 mov ecx, esi
// 0064a3fe  e83d51ffff           call 0x63f540
// 0064a403  5e                   pop esi
// 0064a404  83c40c               add esp, 0xc
// 0064a407  c20800               ret 8
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
