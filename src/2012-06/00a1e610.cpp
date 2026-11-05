// roc 2012-06 00a1e610  unit: CXTPRibbonBar  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1e610
//
// 00a1e610  8b8144020000         mov eax, dword ptr [ecx + 0x244]
// 00a1e616  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a1e610 {
    char pad0[580];
    int m_x;
    int f();
};
int S_func_00a1e610::f()
{
    return m_x;
}
