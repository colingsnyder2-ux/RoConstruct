// from server: 100% by EspClaude
// roc 2009-06 0061ba30  unit: RBX::VChangeHistoryService::?$BoundFuncDesc  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0061ba30
//
// 0061ba30  8b442404             mov eax, dword ptr [esp + 4]
// 0061ba34  83ec0c               sub esp, 0xc
// 0061ba37  56                   push esi
// 0061ba38  6a00                 push 0
// 0061ba3a  68fc9ca000           push 0xa09cfc
// 0061ba3f  68c4bf9d00           push 0x9dbfc4
// 0061ba44  6a00                 push 0
// 0061ba46  50                   push eax
// 0061ba47  8bf1                 mov esi, ecx
// 0061ba49  e82ce20f00           call 0x719c7a
// 0061ba4e  83c414               add esp, 0x14
// 0061ba51  85c0                 test eax, eax
// 0061ba53  751e                 jne 0x61ba73
// 0061ba55  6850d38a00           push 0x8ad350
// 0061ba5a  8d4c2408             lea ecx, [esp + 8]
// 0061ba5e  ff1570e98900         call dword ptr [0x89e970]
// 0061ba64  68b04b9800           push 0x984bb0
// 0061ba69  8d4c2408             lea ecx, [esp + 8]
// 0061ba6d  51                   push ecx
// 0061ba6e  e8d7df0f00           call 0x719a4a
// 0061ba73  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0061ba76  8b5638               mov edx, dword ptr [esi + 0x38]
// 0061ba79  03c8                 add ecx, eax
// 0061ba7b  ffd2                 call edx
// 0061ba7d  5e                   pop esi
// 0061ba7e  83c40c               add esp, 0xc
// 0061ba81  c20800               ret 8
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
