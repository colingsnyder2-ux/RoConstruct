// from server: 100% by EspClaude
// roc 2009-06 004ebf80  unit: RBX::Network::VReplicator::?$BoundFuncDesc  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ebf80
//
// 004ebf80  8b442404             mov eax, dword ptr [esp + 4]
// 004ebf84  83ec0c               sub esp, 0xc
// 004ebf87  56                   push esi
// 004ebf88  6a00                 push 0
// 004ebf8a  680c259f00           push 0x9f250c
// 004ebf8f  68c4bf9d00           push 0x9dbfc4
// 004ebf94  6a00                 push 0
// 004ebf96  50                   push eax
// 004ebf97  8bf1                 mov esi, ecx
// 004ebf99  e8dcdc2200           call 0x719c7a
// 004ebf9e  83c414               add esp, 0x14
// 004ebfa1  85c0                 test eax, eax
// 004ebfa3  751e                 jne 0x4ebfc3
// 004ebfa5  6850d38a00           push 0x8ad350
// 004ebfaa  8d4c2408             lea ecx, [esp + 8]
// 004ebfae  ff1570e98900         call dword ptr [0x89e970]
// 004ebfb4  68b04b9800           push 0x984bb0
// 004ebfb9  8d4c2408             lea ecx, [esp + 8]
// 004ebfbd  51                   push ecx
// 004ebfbe  e887da2200           call 0x719a4a
// 004ebfc3  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004ebfc6  8b5638               mov edx, dword ptr [esi + 0x38]
// 004ebfc9  03c8                 add ecx, eax
// 004ebfcb  ffd2                 call edx
// 004ebfcd  5e                   pop esi
// 004ebfce  83c40c               add esp, 0xc
// 004ebfd1  c20800               ret 8
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
