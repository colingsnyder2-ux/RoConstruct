// from server: 100% by Yeetserama
// roc 2010-06 00606a60  unit: RBX::VWorkspace::?$BoundFuncDesc  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00606a60
//
// 00606a60  6aff                 push -1
// 00606a62  68e8d09800           push 0x98d0e8
// 00606a67  64a100000000         mov eax, dword ptr fs:[0]
// 00606a6d  50                   push eax
// 00606a6e  64892500000000       mov dword ptr fs:[0], esp
// 00606a75  83ec14               sub esp, 0x14
// 00606a78  56                   push esi
// 00606a79  57                   push edi
// 00606a7a  8bf9                 mov edi, ecx
// 00606a7c  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 00606a7f  8b4744               mov eax, dword ptr [edi + 0x44]
// 00606a82  89442408             mov dword ptr [esp + 8], eax
// 00606a86  85c9                 test ecx, ecx
// 00606a88  7409                 je 0x606a93
// 00606a8a  8b11                 mov edx, dword ptr [ecx]
// 00606a8c  8b4208               mov eax, dword ptr [edx + 8]
// 00606a8f  ffd0                 call eax
// 00606a91  eb02                 jmp 0x606a95
// 00606a93  33c0                 xor eax, eax
// 00606a95  8944240c             mov dword ptr [esp + 0xc], eax
// 00606a99  8b742430             mov esi, dword ptr [esp + 0x30]
// 00606a9d  8b16                 mov edx, dword ptr [esi]
// 00606a9f  8b5204               mov edx, dword ptr [edx + 4]
// 00606aa2  8d442408             lea eax, [esp + 8]
// 00606aa6  50                   push eax
// 00606aa7  6a01                 push 1
// 00606aa9  8bce                 mov ecx, esi
// 00606aab  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00606ab3  ffd2                 call edx
// 00606ab5  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00606ab9  6a00                 push 0
// 00606abb  68f4acba00           push 0xbaacf4
// 00606ac0  684090b700           push 0xb79040
// 00606ac5  6a00                 push 0
// 00606ac7  50                   push eax
// 00606ac8  e81d211a00           call 0x7a8bea
// 00606acd  83c414               add esp, 0x14
// 00606ad0  85c0                 test eax, eax
// 00606ad2  751e                 jne 0x606af2
// 00606ad4  68540aa000           push 0xa00a54
// 00606ad9  8d4c2414             lea ecx, [esp + 0x14]
// 00606add  ff159ca89e00         call dword ptr [0x9ea89c]
// 00606ae3  689022b100           push 0xb12290
// 00606ae8  8d4c2414             lea ecx, [esp + 0x14]
// 00606aec  51                   push ecx
// 00606aed  e8c01e1a00           call 0x7a89b2
// 00606af2  8d542408             lea edx, [esp + 8]
// 00606af6  52                   push edx
// 00606af7  83c604               add esi, 4
// 00606afa  56                   push esi
// 00606afb  50                   push eax
// 00606afc  8bcf                 mov ecx, edi
// 00606afe  e87dfeffff           call 0x606980
// 00606b03  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00606b07  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00606b0f  85c9                 test ecx, ecx
// 00606b11  7408                 je 0x606b1b
// 00606b13  8b01                 mov eax, dword ptr [ecx]
// 00606b15  8b10                 mov edx, dword ptr [eax]
// 00606b17  6a01                 push 1
// 00606b19  ffd2                 call edx
// 00606b1b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00606b1f  5f                   pop edi
// 00606b20  5e                   pop esi
// 00606b21  64890d00000000       mov dword ptr fs:[0], ecx
// 00606b28  83c420               add esp, 0x20
// 00606b2b  c20800               ret 8
// copied from an identical function in another client (function ?invoke@Function@ns_ROCX000001@@QAEXPAXPAUReceiver@2@@Z)

namespace ns_ROCX000001 {
// from server: 100% by king_originala
struct Control {
    virtual void dispose(int);
    virtual void slot1();
    virtual Control* clone();

    static Control* copy(Control*);
};

inline Control* Control::copy(Control* source) {
    if (source)
        return source->clone();
    return 0;
}

struct Pair {
    void* value;
    Control* control;

    Pair(const Pair&);
    ~Pair();
};

inline Pair::Pair(const Pair& other) {
    Control* source = other.control;
    value = other.value;
    control = Control::copy(source);
}

inline Pair::~Pair() {
    if (control)
        control->dispose(1);
}

struct Receiver {
    virtual void slot0();
    virtual void set(int, const Pair*);
};

struct BadCast {
    unsigned char storage[12];
};

extern char baseType;
extern char workspaceType;
extern char badCastThrowInfo;

extern "C" void* __cdecl runtimeCast(
    void*, long, void*, void*, int);

extern void (__thiscall *constructBadCast)(BadCast*, const char*);

extern "C" __declspec(noreturn) void __stdcall throwException(
    void*, void*);

struct Function {
    unsigned char reserved[68];
    Pair bound;

    void invoke(void*, Receiver*);
    void dispatch(void*, void*, const Pair*);
};

void Function::invoke(void* object, Receiver* receiver) {
    Pair argument(bound);
    receiver->set(1, &argument);

    void* workspace = runtimeCast(
        object, 0, &baseType, &workspaceType, 0);

    if (!workspace) {
        BadCast exception;
        constructBadCast(&exception, "bad cast");
        throwException(&exception, &badCastThrowInfo);
    }

    dispatch(workspace, reinterpret_cast<char*>(receiver) + 4, &argument);
}
}
