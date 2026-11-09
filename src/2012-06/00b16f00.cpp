// roc 2012-06 00b16f00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16f00
//
// 00b16f00  b970f2e200           mov ecx, 0xe2f270
// 00b16f05  e9e6afa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16f00 { void m(); };
extern T_func_00b16f00 G1_func_00b16f00;
void func_00b16f00()
{
    G1_func_00b16f00.m();
}
