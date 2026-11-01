// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0042e610  unit: CMainFrame  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042e610
//
// 0042e610  53                   push ebx
// 0042e611  55                   push ebp
// 0042e612  56                   push esi
// 0042e613  8bf1                 mov esi, ecx
// 0042e615  57                   push edi
// 0042e616  8dbe38010000         lea edi, [esi + 0x138]
// 0042e61c  68c1000000           push 0xc1
// 0042e621  8bcf                 mov ecx, edi
// 0042e623  e8f8722b00           call 0x6e5920
// 0042e628  85c0                 test eax, eax
// 0042e62a  0f94c3               sete bl
// 0042e62d  6a01                 push 1
// 0042e62f  83ec10               sub esp, 0x10
// 0042e632  8bc4                 mov eax, esp
// 0042e634  33c9                 xor ecx, ecx
// 0042e636  8908                 mov dword ptr [eax], ecx
// 0042e638  33d2                 xor edx, edx
// 0042e63a  895004               mov dword ptr [eax + 4], edx
// 0042e63d  bdfa000000           mov ebp, 0xfa
// 0042e642  b92c010000           mov ecx, 0x12c
// 0042e647  896808               mov dword ptr [eax + 8], ebp
// 0042e64a  89480c               mov dword ptr [eax + 0xc], ecx
// 0042e64d  68c1000000           push 0xc1
// 0042e652  8bce                 mov ecx, esi
// 0042e654  e817ffffff           call 0x42e570
// 0042e659  84db                 test bl, bl
// 0042e65b  7443                 je 0x42e6a0
// 0042e65d  68c2000000           push 0xc2
// 0042e662  8bcf                 mov ecx, edi
// 0042e664  e8b7722b00           call 0x6e5920
// 0042e669  85c0                 test eax, eax
// 0042e66b  7433                 je 0x42e6a0
// 0042e66d  68c1000000           push 0xc1
// 0042e672  8bcf                 mov ecx, edi
// 0042e674  8d7020               lea esi, [eax + 0x20]
// 0042e677  e8a4722b00           call 0x6e5920
// 0042e67c  85c0                 test eax, eax
// 0042e67e  7413                 je 0x42e693
// 0042e680  56                   push esi
// 0042e681  83c020               add eax, 0x20
// 0042e684  6a03                 push 3
// 0042e686  50                   push eax
// 0042e687  8bcf                 mov ecx, edi
// 0042e689  e892882b00           call 0x6e6f20
// 0042e68e  5f                   pop edi
// 0042e68f  5e                   pop esi
// 0042e690  5d                   pop ebp
// 0042e691  5b                   pop ebx
// 0042e692  c3                   ret 
// 0042e693  56                   push esi
// 0042e694  33c0                 xor eax, eax
// 0042e696  6a03                 push 3
// 0042e698  50                   push eax
// 0042e699  8bcf                 mov ecx, edi
// 0042e69b  e880882b00           call 0x6e6f20
// 0042e6a0  5f                   pop edi
// 0042e6a1  5e                   pop esi
// 0042e6a2  5d                   pop ebp
// 0042e6a3  5b                   pop ebx
// 0042e6a4  c3                   ret 

struct Rect
{
    int left, top, right, bottom;
    Rect(int l, int t, int r, int b)
        : left(l), top(t), right(r), bottom(b) {}
};

struct PaneBase
{
    int value;
};

struct Pane
{
    char padding[0x20];
    PaneBase base;
};

struct PaneManager
{
    Pane* FindPane(int id);
    void DockPane(PaneBase* pane, int direction, PaneBase* relative);
};

struct CMainFrame
{
    char padding[0x13c];
    PaneManager manager;

    Pane* FindPane(int id, Rect rect, bool show);
    void f();
};

void CMainFrame::f()
{
    bool missing = manager.FindPane(0xc1) == 0;
    FindPane(0xc1, Rect(0, 0, 250, 300), true);

    if (missing)
    {
        Pane* relative = manager.FindPane(0xc2);
        if (relative)
        {
            PaneBase* base = &relative->base;
            Pane* pane = manager.FindPane(0xc1);
            manager.DockPane(pane ? &pane->base : 0, 3, base);
        }
    }
}
