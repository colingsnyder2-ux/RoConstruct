// from server: 100% by Yeetserama
// roc 2007-08 0040d550  unit: ChatEnter  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040d550
//
// 0040d550  6aff                 push -1
// 0040d552  68f09d7300           push 0x739df0
// 0040d557  64a100000000         mov eax, dword ptr fs:[0]
// 0040d55d  50                   push eax
// 0040d55e  51                   push ecx
// 0040d55f  56                   push esi
// 0040d560  57                   push edi
// 0040d561  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040d566  33c4                 xor eax, esp
// 0040d568  50                   push eax
// 0040d569  8d442410             lea eax, [esp + 0x10]
// 0040d56d  64a300000000         mov dword ptr fs:[0], eax
// 0040d573  8bf1                 mov esi, ecx
// 0040d575  8974240c             mov dword ptr [esp + 0xc], esi
// 0040d579  c70600000000         mov dword ptr [esi], 0
// 0040d57f  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0040d587  c7460400000000       mov dword ptr [esi + 4], 0
// 0040d58e  8b442420             mov eax, dword ptr [esp + 0x20]
// 0040d592  50                   push eax
// 0040d593  c644241c01           mov byte ptr [esp + 0x1c], 1
// 0040d598  c7460800000000       mov dword ptr [esi + 8], 0
// 0040d59f  e82cbd1400           call 0x5592d0
// 0040d5a4  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0040d5a8  85ff                 test edi, edi
// 0040d5aa  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0040d5b2  742a                 je 0x40d5de
// 0040d5b4  8d4f04               lea ecx, [edi + 4]
// 0040d5b7  83caff               or edx, 0xffffffff
// 0040d5ba  f00fc111             lock xadd dword ptr [ecx], edx
// 0040d5be  751e                 jne 0x40d5de
// 0040d5c0  8b07                 mov eax, dword ptr [edi]
// 0040d5c2  8b5004               mov edx, dword ptr [eax + 4]
// 0040d5c5  8bcf                 mov ecx, edi
// 0040d5c7  ffd2                 call edx
// 0040d5c9  8d4708               lea eax, [edi + 8]
// 0040d5cc  83c9ff               or ecx, 0xffffffff
// 0040d5cf  f00fc108             lock xadd dword ptr [eax], ecx
// 0040d5d3  7509                 jne 0x40d5de
// 0040d5d5  8b17                 mov edx, dword ptr [edi]
// 0040d5d7  8b4208               mov eax, dword ptr [edx + 8]
// 0040d5da  8bcf                 mov ecx, edi
// 0040d5dc  ffd0                 call eax
// 0040d5de  8bc6                 mov eax, esi
// 0040d5e0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040d5e4  64890d00000000       mov dword ptr fs:[0], ecx
// 0040d5eb  59                   pop ecx
// 0040d5ec  5f                   pop edi
// 0040d5ed  5e                   pop esi
// 0040d5ee  83c410               add esp, 0x10
// 0040d5f1  c20800               ret 8
// copied from an identical function in another client (function ??0S@ns_ROCX000018@@QAE@UShared@1@@Z)

namespace ns_ROCX000018 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

__forceinline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Second {
    void* value;
    Second();
    ~Second();
};

__forceinline Second::Second() : value(0)
{
}

struct S {
    void* first;
    Second second;
    void* third;

    S(Shared argument);
    void assign(void* object);
};

S::S(Shared argument) : first(0), third(0)
{
    assign(argument.object);
}
}
