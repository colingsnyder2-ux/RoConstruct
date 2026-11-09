// roc 2012-06 009d7f00  unit: CXTPPropExchangeArchive  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d7f00
//
// 009d7f00  8b4944               mov ecx, dword ptr [ecx + 0x44]
// 009d7f03  e970adfaff           jmp 0x982c78
// auto-matched from its assembly shape

struct P_func_009d7f00 { void g(); };
struct S_func_009d7f00 {
    char pad[68];
    P_func_009d7f00* m_p;
    void f();
};
void S_func_009d7f00::f()
{
    m_p->g();
}
