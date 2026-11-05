// roc 2012-06 008119a0  unit: RBX::Motor6D  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008119a0
//
// 008119a0  8b89a8000000         mov ecx, dword ptr [ecx + 0xa8]
// 008119a6  e9656dd4ff           jmp 0x558710
// auto-matched from its assembly shape

struct P_func_008119a0 { void g(); };
struct S_func_008119a0 {
    char pad[168];
    P_func_008119a0* m_p;
    void f();
};
void S_func_008119a0::f()
{
    m_p->g();
}
