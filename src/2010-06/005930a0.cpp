// from server: 100% by Yeetserama
// roc 2010-06 005930a0  unit: RBX::VDebugSettings::?$BoundFuncDesc  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005930a0
//
// 005930a0  8b442404             mov eax, dword ptr [esp + 4]
// 005930a4  83ec0c               sub esp, 0xc
// 005930a7  56                   push esi
// 005930a8  6a00                 push 0
// 005930aa  68b0d4b900           push 0xb9d4b0
// 005930af  684090b700           push 0xb79040
// 005930b4  6a00                 push 0
// 005930b6  50                   push eax
// 005930b7  8bf1                 mov esi, ecx
// 005930b9  e82c5b2100           call 0x7a8bea
// 005930be  83c414               add esp, 0x14
// 005930c1  85c0                 test eax, eax
// 005930c3  751e                 jne 0x5930e3
// 005930c5  68540aa000           push 0xa00a54
// 005930ca  8d4c2408             lea ecx, [esp + 8]
// 005930ce  ff159ca89e00         call dword ptr [0x9ea89c]
// 005930d4  689022b100           push 0xb12290
// 005930d9  8d4c2408             lea ecx, [esp + 8]
// 005930dd  51                   push ecx
// 005930de  e8cf582100           call 0x7a89b2
// 005930e3  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 005930e6  8b5638               mov edx, dword ptr [esi + 0x38]
// 005930e9  03c8                 add ecx, eax
// 005930eb  ffd2                 call edx
// 005930ed  5e                   pop esi
// 005930ee  83c40c               add esp, 0xc
// 005930f1  c20800               ret 8
// copied from an identical function in another client (function ?invoke@S@ns_ROCX00000d@@QAEXPAUBase@2@PAX@Z)

namespace ns_ROCX00000d {
// from server: 100% by king_originala
extern char baseTypeInfo;
extern char windowTypeInfo;
extern char badCastThrowInfo;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

struct BadCast {
    char data[12];
};

extern void (__thiscall *constructBadCast)(BadCast*, const char*);
extern "C" __declspec(noreturn) void __stdcall throwException(
    void*, void*);

struct Base {
    virtual void anchor();
};

struct Other {
    int value;
};

struct Window : Base, Other {
};

struct S {
    char padding[0x38];
    void (Window::*callback)();

    void invoke(Base* object, void* unused);
};

void S::invoke(Base* object, void*)
{
    Window* window = static_cast<Window*>(
        __RTDynamicCast(object, 0, &baseTypeInfo, &windowTypeInfo, 0));

    if (!window) {
        BadCast exception;
        constructBadCast(&exception, "bad cast");
        throwException(&exception, &badCastThrowInfo);
    }

    (window->*callback)();
}
}
