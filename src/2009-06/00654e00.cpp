// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c7530  unit: RBX::VDropperTool::?$TToolVerb  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c7530
//
// 005c7530  6aff                 push -1
// 005c7532  683bf47b00           push 0x7bf43b
// 005c7537  64a100000000         mov eax, dword ptr fs:[0]
// 005c753d  50                   push eax
// 005c753e  64892500000000       mov dword ptr fs:[0], esp
// 005c7545  51                   push ecx
// 005c7546  56                   push esi
// 005c7547  57                   push edi
// 005c7548  6a24                 push 0x24
// 005c754a  8bf9                 mov edi, ecx
// 005c754c  e8cf930d00           call 0x6a0920
// 005c7551  8bf0                 mov esi, eax
// 005c7553  83c404               add esp, 4
// 005c7556  89742408             mov dword ptr [esp + 8], esi
// 005c755a  33c0                 xor eax, eax
// 005c755c  89442414             mov dword ptr [esp + 0x14], eax
// 005c7560  3bf0                 cmp esi, eax
// 005c7562  7420                 je 0x5c7584
// 005c7564  8b470c               mov eax, dword ptr [edi + 0xc]
// 005c7567  8b8804020000         mov ecx, dword ptr [eax + 0x204]
// 005c756d  51                   push ecx
// 005c756e  8bce                 mov ecx, esi
// 005c7570  e81beefeff           call 0x5b6390
// 005c7575  c706f4988300         mov dword ptr [esi], 0x8398f4
// 005c757b  c74604d8988300       mov dword ptr [esi + 4], 0x8398d8
// 005c7582  8bc6                 mov eax, esi
// 005c7584  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c7588  5f                   pop edi
// 005c7589  5e                   pop esi
// 005c758a  64890d00000000       mov dword ptr fs:[0], ecx
// 005c7591  83c410               add esp, 0x10
// 005c7594  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern char table1[];
extern char table2[];

struct Base {
    void* primary;
    void* secondary;
    char pad[0x1c];
    Base(void*);
};

struct Tool : Base {
    Tool(void* p) : Base(p) {
        primary = table1;
        secondary = table2;
    }
};

struct Context {
    char pad[0x204];
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
