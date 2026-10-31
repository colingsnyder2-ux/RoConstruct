// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c7a80  unit: RBX::SlingshotTool  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c7a80
//
// 005c7a80  6aff                 push -1
// 005c7a82  683bf47b00           push 0x7bf43b
// 005c7a87  64a100000000         mov eax, dword ptr fs:[0]
// 005c7a8d  50                   push eax
// 005c7a8e  64892500000000       mov dword ptr fs:[0], esp
// 005c7a95  51                   push ecx
// 005c7a96  56                   push esi
// 005c7a97  57                   push edi
// 005c7a98  6a30                 push 0x30
// 005c7a9a  8bf9                 mov edi, ecx
// 005c7a9c  e87f8e0d00           call 0x6a0920
// 005c7aa1  8bf0                 mov esi, eax
// 005c7aa3  83c404               add esp, 4
// 005c7aa6  89742408             mov dword ptr [esp + 8], esi
// 005c7aaa  33c0                 xor eax, eax
// 005c7aac  89442414             mov dword ptr [esp + 0x14], eax
// 005c7ab0  3bf0                 cmp esi, eax
// 005c7ab2  741e                 je 0x5c7ad2
// 005c7ab4  8b4718               mov eax, dword ptr [edi + 0x18]
// 005c7ab7  6a05                 push 5
// 005c7ab9  6a01                 push 1
// 005c7abb  50                   push eax
// 005c7abc  8bce                 mov ecx, esi
// 005c7abe  e88d6d0700           call 0x63e850
// 005c7ac3  c706649a8300         mov dword ptr [esi], 0x839a64
// 005c7ac9  c746044c9a8300       mov dword ptr [esi + 4], 0x839a4c
// 005c7ad0  8bc6                 mov eax, esi
// 005c7ad2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c7ad6  5f                   pop edi
// 005c7ad7  5e                   pop esi
// 005c7ad8  64890d00000000       mov dword ptr fs:[0], ecx
// 005c7adf  83c410               add esp, 0x10
// 005c7ae2  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Primary {
    virtual void first();
};

struct Secondary {
    virtual void second();
};

struct Base : Primary, Secondary {
    char storage[40];
    Base(int, int, int);
};

struct Product : Base {
    Product(int);
    virtual void first();
    virtual void second();
};

inline Product::Product(int value) : Base(value, 1, 5) {
}

struct SlingshotTool {
    char padding[0x18];
    int value;
    Product* func();
};

Product* SlingshotTool::func() {
    return new Product(value);
}
