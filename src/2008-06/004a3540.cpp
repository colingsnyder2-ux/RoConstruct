// from server: 100% by colin
// from server: 95% by king_originala
// roc 2008-06 004a3540  unit: RBX::Network::Server::ClientProxy  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a3540
//
// from server: 95% by king_originala
// roc 2008-06 004a3540  unit: RBX::Network::Server::ClientProxy  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a3540
//
// 004a3540  6aff                 push -1
// 004a3542  68d47c7c00           push 0x7c7cd4
// 004a3547  64a100000000         mov eax, dword ptr fs:[0]
// 004a354d  50                   push eax
// 004a354e  64892500000000       mov dword ptr fs:[0], esp
// 004a3555  51                   push ecx
// 004a3556  56                   push esi
// 004a3557  8bf1                 mov esi, ecx
// 004a3559  57                   push edi
// 004a355a  89742408             mov dword ptr [esp + 8], esi
// 004a355e  c7067c368200         mov dword ptr [esi], 0x82367c
// 004a3564  c7461070368200       mov dword ptr [esi + 0x10], 0x823670
// 004a356b  c7461468368200       mov dword ptr [esi + 0x14], 0x823668
// 004a3572  c7462060368200       mov dword ptr [esi + 0x20], 0x823660
// 004a3579  c7462450368200       mov dword ptr [esi + 0x24], 0x823650
// 004a3580  c7464440368200       mov dword ptr [esi + 0x44], 0x823640
// 004a3587  c7466430368200       mov dword ptr [esi + 0x64], 0x823630
// 004a358e  c7868400000020368200 mov dword ptr [esi + 0x84], 0x823620
// 004a3598  c786a400000010368200 mov dword ptr [esi + 0xa4], 0x823610
// 004a35a2  c786c400000000368200 mov dword ptr [esi + 0xc4], 0x823600
// 004a35ac  c78630010000d0358200 mov dword ptr [esi + 0x130], 0x8235d0
// 004a35b6  c78634010000c4358200 mov dword ptr [esi + 0x134], 0x8235c4
// 004a35c0  8d8e64010000         lea ecx, [esi + 0x164]
// 004a35c6  c744241402000000     mov dword ptr [esp + 0x14], 2
// 004a35ce  e89dfeffff           call 0x4a3470
// 004a35d3  8d8e50010000         lea ecx, [esi + 0x150]
// 004a35d9  c644241401           mov byte ptr [esp + 0x14], 1
// 004a35de  e8cd1e0f00           call 0x5954b0
// 004a35e3  8bbe4c010000         mov edi, dword ptr [esi + 0x14c]
// 004a35e9  c644241400           mov byte ptr [esp + 0x14], 0
// 004a35ee  85ff                 test edi, edi
// 004a35f0  742a                 je 0x4a361c
// 004a35f2  8d4704               lea eax, [edi + 4]
// 004a35f5  83c9ff               or ecx, 0xffffffff
// 004a35f8  f00fc108             lock xadd dword ptr [eax], ecx
// 004a35fc  751e                 jne 0x4a361c
// 004a35fe  8b17                 mov edx, dword ptr [edi]
// 004a3600  8b4204               mov eax, dword ptr [edx + 4]
// 004a3603  8bcf                 mov ecx, edi
// 004a3605  ffd0                 call eax
// 004a3607  8d4f08               lea ecx, [edi + 8]
// 004a360a  83caff               or edx, 0xffffffff
// 004a360d  f00fc111             lock xadd dword ptr [ecx], edx
// 004a3611  7509                 jne 0x4a361c
// 004a3613  8b07                 mov eax, dword ptr [edi]
// 004a3615  8b5008               mov edx, dword ptr [eax + 8]
// 004a3618  8bcf                 mov ecx, edi
// 004a361a  ffd2                 call edx
// 004a361c  8bce                 mov ecx, esi
// 004a361e  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004a3626  e855dfffff           call 0x4a1580
// 004a362b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a362f  5f                   pop edi
// 004a3630  5e                   pop esi
// 004a3631  64890d00000000       mov dword ptr fs:[0], ecx
// 004a3638  83c410               add esp, 0x10
// 004a363b  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Count {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* pointer;
    Count* count;
    ~Shared();
};

inline Shared::~Shared()
{
    Count* p = count;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Member150 {
    unsigned int data[5];
    ~Member150();
};

struct Member164 {
    unsigned int data;
    ~Member164();
};

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
struct I134 { virtual void f134(); unsigned char data[0x10]; };

struct Base : I00, I10, I14, I20, I24, I44, I64, I84, Ia4, Ic4 {
    ~Base();
};

struct S : Base, I130, I134 {
    Shared shared;
    Member150 member150;
    Member164 member164;
    ~S();
};

S::~S()
{
}
