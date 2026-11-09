// roc 2012-06 007891c0  unit: RBX::N$E?sDoubleConstrainedValue::V?$ConstrainedValue::?$FactoryProduct::Creator  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007891c0
//
// 007891c0  8b8984000000         mov ecx, dword ptr [ecx + 0x84]
// 007891c6  e945eb1e00           jmp 0x977d10
// auto-matched from its assembly shape

struct P_func_007891c0 { void g(); };
struct S_func_007891c0 {
    char pad[132];
    P_func_007891c0* m_p;
    void f();
};
void S_func_007891c0::f()
{
    m_p->g();
}
