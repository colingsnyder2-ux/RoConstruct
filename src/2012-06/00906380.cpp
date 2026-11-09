// roc 2012-06 00906380  unit: RBX::PrismPoly  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00906380
//
// 00906380  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00906383  e9888f0400           jmp 0x94f310
// auto-matched from its assembly shape

struct P_func_00906380 { void g(); };
struct S_func_00906380 {
    char pad[20];
    P_func_00906380* m_p;
    void f();
};
void S_func_00906380::f()
{
    m_p->g();
}
