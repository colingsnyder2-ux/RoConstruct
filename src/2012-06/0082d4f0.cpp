// roc 2012-06 0082d4f0  unit: RBX::BallBlockContact  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0082d4f0
//
// 0082d4f0  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 0082d4f3  e9e8f5ffff           jmp 0x82cae0
// auto-matched from its assembly shape

struct P_func_0082d4f0 { void g(); };
struct S_func_0082d4f0 {
    char pad[36];
    P_func_0082d4f0* m_p;
    void f();
};
void S_func_0082d4f0::f()
{
    m_p->g();
}
