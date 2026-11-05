// roc 2012-06 00b170b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b170b0
//
// 00b170b0  b92cf4e200           mov ecx, 0xe2f42c
// 00b170b5  e936aea7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b170b0 { void m(); };
extern T_func_00b170b0 G1_func_00b170b0;
void func_00b170b0()
{
    G1_func_00b170b0.m();
}
