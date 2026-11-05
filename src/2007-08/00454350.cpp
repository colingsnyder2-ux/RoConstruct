// from server: 100% by Yeetserama
// roc 2007-08 00454350  unit: RBX::VInstance::?$MarshaledListener  size: 191 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00454350
//
// 00454350  6aff                 push -1
// 00454352  6836157400           push 0x741536
// 00454357  64a100000000         mov eax, dword ptr fs:[0]
// 0045435d  50                   push eax
// 0045435e  51                   push ecx
// 0045435f  56                   push esi
// 00454360  57                   push edi
// 00454361  a188518b00           mov eax, dword ptr [0x8b5188]
// 00454366  33c4                 xor eax, esp
// 00454368  50                   push eax
// 00454369  8d442410             lea eax, [esp + 0x10]
// 0045436d  64a300000000         mov dword ptr fs:[0], eax
// 00454373  8bf1                 mov esi, ecx
// 00454375  8974240c             mov dword ptr [esp + 0xc], esi
// 00454379  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00454381  c706e4217900         mov dword ptr [esi], 0x7921e4
// 00454387  c7460400000000       mov dword ptr [esi + 4], 0
// 0045438e  c7460800000000       mov dword ptr [esi + 8], 0
// 00454395  8b442420             mov eax, dword ptr [esp + 0x20]
// 00454399  8d4c2428             lea ecx, [esp + 0x28]
// 0045439d  51                   push ecx
// 0045439e  8d4e10               lea ecx, [esi + 0x10]
// 004543a1  c644241c02           mov byte ptr [esp + 0x1c], 2
// 004543a6  89460c               mov dword ptr [esi + 0xc], eax
// 004543a9  e8b2280500           call 0x4a6c60
// 004543ae  8b542424             mov edx, dword ptr [esp + 0x24]
// 004543b2  52                   push edx
// 004543b3  8bce                 mov ecx, esi
// 004543b5  c644241c03           mov byte ptr [esp + 0x1c], 3
// 004543ba  e891fdffff           call 0x454150
// 004543bf  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004543c3  85ff                 test edi, edi
// 004543c5  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004543cd  742a                 je 0x4543f9
// 004543cf  8d4704               lea eax, [edi + 4]
// 004543d2  83c9ff               or ecx, 0xffffffff
// 004543d5  f00fc108             lock xadd dword ptr [eax], ecx
// 004543d9  751e                 jne 0x4543f9
// 004543db  8b17                 mov edx, dword ptr [edi]
// 004543dd  8b4204               mov eax, dword ptr [edx + 4]
// 004543e0  8bcf                 mov ecx, edi
// 004543e2  ffd0                 call eax
// 004543e4  8d4f08               lea ecx, [edi + 8]
// 004543e7  83caff               or edx, 0xffffffff
// 004543ea  f00fc111             lock xadd dword ptr [ecx], edx
// 004543ee  7509                 jne 0x4543f9
// 004543f0  8b07                 mov eax, dword ptr [edi]
// 004543f2  8b5008               mov edx, dword ptr [eax + 8]
// 004543f5  8bcf                 mov ecx, edi
// 004543f7  ffd2                 call edx
// 004543f9  8bc6                 mov eax, esi
// 004543fb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004543ff  64890d00000000       mov dword ptr fs:[0], ecx
// 00454406  59                   pop ecx
// 00454407  5f                   pop edi
// 00454408  5e                   pop esi
// 00454409  83c410               add esp, 0x10
// 0045440c  c21000               ret 0x10
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
