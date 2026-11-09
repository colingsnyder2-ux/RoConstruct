// from server: 89% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0044fcc0  unit: CRobloxDoc  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044fcc0
//
// 0044fcc0  6aff                 push -1
// 0044fcc2  684b177c00           push 0x7c174b
// 0044fcc7  64a100000000         mov eax, dword ptr fs:[0]
// 0044fccd  50                   push eax
// 0044fcce  64892500000000       mov dword ptr fs:[0], esp
// 0044fcd5  81ec30010000         sub esp, 0x130
// 0044fcdb  8b8194000000         mov eax, dword ptr [ecx + 0x94]
// 0044fce1  6a00                 push 0
// 0044fce3  50                   push eax
// 0044fce4  8d4c2408             lea ecx, [esp + 8]
// 0044fce8  e873f9ffff           call 0x44f660
// 0044fced  8d0c24               lea ecx, [esp]
// 0044fcf0  c784243801000000000000 mov dword ptr [esp + 0x138], 0
// 0044fcfb  e84e0b2500           call 0x6a084e
// 0044fd00  8d0c24               lea ecx, [esp]
// 0044fd03  c7842438010000ffffffff mov dword ptr [esp + 0x138], 0xffffffff
// 0044fd0e  e80d010100           call 0x45fe20
// 0044fd13  8b8c2430010000       mov ecx, dword ptr [esp + 0x130]
// 0044fd1a  64890d00000000       mov dword ptr fs:[0], ecx
// 0044fd21  81c43c010000         add esp, 0x13c
// 0044fd27  c3                   ret 

struct Dialog
{
    char storage[0x130];

    Dialog(void* owner, int flags);
    ~Dialog();
    int run();
};

struct CRobloxDoc
{
    char padding[0x94];
    void* owner;

    void func_0044fcc0();
};

void CRobloxDoc::func_0044fcc0()
{
    Dialog dialog(owner, 0);
    dialog.run();
}
