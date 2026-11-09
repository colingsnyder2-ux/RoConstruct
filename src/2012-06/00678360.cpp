// roc 2012-06 00678360  unit: DummyArbiter  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00678360
//
// 00678360  d98188000000         fld dword ptr [ecx + 0x88]
// 00678366  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00678360 {
    char pad[136];
    float m_x;
    float f();
};
float S_func_00678360::f()
{
    return m_x;
}
