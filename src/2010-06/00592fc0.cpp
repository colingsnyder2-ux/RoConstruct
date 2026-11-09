// from server: 100% by Yeetserama
// roc 2010-06 00592fc0  unit: RBX::VDebugSettings::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00592fc0
//
// 00592fc0  8b442404             mov eax, dword ptr [esp + 4]
// 00592fc4  83ec0c               sub esp, 0xc
// 00592fc7  56                   push esi
// 00592fc8  6a00                 push 0
// 00592fca  68b0d4b900           push 0xb9d4b0
// 00592fcf  684090b700           push 0xb79040
// 00592fd4  6a00                 push 0
// 00592fd6  50                   push eax
// 00592fd7  8bf1                 mov esi, ecx
// 00592fd9  e80c5c2100           call 0x7a8bea
// 00592fde  83c414               add esp, 0x14
// 00592fe1  85c0                 test eax, eax
// 00592fe3  751e                 jne 0x593003
// 00592fe5  68540aa000           push 0xa00a54
// 00592fea  8d4c2408             lea ecx, [esp + 8]
// 00592fee  ff159ca89e00         call dword ptr [0x9ea89c]
// 00592ff4  689022b100           push 0xb12290
// 00592ff9  8d4c2408             lea ecx, [esp + 8]
// 00592ffd  51                   push ecx
// 00592ffe  e8af592100           call 0x7a89b2
// 00593003  8b542418             mov edx, dword ptr [esp + 0x18]
// 00593007  83c204               add edx, 4
// 0059300a  52                   push edx
// 0059300b  50                   push eax
// 0059300c  8bce                 mov ecx, esi
// 0059300e  e80dffffff           call 0x592f20
// 00593013  5e                   pop esi
// 00593014  83c40c               add esp, 0xc
// 00593017  c20800               ret 8
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
