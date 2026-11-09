// roc 2012-06 00a71bd0  unit: CXTPDialogBar  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a71bd0
//
// 00a71bd0  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 00a71bd3  e938e6ffff           jmp 0xa70210
// auto-matched from its assembly shape

struct P_func_00a71bd0 { void g(); };
struct S_func_00a71bd0 {
    char pad[52];
    P_func_00a71bd0* m_p;
    void f();
};
void S_func_00a71bd0::f()
{
    m_p->g();
}
