// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0042e570  unit: CMainFrame  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042e570
//
// 0042e570  53                   push ebx
// 0042e571  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0042e575  56                   push esi
// 0042e576  57                   push edi
// 0042e577  8db938010000         lea edi, [ecx + 0x138]
// 0042e57d  53                   push ebx
// 0042e57e  8bcf                 mov ecx, edi
// 0042e580  e89b732b00           call 0x6e5920
// 0042e585  8bf0                 mov esi, eax
// 0042e587  85f6                 test esi, esi
// 0042e589  7530                 jne 0x42e5bb
// 0042e58b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042e58f  8b542418             mov edx, dword ptr [esp + 0x18]
// 0042e593  50                   push eax
// 0042e594  8b442428             mov eax, dword ptr [esp + 0x28]
// 0042e598  50                   push eax
// 0042e599  83ec10               sub esp, 0x10
// 0042e59c  8bc4                 mov eax, esp
// 0042e59e  8908                 mov dword ptr [eax], ecx
// 0042e5a0  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0042e5a4  895004               mov dword ptr [eax + 4], edx
// 0042e5a7  8b542438             mov edx, dword ptr [esp + 0x38]
// 0042e5ab  894808               mov dword ptr [eax + 8], ecx
// 0042e5ae  53                   push ebx
// 0042e5af  8bcf                 mov ecx, edi
// 0042e5b1  89500c               mov dword ptr [eax + 0xc], edx
// 0042e5b4  e8a7882b00           call 0x6e6e60
// 0042e5b9  8bf0                 mov esi, eax
// 0042e5bb  6a01                 push 1
// 0042e5bd  56                   push esi
// 0042e5be  8bcf                 mov ecx, edi
// 0042e5c0  e89b732b00           call 0x6e5960
// 0042e5c5  8b06                 mov eax, dword ptr [esi]
// 0042e5c7  8b5058               mov edx, dword ptr [eax + 0x58]
// 0042e5ca  8bce                 mov ecx, esi
// 0042e5cc  ffd2                 call edx
// 0042e5ce  5f                   pop edi
// 0042e5cf  5e                   pop esi
// 0042e5d0  5b                   pop ebx
// 0042e5d1  c21800               ret 0x18

struct Rect
{
    int left, top, right, bottom;
};

struct Pane;

struct PaneVTable
{
    void* slots[22];
    int (__thiscall* invoke)(Pane*);
};

struct Pane
{
    PaneVTable* vtable;
};

struct PaneManager
{
    Pane* FindPane(int id);
    Pane* CreatePane(int id, Rect rect, int direction, Pane* relative);
    void ShowPane(Pane* pane, int focus);
};

struct CMainFrame
{
    char padding[0x13c];
    PaneManager manager;

    int func_0042e570(int id, Rect rect, int direction);
};

int CMainFrame::func_0042e570(int id, Rect rect, int direction)
{
    Pane* pane = manager.FindPane(id);
    if (!pane)
        pane = manager.CreatePane(id, rect, direction, 0);

    manager.ShowPane(pane, 1);
    return pane->vtable->invoke(pane);
}
