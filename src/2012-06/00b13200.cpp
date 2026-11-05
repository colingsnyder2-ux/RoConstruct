// roc 2012-06 00b13200  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13200
//
// 00b13200  b98013e200           mov ecx, 0xe21380
// 00b13205  e9e6eca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13200 { void m(); };
extern T_func_00b13200 G1_func_00b13200;
void func_00b13200()
{
    G1_func_00b13200.m();
}
