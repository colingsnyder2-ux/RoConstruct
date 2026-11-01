// from server: 87% by EspClaude
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
    char padding[0x134];
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
