// roc 2012-06 00b16ea0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16ea0
//
// 00b16ea0  b950f5e200           mov ecx, 0xe2f550
// 00b16ea5  e9968bd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b16ea0 { void m(); };
extern T_func_00b16ea0 G1_func_00b16ea0;
void func_00b16ea0()
{
    G1_func_00b16ea0.m();
}
