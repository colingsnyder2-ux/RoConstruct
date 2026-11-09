// roc 2012-06 00b159e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b159e0
//
// 00b159e0  b950a7e200           mov ecx, 0xe2a750
// 00b159e5  e906c5a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b159e0 { void m(); };
extern T_func_00b159e0 G1_func_00b159e0;
void func_00b159e0()
{
    G1_func_00b159e0.m();
}
