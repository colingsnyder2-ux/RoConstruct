// from server: 100% by colin
// from server: 96% by king_originala
// roc 2008-06 005b7680  unit: P8CRenderSettings::?$GetSetImpl  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b7680
//
// from server: 96% by king_originala
// roc 2008-06 005b7680  unit: P8CRenderSettings::?$GetSetImpl  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b7680
//
// 005b7680  6aff                 push -1
// 005b7682  68163a7d00           push 0x7d3a16
// 005b7687  64a100000000         mov eax, dword ptr fs:[0]
// 005b768d  50                   push eax
// 005b768e  64892500000000       mov dword ptr fs:[0], esp
// 005b7695  51                   push ecx
// 005b7696  56                   push esi
// 005b7697  8bf1                 mov esi, ecx
// 005b7699  57                   push edi
// 005b769a  89742408             mov dword ptr [esp + 8], esi
// 005b769e  c706fc768300         mov dword ptr [esi], 0x8376fc
// 005b76a4  c74610ec768300       mov dword ptr [esi + 0x10], 0x8376ec
// 005b76ab  c74614e4768300       mov dword ptr [esi + 0x14], 0x8376e4
// 005b76b2  c74620dc768300       mov dword ptr [esi + 0x20], 0x8376dc
// 005b76b9  c74624cc768300       mov dword ptr [esi + 0x24], 0x8376cc
// 005b76c0  c74644bc768300       mov dword ptr [esi + 0x44], 0x8376bc
// 005b76c7  c74664ac768300       mov dword ptr [esi + 0x64], 0x8376ac
// 005b76ce  c786840000009c768300 mov dword ptr [esi + 0x84], 0x83769c
// 005b76d8  c786a40000008c768300 mov dword ptr [esi + 0xa4], 0x83768c
// 005b76e2  c786c40000007c768300 mov dword ptr [esi + 0xc4], 0x83767c
// 005b76ec  c7863001000070768300 mov dword ptr [esi + 0x130], 0x837670
// 005b76f6  8d8e40010000         lea ecx, [esi + 0x140]
// 005b76fc  c744241401000000     mov dword ptr [esp + 0x14], 1
// 005b7704  ff1568248000         call dword ptr [0x802468]
// 005b770a  8bbe38010000         mov edi, dword ptr [esi + 0x138]
// 005b7710  c644241400           mov byte ptr [esp + 0x14], 0
// 005b7715  85ff                 test edi, edi
// 005b7717  742a                 je 0x5b7743
// 005b7719  8d4704               lea eax, [edi + 4]
// 005b771c  83c9ff               or ecx, 0xffffffff
// 005b771f  f00fc108             lock xadd dword ptr [eax], ecx
// 005b7723  751e                 jne 0x5b7743
// 005b7725  8b17                 mov edx, dword ptr [edi]
// 005b7727  8b4204               mov eax, dword ptr [edx + 4]
// 005b772a  8bcf                 mov ecx, edi
// 005b772c  ffd0                 call eax
// 005b772e  8d4f08               lea ecx, [edi + 8]
// 005b7731  83caff               or edx, 0xffffffff
// 005b7734  f00fc111             lock xadd dword ptr [ecx], edx
// 005b7738  7509                 jne 0x5b7743
// 005b773a  8b07                 mov eax, dword ptr [edi]
// 005b773c  8b5008               mov edx, dword ptr [eax + 8]
// 005b773f  8bcf                 mov ecx, edi
// 005b7741  ffd2                 call edx
// 005b7743  8bce                 mov ecx, esi
// 005b7745  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005b774d  e8eef2ffff           call 0x5b6a40
// 005b7752  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005b7756  5f                   pop edi
// 005b7757  5e                   pop esi
// 005b7758  64890d00000000       mov dword ptr fs:[0], ecx
// 005b775f  83c410               add esp, 0x10
// 005b7762  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* pointer;
    Control* control;
    ~Shared();
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

struct String {
    unsigned char storage[28];
    ~String();
};

extern void (__thiscall *StringDestroy)(String*);

inline String::~String()
{
    StringDestroy(this);
}

struct I00 { virtual void f00(); unsigned char data[0xc]; };
struct I10 { virtual void f10(); };
struct I14 { virtual void f14(); unsigned char data[0x8]; };
struct I20 { virtual void f20(); };
struct I24 { virtual void f24(); unsigned char data[0x1c]; };
struct I44 { virtual void f44(); unsigned char data[0x1c]; };
struct I64 { virtual void f64(); unsigned char data[0x1c]; };
struct I84 { virtual void f84(); unsigned char data[0x1c]; };
struct Ia4 { virtual void fa4(); unsigned char data[0x1c]; };
struct Ic4 { virtual void fc4(); unsigned char data[0x68]; };
struct I130 { virtual void f130(); };

struct Base : I00, I10, I14, I20, I24, I44, I64, I84, Ia4, Ic4 {
    ~Base();
};

struct S : Base, I130 {
    Shared shared;
    unsigned long padding;
    String text;
    ~S();
};

S::~S()
{
}
