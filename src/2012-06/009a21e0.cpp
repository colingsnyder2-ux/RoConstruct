// roc 2012-06 009a21e0  unit: CXTPCommandBars  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a21e0
//
// 009a21e0  8b89bc000000         mov ecx, dword ptr [ecx + 0xbc]
// 009a21e6  e92547feff           jmp 0x986910
// auto-matched from its assembly shape

struct P_func_009a21e0 { void g(); };
struct S_func_009a21e0 {
    char pad[188];
    P_func_009a21e0* m_p;
    void f();
};
void S_func_009a21e0::f()
{
    m_p->g();
}
