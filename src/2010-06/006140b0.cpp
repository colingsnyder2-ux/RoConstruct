// from server: 100% by Yeetserama
// roc 2010-06 006140b0  unit: RBX::VScriptContext::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006140b0
//
// 006140b0  8b442404             mov eax, dword ptr [esp + 4]
// 006140b4  83ec0c               sub esp, 0xc
// 006140b7  56                   push esi
// 006140b8  6a00                 push 0
// 006140ba  68a800bb00           push 0xbb00a8
// 006140bf  684090b700           push 0xb79040
// 006140c4  6a00                 push 0
// 006140c6  50                   push eax
// 006140c7  8bf1                 mov esi, ecx
// 006140c9  e81c4b1900           call 0x7a8bea
// 006140ce  83c414               add esp, 0x14
// 006140d1  85c0                 test eax, eax
// 006140d3  751e                 jne 0x6140f3
// 006140d5  68540aa000           push 0xa00a54
// 006140da  8d4c2408             lea ecx, [esp + 8]
// 006140de  ff159ca89e00         call dword ptr [0x9ea89c]
// 006140e4  689022b100           push 0xb12290
// 006140e9  8d4c2408             lea ecx, [esp + 8]
// 006140ed  51                   push ecx
// 006140ee  e8bf481900           call 0x7a89b2
// 006140f3  8b542418             mov edx, dword ptr [esp + 0x18]
// 006140f7  83c204               add edx, 4
// 006140fa  52                   push edx
// 006140fb  50                   push eax
// 006140fc  8bce                 mov ecx, esi
// 006140fe  e81deef7ff           call 0x592f20
// 00614103  5e                   pop esi
// 00614104  83c40c               add esp, 0xc
// 00614107  c20800               ret 8
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
