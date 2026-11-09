// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c68a0  unit: RBX::WeldTool  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c68a0
//
// 005c68a0  6aff                 push -1
// 005c68a2  683bf47b00           push 0x7bf43b
// 005c68a7  64a100000000         mov eax, dword ptr fs:[0]
// 005c68ad  50                   push eax
// 005c68ae  64892500000000       mov dword ptr fs:[0], esp
// 005c68b5  51                   push ecx
// 005c68b6  56                   push esi
// 005c68b7  57                   push edi
// 005c68b8  6a48                 push 0x48
// 005c68ba  8bf9                 mov edi, ecx
// 005c68bc  e85fa00d00           call 0x6a0920
// 005c68c1  8bf0                 mov esi, eax
// 005c68c3  83c404               add esp, 4
// 005c68c6  89742408             mov dword ptr [esp + 8], esi
// 005c68ca  33c0                 xor eax, eax
// 005c68cc  89442414             mov dword ptr [esp + 0x14], eax
// 005c68d0  3bf0                 cmp esi, eax
// 005c68d2  741a                 je 0x5c68ee
// 005c68d4  8b4718               mov eax, dword ptr [edi + 0x18]
// 005c68d7  50                   push eax
// 005c68d8  8bce                 mov ecx, esi
// 005c68da  e801350500           call 0x619de0
// 005c68df  c706cc928300         mov dword ptr [esi], 0x8392cc
// 005c68e5  c74604b4928300       mov dword ptr [esi + 4], 0x8392b4
// 005c68ec  8bc6                 mov eax, esi
// 005c68ee  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c68f2  5f                   pop edi
// 005c68f3  5e                   pop esi
// 005c68f4  64890d00000000       mov dword ptr fs:[0], ecx
// 005c68fb  83c410               add esp, 0x10
// 005c68fe  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct CursorBase : Primary, Secondary {
    char storage[64];
    CursorBase(void*);
};

struct Cursor : CursorBase {
    Cursor(void*);
    virtual ~Cursor();
};

inline Cursor::Cursor(void* value) : CursorBase(value) {}

struct WeldTool {
    char storage[24];
    void* context;
    Cursor* createCursor();
};

Cursor* WeldTool::createCursor()
{
    return new Cursor(context);
}
