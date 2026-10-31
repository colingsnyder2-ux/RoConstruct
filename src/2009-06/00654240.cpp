// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c69f0  unit: RBX::StudsTool  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c69f0
//
// 005c69f0  6aff                 push -1
// 005c69f2  683bf47b00           push 0x7bf43b
// 005c69f7  64a100000000         mov eax, dword ptr fs:[0]
// 005c69fd  50                   push eax
// 005c69fe  64892500000000       mov dword ptr fs:[0], esp
// 005c6a05  51                   push ecx
// 005c6a06  56                   push esi
// 005c6a07  57                   push edi
// 005c6a08  6a48                 push 0x48
// 005c6a0a  8bf9                 mov edi, ecx
// 005c6a0c  e80f9f0d00           call 0x6a0920
// 005c6a11  8bf0                 mov esi, eax
// 005c6a13  83c404               add esp, 4
// 005c6a16  89742408             mov dword ptr [esp + 8], esi
// 005c6a1a  33c0                 xor eax, eax
// 005c6a1c  89442414             mov dword ptr [esp + 0x14], eax
// 005c6a20  3bf0                 cmp esi, eax
// 005c6a22  741a                 je 0x5c6a3e
// 005c6a24  8b4718               mov eax, dword ptr [edi + 0x18]
// 005c6a27  50                   push eax
// 005c6a28  8bce                 mov ecx, esi
// 005c6a2a  e8b1330500           call 0x619de0
// 005c6a2f  c70654938300         mov dword ptr [esi], 0x839354
// 005c6a35  c746043c938300       mov dword ptr [esi + 4], 0x83933c
// 005c6a3c  8bc6                 mov eax, esi
// 005c6a3e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c6a42  5f                   pop edi
// 005c6a43  5e                   pop esi
// 005c6a44  64890d00000000       mov dword ptr fs:[0], ecx
// 005c6a4b  83c410               add esp, 0x10
// 005c6a4e  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern char table_00839354[];
extern char table_0083933c[];

struct Cursor
{
    void* table;
    void* secondaryTable;
    char storage[0x40];

    void func_00619de0(void* object);
    Cursor(void* object);
};

__forceinline Cursor::Cursor(void* object)
{
    func_00619de0(object);
    table = table_00839354;
    secondaryTable = table_0083933c;
}

struct S
{
    char padding[0x18];
    void* object;

    Cursor* func_005c69f0();
};

Cursor* S::func_005c69f0()
{
    return new Cursor(object);
}
