// roc 2012-06 009d7ef0  unit: CXTPPropExchangeArchive  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d7ef0
//
// 009d7ef0  8b4944               mov ecx, dword ptr [ecx + 0x44]
// 009d7ef3  e986adfaff           jmp 0x982c7e
// auto-matched from its assembly shape

struct P_func_009d7ef0 { void g(); };
struct S_func_009d7ef0 {
    char pad[68];
    P_func_009d7ef0* m_p;
    void f();
};
void S_func_009d7ef0::f()
{
    m_p->g();
}
