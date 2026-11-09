// from server: 100% by colin
// from server: 97% by colin
// roc 2008-06 00494c60  unit: RBX::VRunService::?$SignalDesc  size: 372 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00494c60
//
// 00494c60  6aff                 push -1
// 00494c62  683f687c00           push 0x7c683f
// 00494c67  64a100000000         mov eax, dword ptr fs:[0]
// 00494c6d  50                   push eax
// 00494c6e  64892500000000       mov dword ptr fs:[0], esp
// 00494c75  51                   push ecx
// 00494c76  53                   push ebx
// 00494c77  56                   push esi
// 00494c78  8bf1                 mov esi, ecx
// 00494c7a  57                   push edi
// 00494c7b  8974240c             mov dword ptr [esp + 0xc], esi
// 00494c7f  c7060c228200         mov dword ptr [esi], 0x82220c
// 00494c85  c74610fc218200       mov dword ptr [esi + 0x10], 0x8221fc
// 00494c8c  c74614f4218200       mov dword ptr [esi + 0x14], 0x8221f4
// 00494c93  c74620ec218200       mov dword ptr [esi + 0x20], 0x8221ec
// 00494c9a  c74624dc218200       mov dword ptr [esi + 0x24], 0x8221dc
// 00494ca1  c74644cc218200       mov dword ptr [esi + 0x44], 0x8221cc
// 00494ca8  c74664bc218200       mov dword ptr [esi + 0x64], 0x8221bc
// 00494caf  c78684000000ac218200 mov dword ptr [esi + 0x84], 0x8221ac
// 00494cb9  c786a40000009c218200 mov dword ptr [esi + 0xa4], 0x82219c
// 00494cc3  c786c40000008c218200 mov dword ptr [esi + 0xc4], 0x82218c
// 00494ccd  c786300100007c218200 mov dword ptr [esi + 0x130], 0x82217c
// 00494cd7  c786500100006c218200 mov dword ptr [esi + 0x150], 0x82216c
// 00494ce1  33db                 xor ebx, ebx
// 00494ce3  53                   push ebx
// 00494ce4  c744241c05000000     mov dword ptr [esp + 0x1c], 5
// 00494cec  e8bff7ffff           call 0x4944b0
// 00494cf1  8d8e94010000         lea ecx, [esi + 0x194]
// 00494cf7  c644241804           mov byte ptr [esp + 0x18], 4
// 00494cfc  ff1568248000         call dword ptr [0x802468]
// 00494d02  8d8e80010000         lea ecx, [esi + 0x180]
// 00494d08  c644241803           mov byte ptr [esp + 0x18], 3
// 00494d0d  e89e071000           call 0x5954b0
// 00494d12  8bbe74010000         mov edi, dword ptr [esi + 0x174]
// 00494d18  c644241802           mov byte ptr [esp + 0x18], 2
// 00494d1d  3bfb                 cmp edi, ebx
// 00494d1f  742a                 je 0x494d4b
// 00494d21  8d4704               lea eax, [edi + 4]
// 00494d24  83c9ff               or ecx, 0xffffffff
// 00494d27  f00fc108             lock xadd dword ptr [eax], ecx
// 00494d2b  751e                 jne 0x494d4b
// 00494d2d  8b17                 mov edx, dword ptr [edi]
// 00494d2f  8b4204               mov eax, dword ptr [edx + 4]
// 00494d32  8bcf                 mov ecx, edi
// 00494d34  ffd0                 call eax
// 00494d36  8d4f08               lea ecx, [edi + 8]
// 00494d39  83caff               or edx, 0xffffffff
// 00494d3c  f00fc111             lock xadd dword ptr [ecx], edx
// 00494d40  7509                 jne 0x494d4b
// 00494d42  8b07                 mov eax, dword ptr [edi]
// 00494d44  8b5008               mov edx, dword ptr [eax + 8]
// 00494d47  8bcf                 mov ecx, edi
// 00494d49  ffd2                 call edx
// 00494d4b  8b8660010000         mov eax, dword ptr [esi + 0x160]
// 00494d51  3bc3                 cmp eax, ebx
// 00494d53  7409                 je 0x494d5e
// 00494d55  50                   push eax
// 00494d56  e81fb92000           call 0x6a067a
// 00494d5b  83c404               add esp, 4
// 00494d5e  8b8654010000         mov eax, dword ptr [esi + 0x154]
// 00494d64  50                   push eax
// 00494d65  899e60010000         mov dword ptr [esi + 0x160], ebx
// 00494d6b  899e64010000         mov dword ptr [esi + 0x164], ebx
// 00494d71  899e68010000         mov dword ptr [esi + 0x168], ebx
// 00494d77  e8feb82000           call 0x6a067a
// 00494d7c  8b8640010000         mov eax, dword ptr [esi + 0x140]
// 00494d82  83c404               add esp, 4
// 00494d85  3bc3                 cmp eax, ebx
// 00494d87  7409                 je 0x494d92
// 00494d89  50                   push eax
// 00494d8a  e8ebb82000           call 0x6a067a
// 00494d8f  83c404               add esp, 4
// 00494d92  8b8634010000         mov eax, dword ptr [esi + 0x134]
// 00494d98  50                   push eax
// 00494d99  899e40010000         mov dword ptr [esi + 0x140], ebx
// 00494d9f  899e44010000         mov dword ptr [esi + 0x144], ebx
// 00494da5  899e48010000         mov dword ptr [esi + 0x148], ebx
// 00494dab  e8cab82000           call 0x6a067a
// 00494db0  83c404               add esp, 4
// 00494db3  8bce                 mov ecx, esi
// 00494db5  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00494dbd  e81e4cffff           call 0x4899e0
// 00494dc2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00494dc6  5f                   pop edi
// 00494dc7  5e                   pop esi
// 00494dc8  5b                   pop ebx
// 00494dc9  64890d00000000       mov dword ptr fs:[0], ecx
// 00494dd0  83c410               add esp, 0x10
// 00494dd3  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void __cdecl sub_6a067a(void*);

