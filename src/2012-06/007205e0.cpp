// roc 2012-06 007205e0  unit: RBX::VMouseCommand::?$sp_counted_impl_p  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007205e0
//
// 007205e0  8b8970010000         mov ecx, dword ptr [ecx + 0x170]
// 007205e6  e955071000           jmp 0x820d40
// auto-matched from its assembly shape

struct P_func_007205e0 { void g(); };
struct S_func_007205e0 {
    char pad[368];
    P_func_007205e0* m_p;
    void f();
};
void S_func_007205e0::f()
{
    m_p->g();
}
