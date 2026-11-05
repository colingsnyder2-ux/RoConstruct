// roc 2012-06 00b13a70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13a70
//
// 00b13a70  b97021e200           mov ecx, 0xe22170
// 00b13a75  e976e4a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13a70 { void m(); };
extern T_func_00b13a70 G1_func_00b13a70;
void func_00b13a70()
{
    G1_func_00b13a70.m();
}
