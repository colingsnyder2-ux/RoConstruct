// roc 2012-06 00b16230  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16230
//
// 00b16230  b950d6e200           mov ecx, 0xe2d650
// 00b16235  e9b6bca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16230 { void m(); };
extern T_func_00b16230 G1_func_00b16230;
void func_00b16230()
{
    G1_func_00b16230.m();
}
