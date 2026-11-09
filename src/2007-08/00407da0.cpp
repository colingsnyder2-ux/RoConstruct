// from server: 100% by Yeetserama
// roc 2007-08 00407da0  unit: RBX::VSelection::?$FactoryProduct::Creator  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00407da0
//
// 00407da0  6aff                 push -1
// 00407da2  682ba57400           push 0x74a52b
// 00407da7  64a100000000         mov eax, dword ptr fs:[0]
// 00407dad  50                   push eax
// 00407dae  83ec08               sub esp, 8
// 00407db1  56                   push esi
// 00407db2  a188518b00           mov eax, dword ptr [0x8b5188]
// 00407db7  33c4                 xor eax, esp
// 00407db9  50                   push eax
// 00407dba  8d442410             lea eax, [esp + 0x10]
// 00407dbe  64a300000000         mov dword ptr fs:[0], eax
// 00407dc4  c744240800000000     mov dword ptr [esp + 8], 0
// 00407dcc  6858010000           push 0x158
// 00407dd1  c644240c00           mov byte ptr [esp + 0xc], 0
// 00407dd6  ff15d0e67700         call dword ptr [0x77e6d0]
// 00407ddc  83c404               add esp, 4
// 00407ddf  8944240c             mov dword ptr [esp + 0xc], eax
// 00407de3  85c0                 test eax, eax
// 00407de5  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00407ded  7409                 je 0x407df8
// 00407def  8bc8                 mov ecx, eax
// 00407df1  e84a341300           call 0x53b240
// 00407df6  eb02                 jmp 0x407dfa
// 00407df8  33c0                 xor eax, eax
// 00407dfa  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00407dfe  8b742420             mov esi, dword ptr [esp + 0x20]
// 00407e02  51                   push ecx
// 00407e03  50                   push eax
// 00407e04  8bce                 mov ecx, esi
// 00407e06  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00407e0e  e8ddfeffff           call 0x407cf0
// 00407e13  8bc6                 mov eax, esi
// 00407e15  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00407e19  64890d00000000       mov dword ptr fs:[0], ecx
// 00407e20  59                   pop ecx
// 00407e21  5e                   pop esi
// 00407e22  83c414               add esp, 0x14
// 00407e25  c3                   ret 
// copied from an identical function in another client (function ?create@@YA?AUResult@@XZ)

// from server: 100% by tester
extern "C" {
    extern void* (__cdecl *allocate)(unsigned int);
}

inline void* __cdecl operator new(unsigned int size)
{
    return allocate(size);
}

void __cdecl operator delete(void*);

struct Product {
    unsigned char storage[0x158];
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