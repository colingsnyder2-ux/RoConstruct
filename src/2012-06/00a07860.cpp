// roc 2012-06 00a07860  unit: CXTPRibbonTheme  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a07860
//
// 00a07860  8b81c8050000         mov eax, dword ptr [ecx + 0x5c8]
// 00a07866  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a07860 {
    char pad0[1480];
    int m_x;
    int f();
};
int S_func_00a07860::f()
{
    return m_x;
}
