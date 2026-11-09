// from server: 100% by EspClaude
// roc 2009-06 0062fa50  unit: RBX::VWorkspace::?$BoundFuncDesc  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0062fa50
//
// 0062fa50  6aff                 push -1
// 0062fa52  6868398600           push 0x863968
// 0062fa57  64a100000000         mov eax, dword ptr fs:[0]
// 0062fa5d  50                   push eax
// 0062fa5e  64892500000000       mov dword ptr fs:[0], esp
// 0062fa65  83ec14               sub esp, 0x14
// 0062fa68  56                   push esi
// 0062fa69  57                   push edi
// 0062fa6a  8bf9                 mov edi, ecx
// 0062fa6c  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 0062fa6f  8b4744               mov eax, dword ptr [edi + 0x44]
// 0062fa72  89442408             mov dword ptr [esp + 8], eax
// 0062fa76  85c9                 test ecx, ecx
// 0062fa78  7409                 je 0x62fa83
// 0062fa7a  8b11                 mov edx, dword ptr [ecx]
// 0062fa7c  8b4208               mov eax, dword ptr [edx + 8]
// 0062fa7f  ffd0                 call eax
// 0062fa81  eb02                 jmp 0x62fa85
// 0062fa83  33c0                 xor eax, eax
// 0062fa85  8944240c             mov dword ptr [esp + 0xc], eax
// 0062fa89  8b742430             mov esi, dword ptr [esp + 0x30]
// 0062fa8d  8b16                 mov edx, dword ptr [esi]
// 0062fa8f  8b5204               mov edx, dword ptr [edx + 4]
// 0062fa92  8d442408             lea eax, [esp + 8]
// 0062fa96  50                   push eax
// 0062fa97  6a01                 push 1
// 0062fa99  8bce                 mov ecx, esi
// 0062fa9b  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0062faa3  ffd2                 call edx
// 0062faa5  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0062faa9  6a00                 push 0
// 0062faab  68a481a000           push 0xa081a4
// 0062fab0  68c4bf9d00           push 0x9dbfc4
// 0062fab5  6a00                 push 0
// 0062fab7  50                   push eax
// 0062fab8  e8bda10e00           call 0x719c7a
// 0062fabd  83c414               add esp, 0x14
// 0062fac0  85c0                 test eax, eax
// 0062fac2  751e                 jne 0x62fae2
// 0062fac4  6850d38a00           push 0x8ad350
// 0062fac9  8d4c2414             lea ecx, [esp + 0x14]
// 0062facd  ff1570e98900         call dword ptr [0x89e970]
// 0062fad3  68b04b9800           push 0x984bb0
// 0062fad8  8d4c2414             lea ecx, [esp + 0x14]
// 0062fadc  51                   push ecx
// 0062fadd  e8689f0e00           call 0x719a4a
// 0062fae2  8d542408             lea edx, [esp + 8]
// 0062fae6  52                   push edx
// 0062fae7  83c604               add esi, 4
// 0062faea  56                   push esi
// 0062faeb  50                   push eax
// 0062faec  8bcf                 mov ecx, edi
// 0062faee  e87dfeffff           call 0x62f970
// 0062faf3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0062faf7  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0062faff  85c9                 test ecx, ecx
// 0062fb01  7408                 je 0x62fb0b
// 0062fb03  8b01                 mov eax, dword ptr [ecx]
// 0062fb05  8b10                 mov edx, dword ptr [eax]
// 0062fb07  6a01                 push 1
// 0062fb09  ffd2                 call edx
// 0062fb0b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0062fb0f  5f                   pop edi
// 0062fb10  5e                   pop esi
// 0062fb11  64890d00000000       mov dword ptr fs:[0], ecx
// 0062fb18  83c420               add esp, 0x20
// 0062fb1b  c20800               ret 8
// copied from an identical function in another client (function ?invoke@Function@ns_ROCX000007@@QAEXPAXPAUReceiver@2@@Z)

namespace ns_ROCX000007 {
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
