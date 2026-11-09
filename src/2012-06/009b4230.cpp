// roc 2012-06 009b4230  unit: CXTPReportControl  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b4230
//
// 009b4230  8b4124               mov eax, dword ptr [ecx + 0x24]
// 009b4233  8b8000010000         mov eax, dword ptr [eax + 0x100]
// 009b4239  c3                   ret 
// auto-matched from its assembly shape

struct I_func_009b4230 {
    char pad[256];
    int m_x;
};
struct S_func_009b4230 {
    char pad[36];
    I_func_009b4230* m_p;
    int f();
};
int S_func_009b4230::f()
{
    return m_p->m_x;
}
