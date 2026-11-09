// roc 2012-06 007e69e0  unit: CXTPReportControl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e69e0
//
// 007e69e0  8b81bc010000         mov eax, dword ptr [ecx + 0x1bc]
// 007e69e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_007e69e0 {
    char pad0[444];
    int m_x;
    int f();
};
int S_func_007e69e0::f()
{
    return m_x;
}
