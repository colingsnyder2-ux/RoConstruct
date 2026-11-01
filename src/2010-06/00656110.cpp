// from server: 100% by Yeetserama
// roc 2010-06 00656110  unit: RBX::VPose::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00656110
//
// 00656110  8b442404             mov eax, dword ptr [esp + 4]
// 00656114  83ec0c               sub esp, 0xc
// 00656117  56                   push esi
// 00656118  6a00                 push 0
// 0065611a  68f49fbb00           push 0xbb9ff4
// 0065611f  684090b700           push 0xb79040
// 00656124  6a00                 push 0
// 00656126  50                   push eax
// 00656127  8bf1                 mov esi, ecx
// 00656129  e8bc2a1500           call 0x7a8bea
// 0065612e  83c414               add esp, 0x14
// 00656131  85c0                 test eax, eax
// 00656133  751e                 jne 0x656153
// 00656135  68540aa000           push 0xa00a54
// 0065613a  8d4c2408             lea ecx, [esp + 8]
// 0065613e  ff159ca89e00         call dword ptr [0x9ea89c]
// 00656144  689022b100           push 0xb12290
// 00656149  8d4c2408             lea ecx, [esp + 8]
// 0065614d  51                   push ecx
// 0065614e  e85f281500           call 0x7a89b2
// 00656153  8b542418             mov edx, dword ptr [esp + 0x18]
// 00656157  83c204               add edx, 4
// 0065615a  52                   push edx
// 0065615b  50                   push eax
// 0065615c  8bce                 mov ecx, esi
// 0065615e  e80dffffff           call 0x656070
// 00656163  5e                   pop esi
// 00656164  83c40c               add esp, 0xc
// 00656167  c20800               ret 8
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
