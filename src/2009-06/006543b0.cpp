// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c6b40  unit: RBX::InletTool  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c6b40
//
// 005c6b40  6aff                 push -1
// 005c6b42  683bf47b00           push 0x7bf43b
// 005c6b47  64a100000000         mov eax, dword ptr fs:[0]
// 005c6b4d  50                   push eax
// 005c6b4e  64892500000000       mov dword ptr fs:[0], esp
// 005c6b55  51                   push ecx
// 005c6b56  56                   push esi
// 005c6b57  57                   push edi
// 005c6b58  6a48                 push 0x48
// 005c6b5a  8bf9                 mov edi, ecx
// 005c6b5c  e8bf9d0d00           call 0x6a0920
// 005c6b61  8bf0                 mov esi, eax
// 005c6b63  83c404               add esp, 4
// 005c6b66  89742408             mov dword ptr [esp + 8], esi
// 005c6b6a  33c0                 xor eax, eax
// 005c6b6c  89442414             mov dword ptr [esp + 0x14], eax
// 005c6b70  3bf0                 cmp esi, eax
// 005c6b72  741a                 je 0x5c6b8e
// 005c6b74  8b4718               mov eax, dword ptr [edi + 0x18]
// 005c6b77  50                   push eax
// 005c6b78  8bce                 mov ecx, esi
// 005c6b7a  e861320500           call 0x619de0
// 005c6b7f  c706dc938300         mov dword ptr [esi], 0x8393dc
// 005c6b85  c74604c4938300       mov dword ptr [esi + 4], 0x8393c4
// 005c6b8c  8bc6                 mov eax, esi
// 005c6b8e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c6b92  5f                   pop edi
// 005c6b93  5e                   pop esi
// 005c6b94  64890d00000000       mov dword ptr fs:[0], ecx
// 005c6b9b  83c410               add esp, 0x10
// 005c6b9e  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct CursorBase : Primary, Secondary {
    unsigned char storage[64];
    CursorBase(void*);
};

struct InletCursor : CursorBase {
    InletCursor(void*);
    virtual ~InletCursor();
};

__forceinline InletCursor::InletCursor(void* context)
    : CursorBase(context)
{
}

struct InletTool {
    unsigned char storage[24];
    void* context;
    InletCursor* createCursor();
};

InletCursor* InletTool::createCursor()
{
    return new InletCursor(context);
}
