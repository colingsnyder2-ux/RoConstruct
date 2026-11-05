// roc 2012-06 00a34460  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a34460
//
// 00a34460  8b442404             mov eax, dword ptr [esp + 4]
// 00a34464  894118               mov dword ptr [ecx + 0x18], eax
// 00a34467  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00a34460 {
    char pad0[24];
    int m_x;
    void f(int a1);
};
void S_func_00a34460::f(int a1)
{
    m_x = (int)a1;
}
