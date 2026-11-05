// roc 2012-06 00561870  unit: RBX::VHint::?$FactoryProduct::Creator  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00561870
//
// 00561870  668b4102             mov ax, word ptr [ecx + 2]
// 00561874  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00561870 {
    char pad0[2];
    short m_x;
    short f();
};
short S_func_00561870::f()
{
    return m_x;
}
