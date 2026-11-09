// roc 2012-06 00a70200  unit: CXTPRibbonTab  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a70200
//
// 00a70200  8b8984000000         mov ecx, dword ptr [ecx + 0x84]
// 00a70206  e9f52a0000           jmp 0xa72d00
// auto-matched from its assembly shape

struct P_func_00a70200 { void g(); };
struct S_func_00a70200 {
    char pad[132];
    P_func_00a70200* m_p;
    void f();
};
void S_func_00a70200::f()
{
    m_p->g();
}
