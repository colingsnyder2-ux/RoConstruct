// roc 2012-06 009e65a0  unit: CSelectionCaption  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e65a0
//
// 009e65a0  8b4908               mov ecx, dword ptr [ecx + 8]
// 009e65a3  e944c5f9ff           jmp 0x982aec
// auto-matched from its assembly shape

struct P_func_009e65a0 { void g(); };
struct S_func_009e65a0 {
    char pad[8];
    P_func_009e65a0* m_p;
    void f();
};
void S_func_009e65a0::f()
{
    m_p->g();
}
