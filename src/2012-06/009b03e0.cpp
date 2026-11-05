// roc 2012-06 009b03e0  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b03e0
//
// 009b03e0  8b09                 mov ecx, dword ptr [ecx]
// 009b03e2  e909f2ffff           jmp 0x9af5f0
// auto-matched from its assembly shape

struct P_func_009b03e0 { void g(); };
struct S_func_009b03e0 {
    P_func_009b03e0* m_p;
    void f();
};
void S_func_009b03e0::f()
{
    m_p->g();
}
