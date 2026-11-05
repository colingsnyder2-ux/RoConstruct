// roc 2012-06 00b16f80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16f80
//
// 00b16f80  b988f3e200           mov ecx, 0xe2f388
// 00b16f85  e966afa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16f80 { void m(); };
extern T_func_00b16f80 G1_func_00b16f80;
void func_00b16f80()
{
    G1_func_00b16f80.m();
}
