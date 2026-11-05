// roc 2012-06 0071f920  unit: CXTPRibbonControlTab  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071f920
//
// 0071f920  8b8114020000         mov eax, dword ptr [ecx + 0x214]
// 0071f926  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0071f920 {
    char pad0[532];
    int m_x;
    int f();
};
int S_func_0071f920::f()
{
    return m_x;
}
