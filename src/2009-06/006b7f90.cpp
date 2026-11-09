// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00618200  unit: RBX::NullTool  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00618200
//
// 00618200  6aff                 push -1
// 00618202  683bf47b00           push 0x7bf43b
// 00618207  64a100000000         mov eax, dword ptr fs:[0]
// 0061820d  50                   push eax
// 0061820e  64892500000000       mov dword ptr fs:[0], esp
// 00618215  51                   push ecx
// 00618216  56                   push esi
// 00618217  57                   push edi
// 00618218  6a1c                 push 0x1c
// 0061821a  8bf9                 mov edi, ecx
// 0061821c  e8ff860800           call 0x6a0920
// 00618221  8bf0                 mov esi, eax
// 00618223  83c404               add esp, 4
// 00618226  89742408             mov dword ptr [esp + 8], esi
// 0061822a  33c0                 xor eax, eax
// 0061822c  89442414             mov dword ptr [esp + 0x14], eax
// 00618230  3bf0                 cmp esi, eax
// 00618232  741a                 je 0x61824e
// 00618234  8b4718               mov eax, dword ptr [edi + 0x18]
// 00618237  50                   push eax
// 00618238  8bce                 mov ecx, esi
// 0061823a  e8b1d7ffff           call 0x6159f0
// 0061823f  c706d43b8400         mov dword ptr [esi], 0x843bd4
// 00618245  c74604bc3b8400       mov dword ptr [esi + 4], 0x843bbc
// 0061824c  8bc6                 mov eax, esi
// 0061824e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00618252  5f                   pop edi
// 00618253  5e                   pop esi
// 00618254  64890d00000000       mov dword ptr fs:[0], ecx
// 0061825b  83c410               add esp, 0x10
// 0061825e  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base {
    unsigned int words[7];
    Base(int);
};

struct Cursor : Base {
    Cursor(int);
};

inline Cursor::Cursor(int value) : Base(value) {
    words[0] = 0x008391bc;
    words[1] = 0x008391a0;
}

struct S {
    char padding[24];
    int value;
    Cursor* f();
};

Cursor* S::f() {
    return new Cursor(value);
}
