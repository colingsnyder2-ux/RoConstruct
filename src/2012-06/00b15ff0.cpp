// roc 2012-06 00b15ff0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15ff0
//
// 00b15ff0  b950c4e200           mov ecx, 0xe2c450
// 00b15ff5  e9f6bea7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15ff0 { void m(); };
extern T_func_00b15ff0 G1_func_00b15ff0;
void func_00b15ff0()
{
    G1_func_00b15ff0.m();
}
