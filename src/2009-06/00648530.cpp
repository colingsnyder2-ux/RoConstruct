// from server: 100% by EspClaude
// from server: 87% by EspClaude
// roc 2009-06 00648530  unit: RBX::VStockSound::?$FactoryProduct  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00648530
//
// 00648530  56                   push esi
// 00648531  8bf1                 mov esi, ecx
// 00648533  8b8694000000         mov eax, dword ptr [esi + 0x94]
// 00648539  85c0                 test eax, eax
// 0064853b  741b                 je 0x648558
// 0064853d  6a00                 push 0
// 0064853f  50                   push eax
// 00648540  e805f90c00           call 0x717e4a
// 00648545  50                   push eax
// 00648546  e865efffff           call 0x6474b0
// 0064854b  83c404               add esp, 4
// 0064854e  c7869400000000000000 mov dword ptr [esi + 0x94], 0
// 00648558  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 0064855e  8d8e8c000000         lea ecx, [esi + 0x8c]
// 00648564  5e                   pop esi
// 00648565  85c0                 test eax, eax
// 00648567  7408                 je 0x648571
// 00648569  ff4808               dec dword ptr [eax + 8]
// 0064856c  e92feae1ff           jmp 0x466fa0
// 00648571  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 005b97f0  unit: VStockSound::?$FactoryProduct  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b97f0
//
// 005b97f0  56                   push esi
// 005b97f1  8bf1                 mov esi, ecx
// 005b97f3  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 005b97f9  85c0                 test eax, eax
// 005b97fb  741b                 je 0x5b9818
// 005b97fd  6a00                 push 0
// 005b97ff  50                   push eax
// 005b9800  e8ef630e00           call 0x69fbf4
// 005b9805  50                   push eax
// 005b9806  e895efffff           call 0x5b87a0
// 005b980b  83c404               add esp, 4
// 005b980e  c7863c01000000000000 mov dword ptr [esi + 0x13c], 0
// 005b9818  8b8634010000         mov eax, dword ptr [esi + 0x134]
// 005b981e  8d8e34010000         lea ecx, [esi + 0x134]
// 005b9824  5e                   pop esi
// 005b9825  85c0                 test eax, eax
// 005b9827  7408                 je 0x5b9831
// 005b9829  ff4808               dec dword ptr [eax + 8]
// 005b982c  e94fd6e9ff           jmp 0x456e80
// 005b9831  c3                   ret 

extern "C" void* __stdcall convert(void*, int);
extern "C" void __cdecl dispose(void*);

struct Node {
    char padding[8];
    int count;
};

struct Reference {
    Node* pointer;
    void release();
};

struct S {
    char padding[0x8c];
    Reference reference;
    char gap[4];
    void* resource;

    void f();
};

void S::f()
{
    if (resource) {
        dispose(convert(resource, 0));
        resource = 0;
    }

    if (reference.pointer) {
        --reference.pointer->count;
        reference.release();
    }
}
