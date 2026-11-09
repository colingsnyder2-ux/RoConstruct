// roc 2012-06 00b13c30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13c30
//
// 00b13c30  b90823e200           mov ecx, 0xe22308
// 00b13c35  e9b6e2a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13c30 { void m(); };
extern T_func_00b13c30 G1_func_00b13c30;
void func_00b13c30()
{
    G1_func_00b13c30.m();
}
