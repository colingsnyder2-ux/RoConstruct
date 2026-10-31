// from server: 100% by EspClaude
// roc 2009-06 00646a40  unit: RBX::Soundscape::VSoundChannel::?$BoundFuncDesc  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00646a40
//
// 00646a40  8b442404             mov eax, dword ptr [esp + 4]
// 00646a44  83ec0c               sub esp, 0xc
// 00646a47  56                   push esi
// 00646a48  6a00                 push 0
// 00646a4a  688ce2a000           push 0xa0e28c
// 00646a4f  68c4bf9d00           push 0x9dbfc4
// 00646a54  6a00                 push 0
// 00646a56  50                   push eax
// 00646a57  8bf1                 mov esi, ecx
// 00646a59  e81c320d00           call 0x719c7a
// 00646a5e  83c414               add esp, 0x14
// 00646a61  85c0                 test eax, eax
// 00646a63  751e                 jne 0x646a83
// 00646a65  6850d38a00           push 0x8ad350
// 00646a6a  8d4c2408             lea ecx, [esp + 8]
// 00646a6e  ff1570e98900         call dword ptr [0x89e970]
// 00646a74  68b04b9800           push 0x984bb0
// 00646a79  8d4c2408             lea ecx, [esp + 8]
// 00646a7d  51                   push ecx
// 00646a7e  e8c72f0d00           call 0x719a4a
// 00646a83  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00646a86  8b5638               mov edx, dword ptr [esi + 0x38]
// 00646a89  03c8                 add ecx, eax
// 00646a8b  ffd2                 call edx
// 00646a8d  5e                   pop esi
// 00646a8e  83c40c               add esp, 0xc
// 00646a91  c20800               ret 8
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
