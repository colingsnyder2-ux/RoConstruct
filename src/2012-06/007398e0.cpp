// roc 2012-06 007398e0  unit: RBX::BasePlayerGui  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007398e0
//
// 007398e0  8b8988000000         mov ecx, dword ptr [ecx + 0x88]
// 007398e6  e995ccf3ff           jmp 0x676580
// auto-matched from its assembly shape

struct P_func_007398e0 { void g(); };
struct S_func_007398e0 {
    char pad[136];
    P_func_007398e0* m_p;
    void f();
};
void S_func_007398e0::f()
{
    m_p->g();
}
