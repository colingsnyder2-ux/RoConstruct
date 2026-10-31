// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c6270  unit: RBX::VArrowTool::?$TToolVerb  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c6270
//
// 005c6270  6aff                 push -1
// 005c6272  683bf47b00           push 0x7bf43b
// 005c6277  64a100000000         mov eax, dword ptr fs:[0]
// 005c627d  50                   push eax
// 005c627e  64892500000000       mov dword ptr fs:[0], esp
// 005c6285  51                   push ecx
// 005c6286  56                   push esi
// 005c6287  57                   push edi
// 005c6288  6a20                 push 0x20
// 005c628a  8bf9                 mov edi, ecx
// 005c628c  e88fa60d00           call 0x6a0920
// 005c6291  8bf0                 mov esi, eax
// 005c6293  83c404               add esp, 4
// 005c6296  89742408             mov dword ptr [esp + 8], esi
// 005c629a  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005c62a2  85f6                 test esi, esi
// 005c62a4  7435                 je 0x5c62db
// 005c62a6  8b470c               mov eax, dword ptr [edi + 0xc]
// 005c62a9  8b8804020000         mov ecx, dword ptr [eax + 0x204]
// 005c62af  51                   push ecx
// 005c62b0  8bce                 mov ecx, esi
// 005c62b2  e839f70400           call 0x6159f0
// 005c62b7  5f                   pop edi
// 005c62b8  c6461c00             mov byte ptr [esi + 0x1c], 0
// 005c62bc  c706a4368300         mov dword ptr [esi], 0x8336a4
// 005c62c2  c7460488368300       mov dword ptr [esi + 4], 0x833688
// 005c62c9  8bc6                 mov eax, esi
// 005c62cb  5e                   pop esi
// 005c62cc  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005c62d0  64890d00000000       mov dword ptr fs:[0], ecx
// 005c62d7  83c410               add esp, 0x10
// 005c62da  c3                   ret 
// 005c62db  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c62df  5f                   pop edi
// 005c62e0  33c0                 xor eax, eax
// 005c62e2  5e                   pop esi
// 005c62e3  64890d00000000       mov dword ptr fs:[0], ecx
// 005c62ea  83c410               add esp, 0x10
// 005c62ed  c3                   ret 

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct S_func_006159f0 {
    char data[28];
    int f(int a1);
};

struct Tool : S_func_006159f0 {
    char flag;
    char padding[3];
    Tool(int a1);
};

inline Tool::Tool(int a1)
{
    f(a1);
    flag = 0;
    *(int*)((char*)this + 0) = 0x8336a4;
    *(int*)((char*)this + 4) = 0x833688;
}

struct S {
    char padding[12];
    char* owner;
    Tool* f();
};

Tool* S::f()
{
    return new Tool(*(int*)(owner + 0x204));
}