struct RefCount
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
    RefCount* count;
    unsigned long padding[2];
    ~Shared();
};

struct __declspec(novtable) Buffer
{
    virtual void bufferMethod();
    void* allocation;
    unsigned long padding[2];
    void* data;
    unsigned long size;
    unsigned long capacity;
    unsigned long tail;
    ~Buffer();
};

struct Buffer1 : Buffer {};
struct Buffer2 : Buffer {};

struct ThreadRef
{
    unsigned char storage[20];
    ~ThreadRef();
};

struct String
{
    unsigned char storage[28];
    ~String();
};

extern void (__thiscall *string_destructor)(String*);

struct P00 { virtual void m00(); unsigned long pad[3]; };
struct P10 { virtual void m10(); };
struct P14 { virtual void m14(); unsigned long pad[2]; };
struct P20 { virtual void m20(); };
struct P24 { virtual void m24(); unsigned long pad[7]; };
struct P44 { virtual void m44(); unsigned long pad[7]; };
struct P64 { virtual void m64(); unsigned long pad[7]; };
struct P84 { virtual void m84(); unsigned long pad[7]; };
struct PA4 { virtual void mA4(); unsigned long pad[7]; };
struct PC4 { virtual void mC4(); unsigned long pad[26]; };

struct Base : P00, P10, P14, P20, P24, P44, P64, P84, PA4, PC4
{
    ~Base();
};

struct S : Base, Buffer1, Buffer2
{
    Shared shared;
    ThreadRef thread;
    String string;

    void sub_4944b0(int);
    ~S();
};

inline String::~String()
{
    string_destructor(this);
}

inline Shared::~Shared()
{
    RefCount* p = count;
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

inline Buffer::~Buffer()
{
    void* d = data;
    if (d)
        sub_6a067a(d);
    data = 0;
    size = 0;
    capacity = 0;
    void* a = allocation;
    sub_6a067a(a);
}

S::~S()
{
    sub_4944b0(0);
}
