// from server: 100% by Yeetserama
// roc 2010-06 005ecab0  unit: RBX::VChangeHistoryService::?$BoundFuncDesc  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ecab0
//
// 005ecab0  8b442404             mov eax, dword ptr [esp + 4]
// 005ecab4  83ec0c               sub esp, 0xc
// 005ecab7  56                   push esi
// 005ecab8  6a00                 push 0
// 005ecaba  6868b7ba00           push 0xbab768
// 005ecabf  684090b700           push 0xb79040
// 005ecac4  6a00                 push 0
// 005ecac6  50                   push eax
// 005ecac7  8bf1                 mov esi, ecx
// 005ecac9  e81cc11b00           call 0x7a8bea
// 005ecace  83c414               add esp, 0x14
// 005ecad1  85c0                 test eax, eax
// 005ecad3  751e                 jne 0x5ecaf3
// 005ecad5  68540aa000           push 0xa00a54
// 005ecada  8d4c2408             lea ecx, [esp + 8]
// 005ecade  ff159ca89e00         call dword ptr [0x9ea89c]
// 005ecae4  689022b100           push 0xb12290
// 005ecae9  8d4c2408             lea ecx, [esp + 8]
// 005ecaed  51                   push ecx
// 005ecaee  e8bfbe1b00           call 0x7a89b2
// 005ecaf3  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 005ecaf6  8b5638               mov edx, dword ptr [esi + 0x38]
// 005ecaf9  03c8                 add ecx, eax
// 005ecafb  ffd2                 call edx
// 005ecafd  5e                   pop esi
// 005ecafe  83c40c               add esp, 0xc
// 005ecb01  c20800               ret 8
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
