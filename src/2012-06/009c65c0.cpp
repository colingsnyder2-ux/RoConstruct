// roc 2012-06 009c65c0  unit: CXTPControls  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c65c0
//
// 009c65c0  8b89e4000000         mov ecx, dword ptr [ecx + 0xe4]
// 009c65c6  e9f57afdff           jmp 0x99e0c0
// auto-matched from its assembly shape

struct P_func_009c65c0 { void g(); };
struct S_func_009c65c0 {
    char pad[228];
    P_func_009c65c0* m_p;
    void f();
};
void S_func_009c65c0::f()
{
    m_p->g();
}
