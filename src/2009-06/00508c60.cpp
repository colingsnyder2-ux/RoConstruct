// from server: 100% by EspClaude
// roc 2009-06 00508c60  unit: RBX::Network::PhysicsSender::Job  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00508c60
//
// 00508c60  6aff                 push -1
// 00508c62  68e0d58500           push 0x85d5e0
// 00508c67  64a100000000         mov eax, dword ptr fs:[0]
// 00508c6d  50                   push eax
// 00508c6e  64892500000000       mov dword ptr fs:[0], esp
// 00508c75  51                   push ecx
// 00508c76  53                   push ebx
// 00508c77  56                   push esi
// 00508c78  8bf1                 mov esi, ecx
// 00508c7a  57                   push edi
// 00508c7b  8974240c             mov dword ptr [esp + 0xc], esi
// 00508c7f  8b442420             mov eax, dword ptr [esp + 0x20]
// 00508c83  8906                 mov dword ptr [esi], eax
// 00508c85  8b442424             mov eax, dword ptr [esp + 0x24]
// 00508c89  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00508c91  894604               mov dword ptr [esi + 4], eax
// 00508c94  85c0                 test eax, eax
// 00508c96  740c                 je 0x508ca4
// 00508c98  83c004               add eax, 4
// 00508c9b  b901000000           mov ecx, 1
// 00508ca0  f00fc108             lock xadd dword ptr [eax], ecx
// 00508ca4  8d4e10               lea ecx, [esi + 0x10]
// 00508ca7  c644241801           mov byte ptr [esp + 0x18], 1
// 00508cac  e8ff6bf9ff           call 0x49f8b0
// 00508cb1  d90598609f00         fld dword ptr [0x9f6098]
// 00508cb7  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00508cbb  d95e40               fstp dword ptr [esi + 0x40]
// 00508cbe  83cbff               or ebx, 0xffffffff
// 00508cc1  895e44               mov dword ptr [esi + 0x44], ebx
// 00508cc4  895c2418             mov dword ptr [esp + 0x18], ebx
// 00508cc8  85ff                 test edi, edi
// 00508cca  7426                 je 0x508cf2
// 00508ccc  8d5704               lea edx, [edi + 4]
// 00508ccf  8bc3                 mov eax, ebx
// 00508cd1  f00fc102             lock xadd dword ptr [edx], eax
// 00508cd5  751b                 jne 0x508cf2
// 00508cd7  8b17                 mov edx, dword ptr [edi]
// 00508cd9  8b4204               mov eax, dword ptr [edx + 4]
// 00508cdc  8bcf                 mov ecx, edi
// 00508cde  ffd0                 call eax
// 00508ce0  8d4f08               lea ecx, [edi + 8]
// 00508ce3  f00fc119             lock xadd dword ptr [ecx], ebx
// 00508ce7  7509                 jne 0x508cf2
// 00508ce9  8b17                 mov edx, dword ptr [edi]
// 00508ceb  8b4208               mov eax, dword ptr [edx + 8]
// 00508cee  8bcf                 mov ecx, edi
// 00508cf0  ffd0                 call eax
// 00508cf2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00508cf6  5f                   pop edi
// 00508cf7  8bc6                 mov eax, esi
// 00508cf9  5e                   pop esi
// 00508cfa  5b                   pop ebx
// 00508cfb  64890d00000000       mov dword ptr fs:[0], ecx
// 00508d02  83c410               add esp, 0x10
// 00508d05  c20800               ret 8
// copied from an identical function in another client (function ??0S@ns_ROCX000005@@QAE@UShared@1@@Z)

namespace ns_ROCX000005 {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared& source);
    ~Shared();
};

inline Shared::Shared(const Shared& source)
    : pointer(source.pointer), control(source.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Member {
    char storage[48];
    Member();
};

extern float initialValue;

struct S {
    Shared owner;
    char padding[8];
    Member member;
    float value;
    int index;

    S(Shared source);
};

S::S(Shared source)
    : owner(source), member(), value(initialValue), index(-1)
{
}
}
