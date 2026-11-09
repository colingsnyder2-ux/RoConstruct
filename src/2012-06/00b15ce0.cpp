// roc 2012-06 00b15ce0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15ce0
//
// 00b15ce0  b950b4e200           mov ecx, 0xe2b450
// 00b15ce5  e906c2a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15ce0 { void m(); };
extern T_func_00b15ce0 G1_func_00b15ce0;
void func_00b15ce0()
{
    G1_func_00b15ce0.m();
}
