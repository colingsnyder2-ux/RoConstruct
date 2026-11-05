// from server: 100% by Yeetserama
// roc 2010-06 00671e80  unit: RBX::VHumanoid::?$BoundFuncDesc  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00671e80
//
// 00671e80  6aff                 push -1
// 00671e82  68e8d09800           push 0x98d0e8
// 00671e87  64a100000000         mov eax, dword ptr fs:[0]
// 00671e8d  50                   push eax
// 00671e8e  64892500000000       mov dword ptr fs:[0], esp
// 00671e95  83ec14               sub esp, 0x14
// 00671e98  56                   push esi
// 00671e99  57                   push edi
// 00671e9a  8bf9                 mov edi, ecx
// 00671e9c  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 00671e9f  8b4744               mov eax, dword ptr [edi + 0x44]
// 00671ea2  89442408             mov dword ptr [esp + 8], eax
// 00671ea6  85c9                 test ecx, ecx
// 00671ea8  7409                 je 0x671eb3
// 00671eaa  8b11                 mov edx, dword ptr [ecx]
// 00671eac  8b4208               mov eax, dword ptr [edx + 8]
// 00671eaf  ffd0                 call eax
// 00671eb1  eb02                 jmp 0x671eb5
// 00671eb3  33c0                 xor eax, eax
// 00671eb5  8944240c             mov dword ptr [esp + 0xc], eax
// 00671eb9  8b742430             mov esi, dword ptr [esp + 0x30]
// 00671ebd  8b16                 mov edx, dword ptr [esi]
// 00671ebf  8b5204               mov edx, dword ptr [edx + 4]
// 00671ec2  8d442408             lea eax, [esp + 8]
// 00671ec6  50                   push eax
// 00671ec7  6a01                 push 1
// 00671ec9  8bce                 mov ecx, esi
// 00671ecb  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00671ed3  ffd2                 call edx
// 00671ed5  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00671ed9  6a00                 push 0
// 00671edb  68347db800           push 0xb87d34
// 00671ee0  684090b700           push 0xb79040
// 00671ee5  6a00                 push 0
// 00671ee7  50                   push eax
// 00671ee8  e8fd6c1300           call 0x7a8bea
// 00671eed  83c414               add esp, 0x14
// 00671ef0  85c0                 test eax, eax
// 00671ef2  751e                 jne 0x671f12
// 00671ef4  68540aa000           push 0xa00a54
// 00671ef9  8d4c2414             lea ecx, [esp + 0x14]
// 00671efd  ff159ca89e00         call dword ptr [0x9ea89c]
// 00671f03  689022b100           push 0xb12290
// 00671f08  8d4c2414             lea ecx, [esp + 0x14]
// 00671f0c  51                   push ecx
// 00671f0d  e8a06a1300           call 0x7a89b2
// 00671f12  8d542408             lea edx, [esp + 8]
// 00671f16  52                   push edx
// 00671f17  83c604               add esi, 4
// 00671f1a  56                   push esi
// 00671f1b  50                   push eax
// 00671f1c  8bcf                 mov ecx, edi
// 00671f1e  e87dfeffff           call 0x671da0
// 00671f23  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00671f27  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00671f2f  85c9                 test ecx, ecx
// 00671f31  7408                 je 0x671f3b
// 00671f33  8b01                 mov eax, dword ptr [ecx]
// 00671f35  8b10                 mov edx, dword ptr [eax]
// 00671f37  6a01                 push 1
// 00671f39  ffd2                 call edx
// 00671f3b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00671f3f  5f                   pop edi
// 00671f40  5e                   pop esi
// 00671f41  64890d00000000       mov dword ptr fs:[0], ecx
// 00671f48  83c420               add esp, 0x20
// 00671f4b  c20800               ret 8
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
