// from server: 94% by EspClaude
// from server: 100% by tester
// roc 2008-06 0048ea00  unit: RBX::VHopperBin::?$FactoryProduct::Creator  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048ea00
//
// 0048ea00  6aff                 push -1
// 0048ea02  683b467d00           push 0x7d463b
// 0048ea07  64a100000000         mov eax, dword ptr fs:[0]
// 0048ea0d  50                   push eax
// 0048ea0e  64892500000000       mov dword ptr fs:[0], esp
// 0048ea15  83ec08               sub esp, 8
// 0048ea18  c7042400000000       mov dword ptr [esp], 0
// 0048ea1f  6868010000           push 0x168
// 0048ea24  c644240400           mov byte ptr [esp + 4], 0
// 0048ea29  ff15b0288000         call dword ptr [0x8028b0]
// 0048ea2f  83c404               add esp, 4
// 0048ea32  89442404             mov dword ptr [esp + 4], eax
// 0048ea36  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048ea3e  85c0                 test eax, eax
// 0048ea40  7409                 je 0x48ea4b
// 0048ea42  8bc8                 mov ecx, eax
// 0048ea44  e877251400           call 0x5d0fc0
// 0048ea49  eb02                 jmp 0x48ea4d
// 0048ea4b  33c0                 xor eax, eax
// 0048ea4d  8b0c24               mov ecx, dword ptr [esp]
// 0048ea50  56                   push esi
// 0048ea51  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0048ea55  51                   push ecx
// 0048ea56  50                   push eax
// 0048ea57  8bce                 mov ecx, esi
// 0048ea59  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0048ea61  e8eafeffff           call 0x48e950
// 0048ea66  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0048ea6a  8bc6                 mov eax, esi
// 0048ea6c  5e                   pop esi
// 0048ea6d  64890d00000000       mov dword ptr fs:[0], ecx
// 0048ea74  83c414               add esp, 0x14
// 0048ea77  c3                   ret 

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
