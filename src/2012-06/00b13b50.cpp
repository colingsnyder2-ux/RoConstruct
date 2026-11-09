// roc 2012-06 00b13b50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13b50
//
// 00b13b50  b9c41de200           mov ecx, 0xe21dc4
// 00b13b55  e996e3a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13b50 { void m(); };
extern T_func_00b13b50 G1_func_00b13b50;
void func_00b13b50()
{
    G1_func_00b13b50.m();
}
