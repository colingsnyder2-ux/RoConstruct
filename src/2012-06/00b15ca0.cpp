// roc 2012-06 00b15ca0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15ca0
//
// 00b15ca0  b988b3e200           mov ecx, 0xe2b388
// 00b15ca5  e946c2a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15ca0 { void m(); };
extern T_func_00b15ca0 G1_func_00b15ca0;
void func_00b15ca0()
{
    G1_func_00b15ca0.m();
}
