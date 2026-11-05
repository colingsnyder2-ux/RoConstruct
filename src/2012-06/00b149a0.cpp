// roc 2012-06 00b149a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b149a0
//
// 00b149a0  b9cc56e200           mov ecx, 0xe256cc
// 00b149a5  e946d5a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b149a0 { void m(); };
extern T_func_00b149a0 G1_func_00b149a0;
void func_00b149a0()
{
    G1_func_00b149a0.m();
}
