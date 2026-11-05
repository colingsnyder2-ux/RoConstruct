// from server: 100% by Yeetserama
// roc 2010-06 0066b000  unit: RBX::VTeams::?$BoundFuncDesc  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0066b000
//
// 0066b000  8b442404             mov eax, dword ptr [esp + 4]
// 0066b004  83ec0c               sub esp, 0xc
// 0066b007  56                   push esi
// 0066b008  6a00                 push 0
// 0066b00a  6868f5b900           push 0xb9f568
// 0066b00f  684090b700           push 0xb79040
// 0066b014  6a00                 push 0
// 0066b016  50                   push eax
// 0066b017  8bf1                 mov esi, ecx
// 0066b019  e8ccdb1300           call 0x7a8bea
// 0066b01e  83c414               add esp, 0x14
// 0066b021  85c0                 test eax, eax
// 0066b023  751e                 jne 0x66b043
// 0066b025  68540aa000           push 0xa00a54
// 0066b02a  8d4c2408             lea ecx, [esp + 8]
// 0066b02e  ff159ca89e00         call dword ptr [0x9ea89c]
// 0066b034  689022b100           push 0xb12290
// 0066b039  8d4c2408             lea ecx, [esp + 8]
// 0066b03d  51                   push ecx
// 0066b03e  e86fd91300           call 0x7a89b2
// 0066b043  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0066b046  8b5638               mov edx, dword ptr [esi + 0x38]
// 0066b049  03c8                 add ecx, eax
// 0066b04b  ffd2                 call edx
// 0066b04d  5e                   pop esi
// 0066b04e  83c40c               add esp, 0xc
// 0066b051  c20800               ret 8
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
