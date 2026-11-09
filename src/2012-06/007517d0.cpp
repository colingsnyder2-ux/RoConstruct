// roc 2012-06 007517d0  unit: RBX::PartInstance  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007517d0
//
// 007517d0  8b8998010000         mov ecx, dword ptr [ecx + 0x198]
// 007517d6  e9657a0600           jmp 0x7b9240
// auto-matched from its assembly shape

struct P_func_007517d0 { void g(); };
struct S_func_007517d0 {
    char pad[408];
    P_func_007517d0* m_p;
    void f();
};
void S_func_007517d0::f()
{
    m_p->g();
}
