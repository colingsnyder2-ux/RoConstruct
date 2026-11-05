// roc 2012-06 009ab070  unit: CXTPReportControl  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ab070
//
// 009ab070  8b8900010000         mov ecx, dword ptr [ecx + 0x100]
// 009ab076  e915910700           jmp 0xa24190
// auto-matched from its assembly shape

struct P_func_009ab070 { void g(); };
struct S_func_009ab070 {
    char pad[256];
    P_func_009ab070* m_p;
    void f();
};
void S_func_009ab070::f()
{
    m_p->g();
}
