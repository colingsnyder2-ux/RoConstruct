// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c72f0  unit: RBX::VLockTool::?$TToolVerb  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c72f0
//
// 005c72f0  6aff                 push -1
// 005c72f2  683bf47b00           push 0x7bf43b
// 005c72f7  64a100000000         mov eax, dword ptr fs:[0]
// 005c72fd  50                   push eax
// 005c72fe  64892500000000       mov dword ptr fs:[0], esp
// 005c7305  51                   push ecx
// 005c7306  56                   push esi
// 005c7307  57                   push edi
// 005c7308  6a24                 push 0x24
// 005c730a  8bf9                 mov edi, ecx
// 005c730c  e80f960d00           call 0x6a0920
// 005c7311  8bf0                 mov esi, eax
// 005c7313  83c404               add esp, 4
// 005c7316  89742408             mov dword ptr [esp + 8], esi
// 005c731a  33c0                 xor eax, eax
// 005c731c  89442414             mov dword ptr [esp + 0x14], eax
// 005c7320  3bf0                 cmp esi, eax
// 005c7322  7420                 je 0x5c7344
// 005c7324  8b470c               mov eax, dword ptr [edi + 0xc]
// 005c7327  8b8804020000         mov ecx, dword ptr [eax + 0x204]
// 005c732d  51                   push ecx
// 005c732e  8bce                 mov ecx, esi
// 005c7330  e84b6b0700           call 0x63de80
// 005c7335  c706f4978300         mov dword ptr [esi], 0x8397f4
// 005c733b  c74604dc978300       mov dword ptr [esi + 4], 0x8397dc
// 005c7342  8bc6                 mov eax, esi
// 005c7344  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c7348  5f                   pop edi
// 005c7349  5e                   pop esi
// 005c734a  64890d00000000       mov dword ptr fs:[0], ecx
// 005c7351  83c410               add esp, 0x10
// 005c7354  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern char vtA[];
extern char vtB[];

struct Base {
    void* table1;
    void* table2;
    char padding[0x1c];
    Base(void*);
};

struct Tool : Base {
    Tool(void*);
};

__forceinline Tool::Tool(void* p) : Base(p) {
    table1 = vtA;
    table2 = vtB;
}

struct Context {
    char padding[0x20c];
    void* value;
};

struct Obj {
    char padding[0xc];
    Context* context;
    Tool* f();
};

Tool* Obj::f() {
    return new Tool(context->value);
}
