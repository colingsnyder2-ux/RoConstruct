// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c7750  unit: RBX::VGrabTool::?$TToolVerb  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c7750
//
// 005c7750  6aff                 push -1
// 005c7752  683bf47b00           push 0x7bf43b
// 005c7757  64a100000000         mov eax, dword ptr fs:[0]
// 005c775d  50                   push eax
// 005c775e  64892500000000       mov dword ptr fs:[0], esp
// 005c7765  51                   push ecx
// 005c7766  56                   push esi
// 005c7767  6a38                 push 0x38
// 005c7769  8bf1                 mov esi, ecx
// 005c776b  e8b0910d00           call 0x6a0920
// 005c7770  83c404               add esp, 4
// 005c7773  89442404             mov dword ptr [esp + 4], eax
// 005c7777  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005c777f  85c0                 test eax, eax
// 005c7781  7421                 je 0x5c77a4
// 005c7783  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005c7786  8b8904020000         mov ecx, dword ptr [ecx + 0x204]
// 005c778c  51                   push ecx
// 005c778d  8bc8                 mov ecx, eax
// 005c778f  e80c840700           call 0x63fba0
// 005c7794  5e                   pop esi
// 005c7795  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005c7799  64890d00000000       mov dword ptr fs:[0], ecx
// 005c77a0  83c410               add esp, 0x10
// 005c77a3  c3                   ret 
// 005c77a4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c77a8  33c0                 xor eax, eax
// 005c77aa  5e                   pop esi
// 005c77ab  64890d00000000       mov dword ptr fs:[0], ecx
// 005c77b2  83c410               add esp, 0x10
// 005c77b5  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Tool {
    char data[0x38];
    Tool(void*);
};

struct Context {
    char pad[0x204];
    void* value;
    __forceinline void* get();
};

__forceinline void* Context::get() {
    return value;
}

struct S {
    char pad[0x0c];
    Context* context;
    Tool* f();
};

Tool* S::f() {
    return new Tool(context->get());
}
