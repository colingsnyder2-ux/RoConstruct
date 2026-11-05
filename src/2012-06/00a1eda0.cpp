// roc 2012-06 00a1eda0  unit: CXTPRibbonBar  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a1eda0
//
// 00a1eda0  8b8148020000         mov eax, dword ptr [ecx + 0x248]
// 00a1eda6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a1eda0 {
    char pad0[584];
    int m_x;
    int f();
};
int S_func_00a1eda0::f()
{
    return m_x;
}
