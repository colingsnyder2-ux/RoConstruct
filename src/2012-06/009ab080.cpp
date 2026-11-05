// roc 2012-06 009ab080  unit: CXTPReportControl  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ab080
//
// 009ab080  8b8900010000         mov ecx, dword ptr [ecx + 0x100]
// 009ab086  e955910700           jmp 0xa241e0
// auto-matched from its assembly shape

struct P_func_009ab080 { void g(); };
struct S_func_009ab080 {
    char pad[256];
    P_func_009ab080* m_p;
    void f();
};
void S_func_009ab080::f()
{
    m_p->g();
}
