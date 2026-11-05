// roc 2012-06 00a45ac0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a45ac0
//
// 00a45ac0  8b811c010000         mov eax, dword ptr [ecx + 0x11c]
// 00a45ac6  8b8020010000         mov eax, dword ptr [eax + 0x120]
// 00a45acc  c3                   ret 
// auto-matched from its assembly shape

struct I_func_00a45ac0 {
    char pad[288];
    int m_x;
};
struct S_func_00a45ac0 {
    char pad[284];
    I_func_00a45ac0* m_p;
    int f();
};
int S_func_00a45ac0::f()
{
    return m_p->m_x;
}
