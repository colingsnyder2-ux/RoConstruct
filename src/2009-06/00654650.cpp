// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c6c90  unit: RBX::HingeTool  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c6c90
//
// 005c6c90  6aff                 push -1
// 005c6c92  683bf47b00           push 0x7bf43b
// 005c6c97  64a100000000         mov eax, dword ptr fs:[0]
// 005c6c9d  50                   push eax
// 005c6c9e  64892500000000       mov dword ptr fs:[0], esp
// 005c6ca5  51                   push ecx
// 005c6ca6  56                   push esi
// 005c6ca7  57                   push edi
// 005c6ca8  6a48                 push 0x48
// 005c6caa  8bf9                 mov edi, ecx
// 005c6cac  e86f9c0d00           call 0x6a0920
// 005c6cb1  8bf0                 mov esi, eax
// 005c6cb3  83c404               add esp, 4
// 005c6cb6  89742408             mov dword ptr [esp + 8], esi
// 005c6cba  33c0                 xor eax, eax
// 005c6cbc  89442414             mov dword ptr [esp + 0x14], eax
// 005c6cc0  3bf0                 cmp esi, eax
// 005c6cc2  741a                 je 0x5c6cde
// 005c6cc4  8b4718               mov eax, dword ptr [edi + 0x18]
// 005c6cc7  50                   push eax
// 005c6cc8  8bce                 mov ecx, esi
// 005c6cca  e811310500           call 0x619de0
// 005c6ccf  c70664948300         mov dword ptr [esi], 0x839464
// 005c6cd5  c746044c948300       mov dword ptr [esi + 4], 0x83944c
// 005c6cdc  8bc6                 mov eax, esi
// 005c6cde  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c6ce2  5f                   pop edi
// 005c6ce3  5e                   pop esi
// 005c6ce4  64890d00000000       mov dword ptr fs:[0], ecx
// 005c6ceb  83c410               add esp, 0x10
// 005c6cee  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base {
    unsigned int table1;
    unsigned int table2;
    char storage[64];
    Base(void*);
};

struct Object : Base {
    Object(void*);
};

inline Object::Object(void* p) : Base(p) {
    table1 = 0x839464;
    table2 = 0x83944c;
}

struct S {
    char padding[24];
    void* context;
    Object* f();
};

Object* S::f() {
    return new Object(context);
}
