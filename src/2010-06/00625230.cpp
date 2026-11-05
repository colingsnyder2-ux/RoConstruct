// from server: 100% by Yeetserama
// roc 2010-06 00625230  unit: RBX::Soundscape::VSoundChannel::?$BoundFuncDesc  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00625230
//
// 00625230  8b442404             mov eax, dword ptr [esp + 4]
// 00625234  83ec0c               sub esp, 0xc
// 00625237  56                   push esi
// 00625238  6a00                 push 0
// 0062523a  684012bb00           push 0xbb1240
// 0062523f  684090b700           push 0xb79040
// 00625244  6a00                 push 0
// 00625246  50                   push eax
// 00625247  8bf1                 mov esi, ecx
// 00625249  e89c391800           call 0x7a8bea
// 0062524e  83c414               add esp, 0x14
// 00625251  85c0                 test eax, eax
// 00625253  751e                 jne 0x625273
// 00625255  68540aa000           push 0xa00a54
// 0062525a  8d4c2408             lea ecx, [esp + 8]
// 0062525e  ff159ca89e00         call dword ptr [0x9ea89c]
// 00625264  689022b100           push 0xb12290
// 00625269  8d4c2408             lea ecx, [esp + 8]
// 0062526d  51                   push ecx
// 0062526e  e83f371800           call 0x7a89b2
// 00625273  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00625276  8b5638               mov edx, dword ptr [esi + 0x38]
// 00625279  03c8                 add ecx, eax
// 0062527b  ffd2                 call edx
// 0062527d  5e                   pop esi
// 0062527e  83c40c               add esp, 0xc
// 00625281  c20800               ret 8
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
