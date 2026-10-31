// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c65e0  unit: RBX::FlatTool  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c65e0
//
// 005c65e0  6aff                 push -1
// 005c65e2  683bf47b00           push 0x7bf43b
// 005c65e7  64a100000000         mov eax, dword ptr fs:[0]
// 005c65ed  50                   push eax
// 005c65ee  64892500000000       mov dword ptr fs:[0], esp
// 005c65f5  51                   push ecx
// 005c65f6  56                   push esi
// 005c65f7  57                   push edi
// 005c65f8  6a48                 push 0x48
// 005c65fa  8bf9                 mov edi, ecx
// 005c65fc  e81fa30d00           call 0x6a0920
// 005c6601  8bf0                 mov esi, eax
// 005c6603  83c404               add esp, 4
// 005c6606  89742408             mov dword ptr [esp + 8], esi
// 005c660a  33c0                 xor eax, eax
// 005c660c  89442414             mov dword ptr [esp + 0x14], eax
// 005c6610  3bf0                 cmp esi, eax
// 005c6612  741a                 je 0x5c662e
// 005c6614  8b4718               mov eax, dword ptr [edi + 0x18]
// 005c6617  50                   push eax
// 005c6618  8bce                 mov ecx, esi
// 005c661a  e8c1370500           call 0x619de0
// 005c661f  c706bc918300         mov dword ptr [esi], 0x8391bc
// 005c6625  c74604a0918300       mov dword ptr [esi + 4], 0x8391a0
// 005c662c  8bc6                 mov eax, esi
// 005c662e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c6632  5f                   pop edi
// 005c6633  5e                   pop esi
// 005c6634  64890d00000000       mov dword ptr fs:[0], ecx
// 005c663b  83c410               add esp, 0x10
// 005c663e  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base {
    unsigned int words[18];
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
