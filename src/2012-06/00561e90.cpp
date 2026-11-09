// roc 2012-06 00561e90  unit: RBX::VHint::?$FactoryProduct::Creator  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00561e90
//
// 00561e90  8b81dc0a0000         mov eax, dword ptr [ecx + 0xadc]
// 00561e96  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00561e90 {
    char pad0[2780];
    int m_x;
    int f();
};
int S_func_00561e90::f()
{
    return m_x;
}
