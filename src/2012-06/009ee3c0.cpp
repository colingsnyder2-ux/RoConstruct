// roc 2012-06 009ee3c0  unit: CXTPPropertyGridView  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ee3c0
//
// 009ee3c0  8b89b0000000         mov ecx, dword ptr [ecx + 0xb0]
// 009ee3c6  e9e534ffff           jmp 0x9e18b0
// auto-matched from its assembly shape

struct P_func_009ee3c0 { void g(); };
struct S_func_009ee3c0 {
    char pad[176];
    P_func_009ee3c0* m_p;
    void f();
};
void S_func_009ee3c0::f()
{
    m_p->g();
}
