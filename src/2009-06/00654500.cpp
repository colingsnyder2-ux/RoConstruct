// from server: 100% by EspClaude
// roc 2009-06 00654500  unit: RBX::UniversalTool  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00654500
//
// 00654500  6aff                 push -1
// 00654502  687b9c8600           push 0x869c7b
// 00654507  64a100000000         mov eax, dword ptr fs:[0]
// 0065450d  50                   push eax
// 0065450e  64892500000000       mov dword ptr fs:[0], esp
// 00654515  51                   push ecx
// 00654516  56                   push esi
// 00654517  57                   push edi
// 00654518  6a48                 push 0x48
// 0065451a  8bf9                 mov edi, ecx
// 0065451c  e817450c00           call 0x718a38
// 00654521  8bf0                 mov esi, eax
// 00654523  83c404               add esp, 4
// 00654526  89742408             mov dword ptr [esp + 8], esi
// 0065452a  33c0                 xor eax, eax
// 0065452c  89442414             mov dword ptr [esp + 0x14], eax
// 00654530  3bf0                 cmp esi, eax
// 00654532  741a                 je 0x65454e
// 00654534  8b4718               mov eax, dword ptr [edi + 0x18]
// 00654537  50                   push eax
// 00654538  8bce                 mov ecx, esi
// 0065453a  e8e13e0600           call 0x6b8420
// 0065453f  c7061c028e00         mov dword ptr [esi], 0x8e021c
// 00654545  c7460400028e00       mov dword ptr [esi + 4], 0x8e0200
// 0065454c  8bc6                 mov eax, esi
// 0065454e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00654552  5f                   pop edi
// 00654553  5e                   pop esi
// 00654554  64890d00000000       mov dword ptr fs:[0], ecx
// 0065455b  83c410               add esp, 0x10
// 0065455e  c3                   ret 
// copied from an identical function in another client (function ?createCursor@Tool@@QAEPAUCursor@@XZ)

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