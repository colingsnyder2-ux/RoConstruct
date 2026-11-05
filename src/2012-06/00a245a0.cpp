// roc 2012-06 00a245a0  unit: CXTPReportPaintManager  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a245a0
//
// 00a245a0  8b8164020000         mov eax, dword ptr [ecx + 0x264]
// 00a245a6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00a245a0 {
    char pad0[612];
    int m_x;
    int f();
};
int S_func_00a245a0::f()
{
    return m_x;
}
