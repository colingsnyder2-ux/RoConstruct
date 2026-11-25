// from server: 100% by Xemicl
// from server: 100% by EspClaude
// roc 2009-06 00654830  unit: RBX::VLeftMotorTool::?$TToolVerb  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00654830
//
// 00654830  6aff                 push -1
// 00654832  687b9c8600           push 0x869c7b
// 00654837  64a100000000         mov eax, dword ptr fs:[0]
// 0065483d  50                   push eax
// 0065483e  64892500000000       mov dword ptr fs:[0], esp
// 00654845  51                   push ecx
// 00654846  56                   push esi
// 00654847  57                   push edi
// 00654848  6a48                 push 0x48
// 0065484a  8bf9                 mov edi, ecx
// 0065484c  e8e7410c00           call 0x718a38
// 00654851  8bf0                 mov esi, eax
// 00654853  83c404               add esp, 4
// 00654856  89742408             mov dword ptr [esp + 8], esi
// 0065485a  33c0                 xor eax, eax
// 0065485c  89442414             mov dword ptr [esp + 0x14], eax
// 00654860  3bf0                 cmp esi, eax
// 00654862  7420                 je 0x654884
// 00654864  8b470c               mov eax, dword ptr [edi + 0xc]
// 00654867  8b880c020000         mov ecx, dword ptr [eax + 0x20c]
// 0065486d  51                   push ecx
// 0065486e  8bce                 mov ecx, esi
// 00654870  e8ab3b0600           call 0x6b8420
// 00654875  c706cc038e00         mov dword ptr [esi], 0x8e03cc
// 0065487b  c74604b0038e00       mov dword ptr [esi + 4], 0x8e03b0
// 00654882  8bc6                 mov eax, esi
// 00654884  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00654888  5f                   pop edi
// 00654889  5e                   pop esi
// 0065488a  64890d00000000       mov dword ptr fs:[0], ecx
// 00654891  83c410               add esp, 0x10
// 00654894  c3                   ret 



void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern char table1[];
extern char table2[];

struct Base {
    void* primary;
    void* secondary;
    char pad[0x6c];
    Base(void*);
};

struct Tool : Base {
    Tool(void* p) : Base(p) {
        primary = table1;
        secondary = table2;
    }
};

struct Context {
    char pad[0x20c];
    void* value;
};

struct Verb {
    char pad[0x0c];
    Context* context;
    Tool* f();
};

Tool* Verb::f() {
    return new Tool(context->value);
}
