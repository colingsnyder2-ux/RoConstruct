// from server: 100% by colin
// from server: 96% by king_originala
// roc 2008-06 005bb120  unit: RBX::Soundscape::VSound::?$sp_counted_impl_p  size: 258 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bb120
//
// 005bb120  6aff                 push -1
// 005bb122  68b23b7d00           push 0x7d3bb2
// 005bb127  64a100000000         mov eax, dword ptr fs:[0]
// 005bb12d  50                   push eax
// 005bb12e  64892500000000       mov dword ptr fs:[0], esp
// 005bb135  51                   push ecx
// 005bb136  56                   push esi
// 005bb137  8bf1                 mov esi, ecx
// 005bb139  57                   push edi
// 005bb13a  89742408             mov dword ptr [esp + 8], esi
// 005bb13e  c706d47a8300         mov dword ptr [esi], 0x837ad4
// 005bb144  c74610c87a8300       mov dword ptr [esi + 0x10], 0x837ac8
// 005bb14b  c74614c07a8300       mov dword ptr [esi + 0x14], 0x837ac0
// 005bb152  c74620b87a8300       mov dword ptr [esi + 0x20], 0x837ab8
// 005bb159  c74624a87a8300       mov dword ptr [esi + 0x24], 0x837aa8
// 005bb160  c74644987a8300       mov dword ptr [esi + 0x44], 0x837a98
// 005bb167  c74664887a8300       mov dword ptr [esi + 0x64], 0x837a88
// 005bb16e  c78684000000787a8300 mov dword ptr [esi + 0x84], 0x837a78
// 005bb178  c786a4000000687a8300 mov dword ptr [esi + 0xa4], 0x837a68
// 005bb182  c786c4000000587a8300 mov dword ptr [esi + 0xc4], 0x837a58
// 005bb18c  c786300100004c7a8300 mov dword ptr [esi + 0x130], 0x837a4c
// 005bb196  8d8ea0010000         lea ecx, [esi + 0x1a0]
// 005bb19c  c744241403000000     mov dword ptr [esp + 0x14], 3
// 005bb1a4  e897fcffff           call 0x5bae40
// 005bb1a9  8d8e80010000         lea ecx, [esi + 0x180]
// 005bb1af  c644241402           mov byte ptr [esp + 0x14], 2
// 005bb1b4  e887fcffff           call 0x5bae40
// 005bb1b9  8bbe6c010000         mov edi, dword ptr [esi + 0x16c]
// 005bb1bf  c644241401           mov byte ptr [esp + 0x14], 1
// 005bb1c4  85ff                 test edi, edi
// 005bb1c6  742a                 je 0x5bb1f2
// 005bb1c8  8d4704               lea eax, [edi + 4]
// 005bb1cb  83c9ff               or ecx, 0xffffffff
// 005bb1ce  f00fc108             lock xadd dword ptr [eax], ecx
// 005bb1d2  751e                 jne 0x5bb1f2
// 005bb1d4  8b17                 mov edx, dword ptr [edi]
// 005bb1d6  8b4204               mov eax, dword ptr [edx + 4]
// 005bb1d9  8bcf                 mov ecx, edi
// 005bb1db  ffd0                 call eax
// 005bb1dd  8d4f08               lea ecx, [edi + 8]
// 005bb1e0  83caff               or edx, 0xffffffff
// 005bb1e3  f00fc111             lock xadd dword ptr [ecx], edx
// 005bb1e7  7509                 jne 0x5bb1f2
// 005bb1e9  8b07                 mov eax, dword ptr [edi]
// 005bb1eb  8b5008               mov edx, dword ptr [eax + 8]
// 005bb1ee  8bcf                 mov ecx, edi
// 005bb1f0  ffd2                 call edx
// 005bb1f2  8d8e3c010000         lea ecx, [esi + 0x13c]
// 005bb1f8  c644241400           mov byte ptr [esp + 0x14], 0
// 005bb1fd  e89e64efff           call 0x4b16a0
// 005bb202  8bce                 mov ecx, esi
// 005bb204  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005bb20c  e8cfb7ffff           call 0x5b69e0
// 005bb211  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005bb215  5f                   pop edi
// 005bb216  5e                   pop esi
// 005bb217  64890d00000000       mov dword ptr fs:[0], ecx
// 005bb21e  83c410               add esp, 0x10
// 005bb221  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)


struct Counted
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    Counted* count;
    ~Shared();
};

struct I00
{
    virtual void f00();
    unsigned char data[0xc];
};

struct I10
{
    virtual void f10();
};

struct I14
{
    virtual void f14();
    unsigned char data[0x8];
};

struct I20
{
    virtual void f20();
};

struct I24
{
    virtual void f24();
    unsigned char data[0x1c];
};

struct I44
{
    virtual void f44();
    unsigned char data[0x1c];
};

struct I64
{
    virtual void f64();
    unsigned char data[0x1c];
};

struct I84
{
    virtual void f84();
    unsigned char data[0x1c];
};

struct Ia4
{
    virtual void fa4();
    unsigned char data[0x1c];
};

struct Ic4
{
    virtual void fc4();
    unsigned char data[0x68];
};

struct I130
{
    virtual void f130();
    unsigned char data[0x8];
};

struct Base : I00, I10, I14, I20, I24, I44, I64, I84, Ia4, Ic4, I130
{
    ~Base();
};

struct Member
{
    unsigned char data[0x2c];
    ~Member();
};

struct Tail
{
    unsigned char data[0x20];
    ~Tail();
};

struct S : Base
{
    Member member;
    Shared shared;
    unsigned char padding[0x10];
    Tail first;
    Tail second;
    ~S();
};

__forceinline Shared::~Shared()
{
    Counted* p = count;
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

S::~S()
{
}
