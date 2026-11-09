// roc 2012-06 00b15c90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15c90
//
// 00b15c90  b948b3e200           mov ecx, 0xe2b348
// 00b15c95  e956c2a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15c90 { void m(); };
extern T_func_00b15c90 G1_func_00b15c90;
void func_00b15c90()
{
    G1_func_00b15c90.m();
}
