// roc 2012-06 00a70210  unit: CXTPRibbonTab  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a70210
//
// 00a70210  8b8188000000         mov eax, dword ptr [ecx + 0x88]
// 00a70216  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a70210 {
    char pad0[136];
    int m_x;
    int f();
};
int S_func_00a70210::f()
{
    return m_x;
}
