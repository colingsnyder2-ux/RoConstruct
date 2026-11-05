// roc 2012-06 00b13af0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13af0
//
// 00b13af0  b9d821e200           mov ecx, 0xe221d8
// 00b13af5  e946bfd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13af0 { void m(); };
extern T_func_00b13af0 G1_func_00b13af0;
void func_00b13af0()
{
    G1_func_00b13af0.m();
}
