// roc 2012-06 00b16030  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16030
//
// 00b16030  b9d0c1e200           mov ecx, 0xe2c1d0
// 00b16035  e9b6bea7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16030 { void m(); };
extern T_func_00b16030 G1_func_00b16030;
void func_00b16030()
{
    G1_func_00b16030.m();
}
