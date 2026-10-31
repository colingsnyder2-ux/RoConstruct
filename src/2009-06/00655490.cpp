// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c7b10  unit: RBX::VSlingshotTool::?$TToolVerb  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c7b10
//
// 005c7b10  6aff                 push -1
// 005c7b12  683bf47b00           push 0x7bf43b
// 005c7b17  64a100000000         mov eax, dword ptr fs:[0]
// 005c7b1d  50                   push eax
// 005c7b1e  64892500000000       mov dword ptr fs:[0], esp
// 005c7b25  51                   push ecx
// 005c7b26  56                   push esi
// 005c7b27  57                   push edi
// 005c7b28  6a30                 push 0x30
// 005c7b2a  8bf9                 mov edi, ecx
// 005c7b2c  e8ef8d0d00           call 0x6a0920
// 005c7b31  8bf0                 mov esi, eax
// 005c7b33  83c404               add esp, 4
// 005c7b36  89742408             mov dword ptr [esp + 8], esi
// 005c7b3a  33c0                 xor eax, eax
// 005c7b3c  89442414             mov dword ptr [esp + 0x14], eax
// 005c7b40  3bf0                 cmp esi, eax
// 005c7b42  7424                 je 0x5c7b68
// 005c7b44  8b470c               mov eax, dword ptr [edi + 0xc]
// 005c7b47  8b8804020000         mov ecx, dword ptr [eax + 0x204]
// 005c7b4d  6a05                 push 5
// 005c7b4f  6a01                 push 1
// 005c7b51  51                   push ecx
// 005c7b52  8bce                 mov ecx, esi
// 005c7b54  e8f76c0700           call 0x63e850
// 005c7b59  c706649a8300         mov dword ptr [esi], 0x839a64
// 005c7b5f  c746044c9a8300       mov dword ptr [esi + 4], 0x839a4c
// 005c7b66  8bc6                 mov eax, esi
// 005c7b68  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c7b6c  5f                   pop edi
// 005c7b6d  5e                   pop esi
// 005c7b6e  64890d00000000       mov dword ptr fs:[0], ecx
// 005c7b75  83c410               add esp, 0x10
// 005c7b78  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct First {
    virtual void first();
};

struct Second {
    virtual void second();
};

struct Base : First, Second {
    char storage[0x28];
    Base(void*, int, int);
};

struct Tool : Base {
    Tool(void* p);
    virtual void first();
    virtual void second();
};

inline Tool::Tool(void* p) : Base(p, 1, 5) {}

struct Context {
    char padding[0x204];
    void* value;
};

struct S {
    char padding[0x0c];
    Context* context;
    Tool* f();
};

Tool* S::f()
{
    return new Tool(context->value);
}
