// roc 2012-06 00b15b30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15b30
//
// 00b15b30  b940b1e200           mov ecx, 0xe2b140
// 00b15b35  e9b6c3a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15b30 { void m(); };
extern T_func_00b15b30 G1_func_00b15b30;
void func_00b15b30()
{
    G1_func_00b15b30.m();
}
