// from server: 100% by Yeetserama
// roc 2007-08 004608a0  unit: CScriptDoc  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004608a0
//
// 004608a0  6aff                 push -1
// 004608a2  68fad87300           push 0x73d8fa
// 004608a7  64a100000000         mov eax, dword ptr fs:[0]
// 004608ad  50                   push eax
// 004608ae  51                   push ecx
// 004608af  56                   push esi
// 004608b0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004608b5  33c4                 xor eax, esp
// 004608b7  50                   push eax
// 004608b8  8d44240c             lea eax, [esp + 0xc]
// 004608bc  64a300000000         mov dword ptr fs:[0], eax
// 004608c2  6a5c                 push 0x5c
// 004608c4  e82df61c00           call 0x62fef6
// 004608c9  8bf0                 mov esi, eax
// 004608cb  83c404               add esp, 4
// 004608ce  89742408             mov dword ptr [esp + 8], esi
// 004608d2  85f6                 test esi, esi
// 004608d4  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004608dc  742e                 je 0x46090c
// 004608de  8bce                 mov ecx, esi
// 004608e0  e877f61c00           call 0x62ff5c
// 004608e5  c706a44a7900         mov dword ptr [esi], 0x794aa4
// 004608eb  c7465400000000       mov dword ptr [esi + 0x54], 0
// 004608f2  c7465800000000       mov dword ptr [esi + 0x58], 0
// 004608f9  8bc6                 mov eax, esi
// 004608fb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004608ff  64890d00000000       mov dword ptr fs:[0], ecx
// 00460906  59                   pop ecx
// 00460907  5e                   pop esi
// 00460908  83c410               add esp, 0x10
// 0046090b  c3                   ret 
// 0046090c  33c0                 xor eax, eax
// 0046090e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00460912  64890d00000000       mov dword ptr fs:[0], ecx
// 00460919  59                   pop ecx
// 0046091a  5e                   pop esi
// 0046091b  83c410               add esp, 0x10
// 0046091e  c3                   ret 
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