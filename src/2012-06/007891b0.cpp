// roc 2012-06 007891b0  unit: RBX::N$E?sDoubleConstrainedValue::V?$ConstrainedValue::?$FactoryProduct::Creator  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007891b0
//
// 007891b0  8b8984000000         mov ecx, dword ptr [ecx + 0x84]
// 007891b6  e9c5ea1e00           jmp 0x977c80
// auto-matched from its assembly shape

struct P_func_007891b0 { void g(); };
struct S_func_007891b0 {
    char pad[132];
    P_func_007891b0* m_p;
    void f();
};
void S_func_007891b0::f()
{
    m_p->g();
}
