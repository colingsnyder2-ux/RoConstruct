// from server: 89% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0044fc50  unit: CRobloxDoc  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044fc50
//
// 0044fc50  6aff                 push -1
// 0044fc52  684b177c00           push 0x7c174b
// 0044fc57  64a100000000         mov eax, dword ptr fs:[0]
// 0044fc5d  50                   push eax
// 0044fc5e  64892500000000       mov dword ptr fs:[0], esp
// 0044fc65  81ec30010000         sub esp, 0x130
// 0044fc6b  8b8194000000         mov eax, dword ptr [ecx + 0x94]
// 0044fc71  6a00                 push 0
// 0044fc73  50                   push eax
// 0044fc74  8d4c2408             lea ecx, [esp + 8]
// 0044fc78  e883f8ffff           call 0x44f500
// 0044fc7d  8d0c24               lea ecx, [esp]
// 0044fc80  c784243801000000000000 mov dword ptr [esp + 0x138], 0
// 0044fc8b  e8be0b2500           call 0x6a084e
// 0044fc90  8d0c24               lea ecx, [esp]
// 0044fc93  c7842438010000ffffffff mov dword ptr [esp + 0x138], 0xffffffff
// 0044fc9e  e87d010100           call 0x45fe20
// 0044fca3  8b8c2430010000       mov ecx, dword ptr [esp + 0x130]
// 0044fcaa  64890d00000000       mov dword ptr fs:[0], ecx
// 0044fcb1  81c43c010000         add esp, 0x13c
// 0044fcb7  c3                   ret 

struct Dialog
{
    char storage[0x12C];
    Dialog(void *, int);
    virtual ~Dialog();
    int DoModal();
};

struct CRobloxDoc
{
    char padding[0x94];
    void *context;
    void func_0044fc50();
};

void CRobloxDoc::func_0044fc50()
{
    Dialog dialog(context, 0);
    dialog.DoModal();
}
