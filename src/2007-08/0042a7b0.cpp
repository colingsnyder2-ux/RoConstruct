// from server: 100% by Yeetserama
// roc 2007-08 0042a7b0  unit: CLuaHtmlView  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042a7b0
//
// 0042a7b0  6aff                 push -1
// 0042a7b2  6858cf7300           push 0x73cf58
// 0042a7b7  64a100000000         mov eax, dword ptr fs:[0]
// 0042a7bd  50                   push eax
// 0042a7be  51                   push ecx
// 0042a7bf  56                   push esi
// 0042a7c0  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042a7c5  33c4                 xor eax, esp
// 0042a7c7  50                   push eax
// 0042a7c8  8d44240c             lea eax, [esp + 0xc]
// 0042a7cc  64a300000000         mov dword ptr fs:[0], eax
// 0042a7d2  8bf1                 mov esi, ecx
// 0042a7d4  89742408             mov dword ptr [esp + 8], esi
// 0042a7d8  8d4e0c               lea ecx, [esi + 0xc]
// 0042a7db  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0042a7e3  e8b8dd2f00           call 0x7285a0
// 0042a7e8  8b7604               mov esi, dword ptr [esi + 4]
// 0042a7eb  85f6                 test esi, esi
// 0042a7ed  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0042a7f5  742a                 je 0x42a821
// 0042a7f7  8d4604               lea eax, [esi + 4]
// 0042a7fa  83c9ff               or ecx, 0xffffffff
// 0042a7fd  f00fc108             lock xadd dword ptr [eax], ecx
// 0042a801  751e                 jne 0x42a821
// 0042a803  8b16                 mov edx, dword ptr [esi]
// 0042a805  8b4204               mov eax, dword ptr [edx + 4]
// 0042a808  8bce                 mov ecx, esi
// 0042a80a  ffd0                 call eax
// 0042a80c  8d4e08               lea ecx, [esi + 8]
// 0042a80f  83caff               or edx, 0xffffffff
// 0042a812  f00fc111             lock xadd dword ptr [ecx], edx
// 0042a816  7509                 jne 0x42a821
// 0042a818  8b06                 mov eax, dword ptr [esi]
// 0042a81a  8b5008               mov edx, dword ptr [eax + 8]
// 0042a81d  8bce                 mov ecx, esi
// 0042a81f  ffd2                 call edx
// 0042a821  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0042a825  64890d00000000       mov dword ptr fs:[0], ecx
// 0042a82c  59                   pop ecx
// 0042a82d  5e                   pop esi
// 0042a82e  83c410               add esp, 0x10
// 0042a831  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX000009@@QAE@XZ)

namespace ns_ROCX000009 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Count
{
    virtual ~Count();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Reference
{
    void* pointer;
    Count* count;
    ~Reference();
};

inline Reference::~Reference()
{
    Count* p = count;
    if (p)
    {
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Tail
{
    ~Tail();
};

struct S
{
    Reference reference;
    int value;
    Tail tail;
    ~S();
};

S::~S()
{
}
}
