// from server: 100% by Yeetserama
// roc 2010-06 0062f230  unit: RBX::VContentProvider::?$BoundFuncDesc  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0062f230
//
// 0062f230  8b442404             mov eax, dword ptr [esp + 4]
// 0062f234  83ec0c               sub esp, 0xc
// 0062f237  56                   push esi
// 0062f238  6a00                 push 0
// 0062f23a  687825bb00           push 0xbb2578
// 0062f23f  684090b700           push 0xb79040
// 0062f244  6a00                 push 0
// 0062f246  50                   push eax
// 0062f247  8bf1                 mov esi, ecx
// 0062f249  e89c991700           call 0x7a8bea
// 0062f24e  83c414               add esp, 0x14
// 0062f251  85c0                 test eax, eax
// 0062f253  751e                 jne 0x62f273
// 0062f255  68540aa000           push 0xa00a54
// 0062f25a  8d4c2408             lea ecx, [esp + 8]
// 0062f25e  ff159ca89e00         call dword ptr [0x9ea89c]
// 0062f264  689022b100           push 0xb12290
// 0062f269  8d4c2408             lea ecx, [esp + 8]
// 0062f26d  51                   push ecx
// 0062f26e  e83f971700           call 0x7a89b2
// 0062f273  8b542418             mov edx, dword ptr [esp + 0x18]
// 0062f277  83c204               add edx, 4
// 0062f27a  52                   push edx
// 0062f27b  50                   push eax
// 0062f27c  8bce                 mov ecx, esi
// 0062f27e  e80dffffff           call 0x62f190
// 0062f283  5e                   pop esi
// 0062f284  83c40c               add esp, 0xc
// 0062f287  c20800               ret 8
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
