// roc 2012-06 00b15930  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15930
//
// 00b15930  b9e0a2e200           mov ecx, 0xe2a2e0
// 00b15935  e9b6c5a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15930 { void m(); };
extern T_func_00b15930 G1_func_00b15930;
void func_00b15930()
{
    G1_func_00b15930.m();
}
