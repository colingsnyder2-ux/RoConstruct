// from server: 100% by EspClaude
// roc 2009-06 004c5030  unit: RBX::Network::Players::Plugin  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c5030
//
// 004c5030  6aff                 push -1
// 004c5032  68f89c8500           push 0x859cf8
// 004c5037  64a100000000         mov eax, dword ptr fs:[0]
// 004c503d  50                   push eax
// 004c503e  64892500000000       mov dword ptr fs:[0], esp
// 004c5045  51                   push ecx
// 004c5046  56                   push esi
// 004c5047  8bf1                 mov esi, ecx
// 004c5049  57                   push edi
// 004c504a  89742408             mov dword ptr [esp + 8], esi
// 004c504e  8b7e08               mov edi, dword ptr [esi + 8]
// 004c5051  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004c5059  85ff                 test edi, edi
// 004c505b  7410                 je 0x4c506d
// 004c505d  8bcf                 mov ecx, edi
// 004c505f  e84c2f2400           call 0x707fb0
// 004c5064  57                   push edi
// 004c5065  e8c8392500           call 0x718a32
// 004c506a  83c404               add esp, 4
// 004c506d  8b7604               mov esi, dword ptr [esi + 4]
// 004c5070  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004c5078  85f6                 test esi, esi
// 004c507a  742a                 je 0x4c50a6
// 004c507c  8d4604               lea eax, [esi + 4]
// 004c507f  83c9ff               or ecx, 0xffffffff
// 004c5082  f00fc108             lock xadd dword ptr [eax], ecx
// 004c5086  751e                 jne 0x4c50a6
// 004c5088  8b16                 mov edx, dword ptr [esi]
// 004c508a  8b4204               mov eax, dword ptr [edx + 4]
// 004c508d  8bce                 mov ecx, esi
// 004c508f  ffd0                 call eax
// 004c5091  8d4e08               lea ecx, [esi + 8]
// 004c5094  83caff               or edx, 0xffffffff
// 004c5097  f00fc111             lock xadd dword ptr [ecx], edx
// 004c509b  7509                 jne 0x4c50a6
// 004c509d  8b06                 mov eax, dword ptr [esi]
// 004c509f  8b5008               mov edx, dword ptr [eax + 8]
// 004c50a2  8bce                 mov ecx, esi
// 004c50a4  ffd2                 call edx
// 004c50a6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004c50aa  5f                   pop edi
// 004c50ab  5e                   pop esi
// 004c50ac  64890d00000000       mov dword ptr fs:[0], ecx
// 004c50b3  83c410               add esp, 0x10
// 004c50b6  c3                   ret 
// copied from an identical function in another client (function ??1S@@QAE@XZ)

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

void __cdecl operator delete(void*);

struct Control {
    virtual ~Control();
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

struct Payload {
    ~Payload();
};

struct S {
    Shared shared;
    Payload* payload;
    ~S();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

S::~S()
{
    delete payload;
}