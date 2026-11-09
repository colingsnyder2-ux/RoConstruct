// roc 2012-06 00b134b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b134b0
//
// 00b134b0  b9f008e200           mov ecx, 0xe208f0
// 00b134b5  e936eaa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b134b0 { void m(); };
extern T_func_00b134b0 G1_func_00b134b0;
void func_00b134b0()
{
    G1_func_00b134b0.m();
}
