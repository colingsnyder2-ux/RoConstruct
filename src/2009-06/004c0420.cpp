// from server: 100% by EspClaude
// roc 2009-06 004c0420  unit: RBX::Network::VPlayer::?$BoundFuncDesc  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c0420
//
// 004c0420  8b442404             mov eax, dword ptr [esp + 4]
// 004c0424  83ec0c               sub esp, 0xc
// 004c0427  56                   push esi
// 004c0428  6a00                 push 0
// 004c042a  6820ed9e00           push 0x9eed20
// 004c042f  68c4bf9d00           push 0x9dbfc4
// 004c0434  6a00                 push 0
// 004c0436  50                   push eax
// 004c0437  8bf1                 mov esi, ecx
// 004c0439  e83c982500           call 0x719c7a
// 004c043e  83c414               add esp, 0x14
// 004c0441  85c0                 test eax, eax
// 004c0443  751e                 jne 0x4c0463
// 004c0445  6850d38a00           push 0x8ad350
// 004c044a  8d4c2408             lea ecx, [esp + 8]
// 004c044e  ff1570e98900         call dword ptr [0x89e970]
// 004c0454  68b04b9800           push 0x984bb0
// 004c0459  8d4c2408             lea ecx, [esp + 8]
// 004c045d  51                   push ecx
// 004c045e  e8e7952500           call 0x719a4a
// 004c0463  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004c0466  8b5638               mov edx, dword ptr [esi + 0x38]
// 004c0469  03c8                 add ecx, eax
// 004c046b  ffd2                 call edx
// 004c046d  5e                   pop esi
// 004c046e  83c40c               add esp, 0xc
// 004c0471  c20800               ret 8
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
