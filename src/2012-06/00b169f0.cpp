// roc 2012-06 00b169f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b169f0
//
// 00b169f0  b950ece200           mov ecx, 0xe2ec50
// 00b169f5  e9f6b4a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b169f0 { void m(); };
extern T_func_00b169f0 G1_func_00b169f0;
void func_00b169f0()
{
    G1_func_00b169f0.m();
}
