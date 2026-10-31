// from server: 94% by EspClaude
// from server: 100% by tester
// roc 2008-06 005ff600  unit: RBX::Mouse  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ff600
//
// 005ff600  6aff                 push -1
// 005ff602  683b467d00           push 0x7d463b
// 005ff607  64a100000000         mov eax, dword ptr fs:[0]
// 005ff60d  50                   push eax
// 005ff60e  64892500000000       mov dword ptr fs:[0], esp
// 005ff615  83ec08               sub esp, 8
// 005ff618  c7042400000000       mov dword ptr [esp], 0
// 005ff61f  6868010000           push 0x168
// 005ff624  c644240400           mov byte ptr [esp + 4], 0
// 005ff629  ff15b0288000         call dword ptr [0x8028b0]
// 005ff62f  83c404               add esp, 4
// 005ff632  89442404             mov dword ptr [esp + 4], eax
// 005ff636  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005ff63e  85c0                 test eax, eax
// 005ff640  7409                 je 0x5ff64b
// 005ff642  8bc8                 mov ecx, eax
// 005ff644  e867fdffff           call 0x5ff3b0
// 005ff649  eb02                 jmp 0x5ff64d
// 005ff64b  33c0                 xor eax, eax
// 005ff64d  8b0c24               mov ecx, dword ptr [esp]
// 005ff650  56                   push esi
// 005ff651  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005ff655  51                   push ecx
// 005ff656  50                   push eax
// 005ff657  8bce                 mov ecx, esi
// 005ff659  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 005ff661  e8aae7ffff           call 0x5fde10
// 005ff666  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005ff66a  8bc6                 mov eax, esi
// 005ff66c  5e                   pop esi
// 005ff66d  64890d00000000       mov dword ptr fs:[0], ecx
// 005ff674  83c414               add esp, 0x14
// 005ff677  c3                   ret 

extern "C" {
    extern void* (__cdecl *allocate)(unsigned int);
}

inline void* __cdecl operator new(unsigned int size)
{
    return allocate(size);
}

void __cdecl operator delete(void*);

struct Product {
    unsigned char storage[0x168];
    Product();
};

struct Deleter {
    union {
        unsigned int value;
        unsigned char unused;
    };
};

struct Result {
    Result(Product*, Deleter);
};

Result __cdecl create()
{
    Deleter deleter = { 0 };
    *(volatile unsigned char*)&deleter.unused = 0;
    return Result(new Product, deleter);
}
