// from server: 100% by EspClaude
// roc 2009-06 00674f60  unit: RBX::VTeams::?$BoundFuncDesc  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00674f60
//
// 00674f60  8b442404             mov eax, dword ptr [esp + 4]
// 00674f64  83ec0c               sub esp, 0xc
// 00674f67  56                   push esi
// 00674f68  6a00                 push 0
// 00674f6a  68d000a000           push 0xa000d0
// 00674f6f  68c4bf9d00           push 0x9dbfc4
// 00674f74  6a00                 push 0
// 00674f76  50                   push eax
// 00674f77  8bf1                 mov esi, ecx
// 00674f79  e8fc4c0a00           call 0x719c7a
// 00674f7e  83c414               add esp, 0x14
// 00674f81  85c0                 test eax, eax
// 00674f83  751e                 jne 0x674fa3
// 00674f85  6850d38a00           push 0x8ad350
// 00674f8a  8d4c2408             lea ecx, [esp + 8]
// 00674f8e  ff1570e98900         call dword ptr [0x89e970]
// 00674f94  68b04b9800           push 0x984bb0
// 00674f99  8d4c2408             lea ecx, [esp + 8]
// 00674f9d  51                   push ecx
// 00674f9e  e8a74a0a00           call 0x719a4a
// 00674fa3  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00674fa6  8b5638               mov edx, dword ptr [esi + 0x38]
// 00674fa9  03c8                 add ecx, eax
// 00674fab  ffd2                 call edx
// 00674fad  5e                   pop esi
// 00674fae  83c40c               add esp, 0xc
// 00674fb1  c20800               ret 8
// copied from an identical function in another client (function ?invoke@S@ns_ROCX00002e@@QAEXPAUBase@2@PAX@Z)

namespace ns_ROCX00002e {
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
