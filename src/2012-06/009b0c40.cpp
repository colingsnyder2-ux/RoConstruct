// roc 2012-06 009b0c40  unit: CXTPReportControl  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b0c40
//
// 009b0c40  8b8184020000         mov eax, dword ptr [ecx + 0x284]
// 009b0c46  c3                   ret 
// auto-matched from its assembly shape

struct S_func_009b0c40 {
    char pad0[644];
    int m_x;
    int f();
};
int S_func_009b0c40::f()
{
    return m_x;
}
