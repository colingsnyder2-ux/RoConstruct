// roc 2012-06 00b143a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b143a0
//
// 00b143a0  b93042e200           mov ecx, 0xe24230
// 00b143a5  e9f6bca4ff           jmp 0x5600a0
// auto-matched from its assembly shape

struct T_func_00b143a0 { void m(); };
extern T_func_00b143a0 G1_func_00b143a0;
void func_00b143a0()
{
    G1_func_00b143a0.m();
}
