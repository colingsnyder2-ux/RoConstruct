// roc 2012-06 009bd2c0  unit: CXTPReportSelectedRows  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009bd2c0
//
// 009bd2c0  8b8168010000         mov eax, dword ptr [ecx + 0x168]
// 009bd2c6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009bd2c0 {
    char pad0[360];
    int m_x;
    int f();
};
int S_func_009bd2c0::f()
{
    return m_x;
}
