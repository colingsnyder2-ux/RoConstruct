// from server: 100% by Yeetserama
// roc 2010-06 006e5a40  unit: RBX::VLuaDragger::?$BoundFuncDesc  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e5a40
//
// 006e5a40  8b442404             mov eax, dword ptr [esp + 4]
// 006e5a44  83ec0c               sub esp, 0xc
// 006e5a47  56                   push esi
// 006e5a48  6a00                 push 0
// 006e5a4a  6818a1bd00           push 0xbda118
// 006e5a4f  684090b700           push 0xb79040
// 006e5a54  6a00                 push 0
// 006e5a56  50                   push eax
// 006e5a57  8bf1                 mov esi, ecx
// 006e5a59  e88c310c00           call 0x7a8bea
// 006e5a5e  83c414               add esp, 0x14
// 006e5a61  85c0                 test eax, eax
// 006e5a63  751e                 jne 0x6e5a83
// 006e5a65  68540aa000           push 0xa00a54
// 006e5a6a  8d4c2408             lea ecx, [esp + 8]
// 006e5a6e  ff159ca89e00         call dword ptr [0x9ea89c]
// 006e5a74  689022b100           push 0xb12290
// 006e5a79  8d4c2408             lea ecx, [esp + 8]
// 006e5a7d  51                   push ecx
// 006e5a7e  e82f2f0c00           call 0x7a89b2
// 006e5a83  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 006e5a86  8b5638               mov edx, dword ptr [esi + 0x38]
// 006e5a89  03c8                 add ecx, eax
// 006e5a8b  ffd2                 call edx
// 006e5a8d  5e                   pop esi
// 006e5a8e  83c40c               add esp, 0xc
// 006e5a91  c20800               ret 8
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
