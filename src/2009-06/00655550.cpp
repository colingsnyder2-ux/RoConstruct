// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c7bd0  unit: RBX::RocketTool  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c7bd0
//
// 005c7bd0  6aff                 push -1
// 005c7bd2  683bf47b00           push 0x7bf43b
// 005c7bd7  64a100000000         mov eax, dword ptr fs:[0]
// 005c7bdd  50                   push eax
// 005c7bde  64892500000000       mov dword ptr fs:[0], esp
// 005c7be5  51                   push ecx
// 005c7be6  56                   push esi
// 005c7be7  57                   push edi
// 005c7be8  6a30                 push 0x30
// 005c7bea  8bf9                 mov edi, ecx
// 005c7bec  e82f8d0d00           call 0x6a0920
// 005c7bf1  8bf0                 mov esi, eax
// 005c7bf3  83c404               add esp, 4
// 005c7bf6  89742408             mov dword ptr [esp + 8], esi
// 005c7bfa  33c0                 xor eax, eax
// 005c7bfc  89442414             mov dword ptr [esp + 0x14], eax
// 005c7c00  3bf0                 cmp esi, eax
// 005c7c02  741d                 je 0x5c7c21
// 005c7c04  6a5a                 push 0x5a
// 005c7c06  50                   push eax
// 005c7c07  8b4718               mov eax, dword ptr [edi + 0x18]
// 005c7c0a  50                   push eax
// 005c7c0b  8bce                 mov ecx, esi
// 005c7c0d  e83e6c0700           call 0x63e850
// 005c7c12  c706ec9a8300         mov dword ptr [esi], 0x839aec
// 005c7c18  c74604d09a8300       mov dword ptr [esi + 4], 0x839ad0
// 005c7c1f  8bc6                 mov eax, esi
// 005c7c21  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c7c25  5f                   pop edi
// 005c7c26  5e                   pop esi
// 005c7c27  64890d00000000       mov dword ptr fs:[0], ecx
// 005c7c2e  83c410               add esp, 0x10
// 005c7c31  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Primary {
    virtual void f();
};

struct Secondary {
    virtual void g();
};

struct Base : Primary, Secondary {
    char data[40];
    Base(void*, int, int);
};

struct Object : Base {
    Object(void*, int, int);
    virtual void f();
    virtual void g();
};

__forceinline Object::Object(void* owner, int value, int limit)
    : Base(owner, value, limit) {}

struct S {
    char padding[24];
    void* owner;
    Object* create();
};

Object* S::create()
{
    return new Object(owner, 0, 90);
}
