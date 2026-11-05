// roc 2012-06 009bd2d0  unit: CXTPReportSelectedRows  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009bd2d0
//
// 009bd2d0  8b8168040000         mov eax, dword ptr [ecx + 0x468]
// 009bd2d6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009bd2d0 {
    char pad0[1128];
    int m_x;
    int f();
};
int S_func_009bd2d0::f()
{
    return m_x;
}
