// from server: 100% by Yeetserama
// roc 2007-08 00454500  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 191 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00454500
//
// 00454500  6aff                 push -1
// 00454502  6836157400           push 0x741536
// 00454507  64a100000000         mov eax, dword ptr fs:[0]
// 0045450d  50                   push eax
// 0045450e  51                   push ecx
// 0045450f  56                   push esi
// 00454510  57                   push edi
// 00454511  a188518b00           mov eax, dword ptr [0x8b5188]
// 00454516  33c4                 xor eax, esp
// 00454518  50                   push eax
// 00454519  8d442410             lea eax, [esp + 0x10]
// 0045451d  64a300000000         mov dword ptr fs:[0], eax
// 00454523  8bf1                 mov esi, ecx
// 00454525  8974240c             mov dword ptr [esp + 0xc], esi
// 00454529  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00454531  c706f0217900         mov dword ptr [esi], 0x7921f0
// 00454537  c7460400000000       mov dword ptr [esi + 4], 0
// 0045453e  c7460800000000       mov dword ptr [esi + 8], 0
// 00454545  8b442420             mov eax, dword ptr [esp + 0x20]
// 00454549  8d4c2428             lea ecx, [esp + 0x28]
// 0045454d  51                   push ecx
// 0045454e  8d4e10               lea ecx, [esi + 0x10]
// 00454551  c644241c02           mov byte ptr [esp + 0x1c], 2
// 00454556  89460c               mov dword ptr [esi + 0xc], eax
// 00454559  e802270500           call 0x4a6c60
// 0045455e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00454562  52                   push edx
// 00454563  8bce                 mov ecx, esi
// 00454565  c644241c03           mov byte ptr [esp + 0x1c], 3
// 0045456a  e8e1fbffff           call 0x454150
// 0045456f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00454573  85ff                 test edi, edi
// 00454575  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0045457d  742a                 je 0x4545a9
// 0045457f  8d4704               lea eax, [edi + 4]
// 00454582  83c9ff               or ecx, 0xffffffff
// 00454585  f00fc108             lock xadd dword ptr [eax], ecx
// 00454589  751e                 jne 0x4545a9
// 0045458b  8b17                 mov edx, dword ptr [edi]
// 0045458d  8b4204               mov eax, dword ptr [edx + 4]
// 00454590  8bcf                 mov ecx, edi
// 00454592  ffd0                 call eax
// 00454594  8d4f08               lea ecx, [edi + 8]
// 00454597  83caff               or edx, 0xffffffff
// 0045459a  f00fc111             lock xadd dword ptr [ecx], edx
// 0045459e  7509                 jne 0x4545a9
// 004545a0  8b07                 mov eax, dword ptr [edi]
// 004545a2  8b5008               mov edx, dword ptr [eax + 8]
// 004545a5  8bcf                 mov ecx, edi
// 004545a7  ffd2                 call edx
// 004545a9  8bc6                 mov eax, esi
// 004545ab  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004545af  64890d00000000       mov dword ptr fs:[0], ecx
// 004545b6  59                   pop ecx
// 004545b7  5f                   pop edi
// 004545b8  5e                   pop esi
// 004545b9  83c410               add esp, 0x10
// 004545bc  c21000               ret 0x10
// copied from an identical function in another client (function ??0S@ns_ROCX000009@@QAE@PAX0UShared@1@@Z)

namespace ns_ROCX000009 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* pointer;
    Control* control;

    Shared();
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared() : pointer(0), control(0)
{
}

inline Shared::~Shared()
{
    Control* p = control;
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

struct Base
{
    virtual ~Base();
};

struct S : Base
{
    Shared connection;
    void* owner;
    Shared listener;

    S(void*, void*, Shared);
    virtual ~S();
    void attach(void*);
};

S::S(void* a, void* b, Shared value)
    : owner(a), listener(value)
{
    attach(b);
}
}
