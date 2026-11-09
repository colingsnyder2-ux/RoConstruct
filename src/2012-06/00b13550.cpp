// roc 2012-06 00b13550  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13550
//
// 00b13550  b9f414e200           mov ecx, 0xe214f4
// 00b13555  e9663ca1ff           jmp 0x5271c0
// auto-matched from its assembly shape

struct T_func_00b13550 { void m(); };
extern T_func_00b13550 G1_func_00b13550;
void func_00b13550()
{
    G1_func_00b13550.m();
}
