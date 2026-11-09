// roc 2012-06 007398f0  unit: RBX::BasePlayerGui  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007398f0
//
// 007398f0  8b8988000000         mov ecx, dword ptr [ecx + 0x88]
// 007398f6  e915cdf3ff           jmp 0x676610
// auto-matched from its assembly shape

struct P_func_007398f0 { void g(); };
struct S_func_007398f0 {
    char pad[136];
    P_func_007398f0* m_p;
    void f();
};
void S_func_007398f0::f()
{
    m_p->g();
}
