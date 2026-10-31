// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c6730  unit: RBX::GlueTool  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c6730
//
// 005c6730  6aff                 push -1
// 005c6732  683bf47b00           push 0x7bf43b
// 005c6737  64a100000000         mov eax, dword ptr fs:[0]
// 005c673d  50                   push eax
// 005c673e  64892500000000       mov dword ptr fs:[0], esp
// 005c6745  51                   push ecx
// 005c6746  56                   push esi
// 005c6747  57                   push edi
// 005c6748  6a48                 push 0x48
// 005c674a  8bf9                 mov edi, ecx
// 005c674c  e8cfa10d00           call 0x6a0920
// 005c6751  8bf0                 mov esi, eax
// 005c6753  83c404               add esp, 4
// 005c6756  89742408             mov dword ptr [esp + 8], esi
// 005c675a  33c0                 xor eax, eax
// 005c675c  89442414             mov dword ptr [esp + 0x14], eax
// 005c6760  3bf0                 cmp esi, eax
// 005c6762  741a                 je 0x5c677e
// 005c6764  8b4718               mov eax, dword ptr [edi + 0x18]
// 005c6767  50                   push eax
// 005c6768  8bce                 mov ecx, esi
// 005c676a  e871360500           call 0x619de0
// 005c676f  c70644928300         mov dword ptr [esi], 0x839244
// 005c6775  c746042c928300       mov dword ptr [esi + 4], 0x83922c
// 005c677c  8bc6                 mov eax, esi
// 005c677e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c6782  5f                   pop edi
// 005c6783  5e                   pop esi
// 005c6784  64890d00000000       mov dword ptr fs:[0], ecx
// 005c678b  83c410               add esp, 0x10
// 005c678e  c3                   ret 

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Primary {
    virtual void first();
};

struct Secondary {
    virtual void second();
};

struct CursorBase : Primary, Secondary {
    char reserved[64];
    CursorBase(void*);
};

struct Cursor : CursorBase {
    Cursor(void*);
    virtual void first();
    virtual void second();
};

inline Cursor::Cursor(void* context) : CursorBase(context)
{
}

struct Tool {
    char reserved[24];
    void* context;
    Cursor* createCursor();
};

Cursor* Tool::createCursor()
{
    return new Cursor(context);
}
