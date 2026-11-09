// roc 2012-06 00b139f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b139f0
//
// 00b139f0  b95824e200           mov ecx, 0xe22458
// 00b139f5  e946c0d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b139f0 { void m(); };
extern T_func_00b139f0 G1_func_00b139f0;
void func_00b139f0()
{
    G1_func_00b139f0.m();
}
