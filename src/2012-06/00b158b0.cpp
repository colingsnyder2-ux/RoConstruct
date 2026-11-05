// roc 2012-06 00b158b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b158b0
//
// 00b158b0  b998a3e200           mov ecx, 0xe2a398
// 00b158b5  e936c6a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b158b0 { void m(); };
extern T_func_00b158b0 G1_func_00b158b0;
void func_00b158b0()
{
    G1_func_00b158b0.m();
}
