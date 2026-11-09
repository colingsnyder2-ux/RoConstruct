// roc 2012-06 00b13770  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13770
//
// 00b13770  b99c12e200           mov ecx, 0xe2129c
// 00b13775  e976e7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13770 { void m(); };
extern T_func_00b13770 G1_func_00b13770;
void func_00b13770()
{
    G1_func_00b13770.m();
}
