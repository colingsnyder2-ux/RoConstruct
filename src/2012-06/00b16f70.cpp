// roc 2012-06 00b16f70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16f70
//
// 00b16f70  b918f1e200           mov ecx, 0xe2f118
// 00b16f75  e976afa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16f70 { void m(); };
extern T_func_00b16f70 G1_func_00b16f70;
void func_00b16f70()
{
    G1_func_00b16f70.m();
}
