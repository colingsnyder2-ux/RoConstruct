// roc 2012-06 00a35260  unit: CXTPDockingPaneAutoHidePanel  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a35260
//
// 00a35260  8b442404             mov eax, dword ptr [esp + 4]
// 00a35264  894110               mov dword ptr [ecx + 0x10], eax
// 00a35267  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00a35260 {
    char pad0[16];
    int m_x;
    void f(int a1);
};
void S_func_00a35260::f(int a1)
{
    m_x = (int)a1;
}
