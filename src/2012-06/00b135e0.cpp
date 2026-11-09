// roc 2012-06 00b135e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b135e0
//
// 00b135e0  b9f013e200           mov ecx, 0xe213f0
// 00b135e5  e986dbb6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b135e0 { void m(); };
extern T_func_00b135e0 G1_func_00b135e0;
void func_00b135e0()
{
    G1_func_00b135e0.m();
}
