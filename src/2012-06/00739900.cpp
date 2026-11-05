// roc 2012-06 00739900  unit: RBX::BasePlayerGui  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00739900
//
// 00739900  8b8988000000         mov ecx, dword ptr [ecx + 0x88]
// 00739906  e9e5cbf3ff           jmp 0x6764f0
// auto-matched from its assembly shape

struct P_func_00739900 { void g(); };
struct S_func_00739900 {
    char pad[136];
    P_func_00739900* m_p;
    void f();
};
void S_func_00739900::f()
{
    m_p->g();
}
