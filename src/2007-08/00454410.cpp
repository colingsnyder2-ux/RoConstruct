// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 00454410  unit: RBX::VInstance::?$MarshaledListener  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00454410
//
// 00454410  6aff                 push -1
// 00454412  687e157400           push 0x74157e
// 00454417  64a100000000         mov eax, dword ptr fs:[0]
// 0045441d  50                   push eax
// 0045441e  51                   push ecx
// 0045441f  56                   push esi
// 00454420  57                   push edi
// 00454421  a188518b00           mov eax, dword ptr [0x8b5188]
// 00454426  33c4                 xor eax, esp
// 00454428  50                   push eax
// 00454429  8d442410             lea eax, [esp + 0x10]
// 0045442d  64a300000000         mov dword ptr fs:[0], eax
// 00454433  8bf1                 mov esi, ecx
// 00454435  8974240c             mov dword ptr [esp + 0xc], esi
// 00454439  c706e4217900         mov dword ptr [esi], 0x7921e4
// 0045443f  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00454442  85c9                 test ecx, ecx
// 00454444  c744241802000000     mov dword ptr [esp + 0x18], 2
// 0045444c  7406                 je 0x454454
// 0045444e  56                   push esi
// 0045444f  e82c37feff           call 0x437b80
// 00454454  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00454457  85ff                 test edi, edi
// 00454459  c644241801           mov byte ptr [esp + 0x18], 1
// 0045445e  742a                 je 0x45448a
// 00454460  8d4704               lea eax, [edi + 4]
// 00454463  83c9ff               or ecx, 0xffffffff
// 00454466  f00fc108             lock xadd dword ptr [eax], ecx
// 0045446a  751e                 jne 0x45448a
// 0045446c  8b17                 mov edx, dword ptr [edi]
// 0045446e  8b4204               mov eax, dword ptr [edx + 4]
// 00454471  8bcf                 mov ecx, edi
// 00454473  ffd0                 call eax
// 00454475  8d4f08               lea ecx, [edi + 8]
// 00454478  83caff               or edx, 0xffffffff
// 0045447b  f00fc111             lock xadd dword ptr [ecx], edx
// 0045447f  7509                 jne 0x45448a
// 00454481  8b07                 mov eax, dword ptr [edi]
// 00454483  8b5008               mov edx, dword ptr [eax + 8]
// 00454486  8bcf                 mov ecx, edi
// 00454488  ffd2                 call edx
// 0045448a  8b7e08               mov edi, dword ptr [esi + 8]
// 0045448d  85ff                 test edi, edi
// 0045448f  c644241800           mov byte ptr [esp + 0x18], 0
// 00454494  742a                 je 0x4544c0
// 00454496  8d4704               lea eax, [edi + 4]
// 00454499  83c9ff               or ecx, 0xffffffff
// 0045449c  f00fc108             lock xadd dword ptr [eax], ecx
// 004544a0  751e                 jne 0x4544c0
// 004544a2  8b17                 mov edx, dword ptr [edi]
// 004544a4  8b4204               mov eax, dword ptr [edx + 4]
// 004544a7  8bcf                 mov ecx, edi
// 004544a9  ffd0                 call eax
// 004544ab  8d4f08               lea ecx, [edi + 8]
// 004544ae  83caff               or edx, 0xffffffff
// 004544b1  f00fc111             lock xadd dword ptr [ecx], edx
// 004544b5  7509                 jne 0x4544c0
// 004544b7  8b07                 mov eax, dword ptr [edi]
// 004544b9  8b5008               mov edx, dword ptr [eax + 8]
// 004544bc  8bcf                 mov ecx, edi
// 004544be  ffd2                 call edx
// 004544c0  c706687f7800         mov dword ptr [esi], 0x787f68
// 004544c6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004544ca  64890d00000000       mov dword ptr fs:[0], ecx
// 004544d1  59                   pop ecx
// 004544d2  5f                   pop edi
// 004544d3  5e                   pop esi
// 004544d4  83c410               add esp, 0x10
// 004544d7  c3                   ret 
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
    ~Shared();
};

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

struct S;

struct Owner
{
    void detach(S*);
};

struct Base
{
    virtual ~Base();
};

inline Base::~Base()
{
}

struct S : Base
{
    Shared connection;
    Owner* owner;
    Shared listener;

    virtual ~S();
};

S::~S()
{
    if (owner)
        owner->detach(this);
}
