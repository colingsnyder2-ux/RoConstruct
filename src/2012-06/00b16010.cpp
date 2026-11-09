// roc 2012-06 00b16010  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16010
//
// 00b16010  b988c3e200           mov ecx, 0xe2c388
// 00b16015  e9d6bea7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16010 { void m(); };
extern T_func_00b16010 G1_func_00b16010;
void func_00b16010()
{
    G1_func_00b16010.m();
}
