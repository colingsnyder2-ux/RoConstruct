// roc 2012-06 0082e600  unit: RBX::BallBlockContact  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0082e600
//
// 0082e600  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 0082e603  e908ffffff           jmp 0x82e510
// auto-matched from its assembly shape

struct P_func_0082e600 { void g(); };
struct S_func_0082e600 {
    char pad[36];
    P_func_0082e600* m_p;
    void f();
};
void S_func_0082e600::f()
{
    m_p->g();
}
