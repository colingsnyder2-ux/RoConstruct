// roc 2012-06 00b13750  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13750
//
// 00b13750  b9b011e200           mov ecx, 0xe211b0
// 00b13755  e996e7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13750 { void m(); };
extern T_func_00b13750 G1_func_00b13750;
void func_00b13750()
{
    G1_func_00b13750.m();
}
