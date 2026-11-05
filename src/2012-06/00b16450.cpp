// roc 2012-06 00b16450  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16450
//
// 00b16450  b970d8e200           mov ecx, 0xe2d870
// 00b16455  e996baa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16450 { void m(); };
extern T_func_00b16450 G1_func_00b16450;
void func_00b16450()
{
    G1_func_00b16450.m();
}
