// roc 2012-06 00a33430  unit: CXTPDockingPaneAutoHideWnd  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a33430
//
// 00a33430  8b8190000000         mov eax, dword ptr [ecx + 0x90]
// 00a33436  8b4014               mov eax, dword ptr [eax + 0x14]
// 00a33439  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00a33430 {
    char pad[20];
    int m_x;
};
struct S_func_00a33430 {
    char pad[144];
    I_func_00a33430* m_p;
    int f();
};
int S_func_00a33430::f()
{
    return m_p->m_x;
}
