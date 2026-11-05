// from server: 100% by Yeetserama
// roc 2010-06 004f34c0  unit: RBX::Network::VReplicator::?$BoundFuncDesc  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004f34c0
//
// 004f34c0  8b442404             mov eax, dword ptr [esp + 4]
// 004f34c4  83ec0c               sub esp, 0xc
// 004f34c7  56                   push esi
// 004f34c8  6a00                 push 0
// 004f34ca  68ac0cb900           push 0xb90cac
// 004f34cf  684090b700           push 0xb79040
// 004f34d4  6a00                 push 0
// 004f34d6  50                   push eax
// 004f34d7  8bf1                 mov esi, ecx
// 004f34d9  e80c572b00           call 0x7a8bea
// 004f34de  83c414               add esp, 0x14
// 004f34e1  85c0                 test eax, eax
// 004f34e3  751e                 jne 0x4f3503
// 004f34e5  68540aa000           push 0xa00a54
// 004f34ea  8d4c2408             lea ecx, [esp + 8]
// 004f34ee  ff159ca89e00         call dword ptr [0x9ea89c]
// 004f34f4  689022b100           push 0xb12290
// 004f34f9  8d4c2408             lea ecx, [esp + 8]
// 004f34fd  51                   push ecx
// 004f34fe  e8af542b00           call 0x7a89b2
// 004f3503  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004f3506  8b5638               mov edx, dword ptr [esi + 0x38]
// 004f3509  03c8                 add ecx, eax
// 004f350b  ffd2                 call edx
// 004f350d  5e                   pop esi
// 004f350e  83c40c               add esp, 0xc
// 004f3511  c20800               ret 8
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
