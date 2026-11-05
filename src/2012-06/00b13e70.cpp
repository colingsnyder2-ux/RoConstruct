// roc 2012-06 00b13e70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13e70
//
// 00b13e70  b97826e200           mov ecx, 0xe22678
// 00b13e75  e96626a4ff           jmp 0x5564e0
// auto-matched from its assembly shape

struct T_func_00b13e70 { void m(); };
extern T_func_00b13e70 G1_func_00b13e70;
void func_00b13e70()
{
    G1_func_00b13e70.m();
}
