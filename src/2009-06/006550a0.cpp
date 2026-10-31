// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c77f0  unit: RBX::VCloneTool::?$TToolVerb  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c77f0
//
// 005c77f0  6aff                 push -1
// 005c77f2  683bf47b00           push 0x7bf43b
// 005c77f7  64a100000000         mov eax, dword ptr fs:[0]
// 005c77fd  50                   push eax
// 005c77fe  64892500000000       mov dword ptr fs:[0], esp
// 005c7805  51                   push ecx
// 005c7806  56                   push esi
// 005c7807  6a24                 push 0x24
// 005c7809  8bf1                 mov esi, ecx
// 005c780b  e810910d00           call 0x6a0920
// 005c7810  83c404               add esp, 4
// 005c7813  89442404             mov dword ptr [esp + 4], eax
// 005c7817  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005c781f  85c0                 test eax, eax
// 005c7821  7421                 je 0x5c7844
// 005c7823  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005c7826  8b8904020000         mov ecx, dword ptr [ecx + 0x204]
// 005c782c  51                   push ecx
// 005c782d  8bc8                 mov ecx, eax
// 005c782f  e89c850700           call 0x63fdd0
// 005c7834  5e                   pop esi
// 005c7835  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005c7839  64890d00000000       mov dword ptr fs:[0], ecx
// 005c7840  83c410               add esp, 0x10
// 005c7843  c3                   ret 
// 005c7844  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c7848  33c0                 xor eax, eax
// 005c784a  5e                   pop esi
// 005c784b  64890d00000000       mov dword ptr fs:[0], ecx
// 005c7852  83c410               add esp, 0x10
// 005c7855  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Context {
    char pad[0x204];
    void* value;
    __forceinline void* get();
};

__forceinline void* Context::get() {
    return value;
}

struct Tool {
    char storage[0x24];
    Tool(void*);
};

struct Verb {
    char pad[0x0c];
    Context* context;
    Tool* create();
};

Tool* Verb::create() {
    return new Tool(context->get());
}
