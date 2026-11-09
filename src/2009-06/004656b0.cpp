// from server: 100% by EspClaude
// roc 2009-06 004656b0  unit: CScriptDoc  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004656b0
//
// 004656b0  6aff                 push -1
// 004656b2  687aef8400           push 0x84ef7a
// 004656b7  64a100000000         mov eax, dword ptr fs:[0]
// 004656bd  50                   push eax
// 004656be  64892500000000       mov dword ptr fs:[0], esp
// 004656c5  51                   push ecx
// 004656c6  56                   push esi
// 004656c7  6a5c                 push 0x5c
// 004656c9  e86a332b00           call 0x718a38
// 004656ce  8bf0                 mov esi, eax
// 004656d0  83c404               add esp, 4
// 004656d3  89742404             mov dword ptr [esp + 4], esi
// 004656d7  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004656df  85f6                 test esi, esi
// 004656e1  742d                 je 0x465710
// 004656e3  8bce                 mov ecx, esi
// 004656e5  e848362b00           call 0x718d32
// 004656ea  c70684bc8b00         mov dword ptr [esi], 0x8bbc84
// 004656f0  c7465400000000       mov dword ptr [esi + 0x54], 0
// 004656f7  c7465800000000       mov dword ptr [esi + 0x58], 0
// 004656fe  8bc6                 mov eax, esi
// 00465700  5e                   pop esi
// 00465701  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00465705  64890d00000000       mov dword ptr fs:[0], ecx
// 0046570c  83c410               add esp, 0x10
// 0046570f  c3                   ret 
// 00465710  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00465714  33c0                 xor eax, eax
// 00465716  5e                   pop esi
// 00465717  64890d00000000       mov dword ptr fs:[0], ecx
// 0046571e  83c410               add esp, 0x10
// 00465721  c3                   ret 
// copied from an identical function in another client (function ?Create@CScriptDoc@@SAPAU1@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base {
    Base();
    virtual ~Base();
    char padding[0x50];
};

struct CScriptDoc : Base {
    virtual ~CScriptDoc();
    int field54;
    int field58;
    static CScriptDoc* Create();
};

CScriptDoc* CScriptDoc::Create()
{
    CScriptDoc* p = new CScriptDoc;
    if (p) {
        p->field54 = 0;
        p->field58 = 0;
    }
    return p;
}