// from server: 100% by Yeetserama
// roc 2010-06 00471d00  unit: CScriptDoc  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00471d00
//
// 00471d00  6aff                 push -1
// 00471d02  68da209800           push 0x9820da
// 00471d07  64a100000000         mov eax, dword ptr fs:[0]
// 00471d0d  50                   push eax
// 00471d0e  64892500000000       mov dword ptr fs:[0], esp
// 00471d15  51                   push ecx
// 00471d16  56                   push esi
// 00471d17  6a5c                 push 0x5c
// 00471d19  e8825c3300           call 0x7a79a0
// 00471d1e  8bf0                 mov esi, eax
// 00471d20  83c404               add esp, 4
// 00471d23  89742404             mov dword ptr [esp + 4], esi
// 00471d27  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00471d2f  85f6                 test esi, esi
// 00471d31  742d                 je 0x471d60
// 00471d33  8bce                 mov ecx, esi
// 00471d35  e8605f3300           call 0x7a7c9a
// 00471d3a  c706a40ea100         mov dword ptr [esi], 0xa10ea4
// 00471d40  c7465400000000       mov dword ptr [esi + 0x54], 0
// 00471d47  c7465800000000       mov dword ptr [esi + 0x58], 0
// 00471d4e  8bc6                 mov eax, esi
// 00471d50  5e                   pop esi
// 00471d51  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00471d55  64890d00000000       mov dword ptr fs:[0], ecx
// 00471d5c  83c410               add esp, 0x10
// 00471d5f  c3                   ret 
// 00471d60  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00471d64  33c0                 xor eax, eax
// 00471d66  5e                   pop esi
// 00471d67  64890d00000000       mov dword ptr fs:[0], ecx
// 00471d6e  83c410               add esp, 0x10
// 00471d71  c3                   ret 
// copied from an identical function in another client (function ?Create@CScriptDoc@@SAPAU1@XZ)

// from server: 100% by king_originala
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